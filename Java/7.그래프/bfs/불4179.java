import java.io.*;
import java.util.*;

public class Main {
	
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static char[][] board = new char[1001][1001];
	static int[][] dist = new int[1001][1001];
	static boolean[][] fire_check = new boolean[1001][1001];
	static List<int[]> fire = new ArrayList<>();
	static int answer = Integer.MAX_VALUE;
	static int N,M;
	
	static void bfs(int sx, int sy) {
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) dist[i][j] = Integer.MAX_VALUE;
		}
		Queue<int[]> q = new LinkedList<>();
		Queue<int[]> fq = new LinkedList<>();
		q.offer(new int[] {sx,sy});
		dist[sx][sy] = 0;
		for(int i=0;i<fire.size();i++) {
			fq.offer(fire.get(i));
			fire_check[fire.get(i)[0]][fire.get(i)[1]] = true;
		}
		while(!q.isEmpty()) {
			int f_size = fq.size();
			for(int c=0;c<f_size;c++) {
				int[] now = fq.poll();
				int x = now[0]; int y = now[1];
				for(int i=0;i<4;i++) {
					int nx = x+dx[i];
					int ny = y+dy[i];
					if(nx>=0&&nx<N&&ny>=0&&ny<M&&fire_check[nx][ny]==false) {
						if(board[nx][ny]!='#') {
							fq.offer(new int[] {nx,ny});
							fire_check[nx][ny] = true;							
						}
					}
				}
			}
			int size = q.size();
			for(int c=0;c<size;c++) {
				int[] now = q.poll();
				int x = now[0]; int y = now[1];
				for(int i=0;i<4;i++) {
					int nx = x+dx[i];
					int ny = y+dy[i];
					if(nx>=0&&nx<N&&ny>=0&&ny<M&&dist[nx][ny]==Integer.MAX_VALUE) {
						if(board[nx][ny]!='#'&&fire_check[nx][ny]==false) {
							q.offer(new int[] {nx,ny});
							dist[nx][ny] = dist[x][y]+1;
						}
					}
				}
			}
		}
	}
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        N=n;M=m;
        int sx=-1,sy=-1,fx=-1,fy=-1;
        for(int i=0;i<n;i++) {
        	String temp = br.readLine();
        	for(int j=0;j<m;j++) {
        		board[i][j] = temp.charAt(j);
        		if(board[i][j]=='J') {
        			sx = i; sy = j;
        		} else if(board[i][j]=='F') {
        			fire.add(new int[] {i,j});
        		}
        	}
        }
        
        bfs(sx,sy);
        for(int j=0;j<m;j++) {
        	answer = Math.min(answer, dist[0][j]);
        	answer = Math.min(answer, dist[n-1][j]);
        }
        for(int i=0;i<n;i++) {
        	answer = Math.min(answer, dist[i][0]);
        	answer = Math.min(answer, dist[i][m-1]);
        }
        if(answer==Integer.MAX_VALUE) sb.append("IMPOSSIBLE");
        else sb.append(answer+1);
        System.out.println(sb);
	} 
}