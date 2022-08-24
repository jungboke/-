import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] board = new int[1001][1001];
	static int[][][] dist = new int[1001][1001][2];
	static int N,M;

	static int bfs() {
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				for(int k=0;k<2;k++) {
					dist[i][j][k] = -1;
				}
			}
		}
		Queue<int[]> q = new LinkedList<>();
		q.offer(new int[] {0,0,1});
		dist[0][0][1] = 1;
		while(!q.isEmpty()) {
			int[] now = q.poll();
			int x = now[0]; int y = now[1]; int z = now[2];
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx>=0&&nx<N&&ny>=0&&ny<M) {
					if(board[nx][ny]==1) {
						if(z==1&&dist[nx][ny][z-1]==-1) {
							q.offer(new int[] {nx,ny,z-1});
							dist[nx][ny][z-1] = dist[x][y][z]+1;
						}
					} else if(dist[nx][ny][z]==-1){
						q.offer(new int[] {nx,ny,z});
						dist[nx][ny][z] = dist[x][y][z]+1;
					}

				}
			}
		}
		if(dist[N-1][M-1][0]==-1||dist[N-1][M-1][1]==-1) {
			return Math.max(dist[N-1][M-1][0], dist[N-1][M-1][1]);
		} else return Math.min(dist[N-1][M-1][0], dist[N-1][M-1][1]);
 	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		N=n;M=m;
		for(int i=0;i<n;i++) {
			String temp = br.readLine();
			for(int j=0;j<m;j++) {
				board[i][j] = temp.charAt(j)-'0';
			}
		}
		System.out.println(sb.append(bfs()));
	}
}
