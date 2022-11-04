import java.io.*;
import java.util.*;

public class Main {
	
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] board = new int[126][126];
	static int[][] dist = new int[126][126];
	static int N;
	
	static int bfs() {
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) dist[i][j] = Integer.MAX_VALUE;
		}
		PriorityQueue<int[]> q = new PriorityQueue<>(new Comparator<int[]>() {
			public int compare(int[] o1, int[] o2) {
				return o1[2]-o2[2];
			}
		});
		dist[0][0] = board[0][0];
		q.offer(new int[] {0,0,dist[0][0]});
		while(!q.isEmpty()) {
			int[] now = q.poll();
			int x = now[0]; int y = now[1]; int z = now[2];
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx>=0&&nx<N&&ny>=0&&ny<N) {
					if(dist[nx][ny]>dist[x][y]+board[nx][ny]) {
						dist[nx][ny] = dist[x][y]+board[nx][ny];
						q.offer(new int[] {nx,ny,dist[nx][ny]});
					}
				}
			}
		}
		return dist[N-1][N-1];
	}
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int t = 1;
        while(true) {
        	int n = Integer.parseInt(br.readLine());
        	N=n;
        	if(n==0) break;
        	for(int i=0;i<n;i++) {
        		st = new StringTokenizer(br.readLine());
        		for(int j=0;j<n;j++) {
        			board[i][j] = Integer.parseInt(st.nextToken());
        		}
        	}
        	sb.append("Problem "+t+": "+bfs()+"\n");
        	t+=1;
        }
        System.out.println(sb);
	}
}