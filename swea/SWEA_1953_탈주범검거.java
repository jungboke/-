import java.util.*;
import java.io.*;

public class Solution {
	
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] board = new int[51][51];
	static int[][] dist = new int[51][51];
	static int[][] dir = {{0,0,0,0},{1,1,1,1},{0,1,0,1},{1,0,1,0},{0,1,1,0},{0,0,1,1},{1,0,0,1},{1,1,0,0}};
	static int answer = 0;
	static int N,M;
	
	static int bfs(int sx, int sy, int l) {
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) dist[i][j] = -1;
		}
		Queue<int[]> q = new LinkedList<>();
		dist[sx][sy] = 0;
		q.offer(new int[] {sx,sy});
		while(!q.isEmpty()) {
			int[] now = q.poll();
			int x = now[0]; int y = now[1];
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx>=0&&nx<N&&ny>=0&&ny<M&&dist[nx][ny]==-1) {
					if(dir[board[x][y]][i]==1&&dir[board[nx][ny]][(i+2)%4]==1) {
						dist[nx][ny] = dist[x][y]+1;
						q.offer(new int[] {nx,ny});
					}
				}
			}
		}
		int result = 0;
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(dist[i][j]==-1) continue;
				if(dist[i][j]+1<=l) result+=1;
			}
		}
		return result;
	}
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("data/1953.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			N=n;M=m;
			int r = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int l = Integer.parseInt(st.nextToken());
			for(int i=0;i<n;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<m;j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			answer = bfs(r,c,l);
			sb.append("#"+(ot-t)+" "+answer+"\n");
		}
		System.out.println(sb);
	}
}
