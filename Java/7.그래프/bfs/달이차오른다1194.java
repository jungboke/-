import java.io.*;
import java.util.*;

public class Main {
	
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static char[][] board = new char[51][51];
	static int[][][] dist = new int[51][51][1<<6];
	static List<int[]> one = new ArrayList<>();
	static int N,M;
	
	static int bfs(int sx, int sy) {
		Queue<int[]> q = new LinkedList<>();
		q.offer(new int[] {sx,sy,0});
		dist[sx][sy][0] = 1;
		while(!q.isEmpty()) {
			int[] now = q.poll();
			int x = now[0]; int y = now[1]; int z = now[2];
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx>=0&&nx<N&&ny>=0&&ny<M) {
					if(board[nx][ny]>='a'&&board[nx][ny]<='f') {
						int nz = z|(1<<(board[nx][ny]-'a'));
						if(dist[nx][ny][nz]==0) {
							q.offer(new int[] {nx,ny,nz});
							dist[nx][ny][nz] = dist[x][y][z]+1;							
						}
					} else if(board[nx][ny]=='.'&&dist[nx][ny][z]==0) {
						q.offer(new int[] {nx,ny,z});
						dist[nx][ny][z] = dist[x][y][z]+1;
					} else if(board[nx][ny]>='A'&&board[nx][ny]<='F'&&dist[nx][ny][z]==0) {
						if((z&(1<<(board[nx][ny]-'A')))!=0) {
							q.offer(new int[] {nx,ny,z});
							dist[nx][ny][z] = dist[x][y][z]+1;
						}
					}
				}
			}
		}
		int mini = Integer.MAX_VALUE;
		for(int i=0;i<one.size();i++) {
			int x = one.get(i)[0]; int y = one.get(i)[1];
			for(int j=0;j<(1<<6);j++) {
				if(dist[x][y][j]==0) continue;
				mini = Math.min(mini, dist[x][y][j]);
			}
		}
		if(mini==Integer.MAX_VALUE) return -1;
		return mini-1;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		N=n;M=m;
		int sx=-1,sy=-1;
		for(int i=0;i<n;i++) {
			String temp = br.readLine();
			for(int j=0;j<m;j++) {
				board[i][j] = temp.charAt(j);
				if(board[i][j]=='0') {
					sx=i;sy=j;
					board[i][j] = '.';
				} else if(board[i][j]=='1') {
					one.add(new int[] {i,j});
					board[i][j] = '.';
				}
			}
		}
		System.out.println(sb.append(bfs(sx,sy)));
	}
}