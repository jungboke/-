import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] a = new int[101][101];
	static int[][] dist = new int[101][101];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		Queue<int[]> q = new LinkedList<>();
		for(int i=0;i<dist.length;i++) {
			Arrays.fill(dist[i], -1);
		}

		st = new StringTokenizer(br.readLine()," ");
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		for(int i=0;i<n;i++) {
			String temp = br.readLine();
			for(int j=0;j<m;j++) {
				a[i][j] = temp.charAt(j)-'0';
			}
		}
		q.offer(new int[] {0,0});
		dist[0][0] = 0;
		while(!q.isEmpty()) {
			int now[] = q.peek();
			int x = now[0];
			int y = now[1];
			q.poll();
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx>=0&&nx<n&&ny>=0&&ny<m) {
					if(dist[nx][ny]==-1&&a[nx][ny]==1) {
						q.offer(new int[] {nx,ny});
						dist[nx][ny] = dist[x][y]+1;
					}
				}
			}
		}
		System.out.println(sb.append(dist[n-1][m-1]+1).append("\n"));
	}
}
