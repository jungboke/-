import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		int t = Integer.parseInt(br.readLine());
		while(t-->0) {
			int n = Integer.parseInt(br.readLine());
			int[][] a = new int[2][n+1];
			int[][] d = new int[n+1][3];
			for(int i=0;i<2;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=1;j<=n;j++) {
					a[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			for(int i=1;i<=n;i++) {
				d[i][0] = Math.max(d[i-1][1], d[i-1][2]) + a[0][i];
				d[i][1] = Math.max(d[i-1][0], d[i-1][2]) + a[1][i];
				d[i][2] = Math.max(Math.max(d[i-1][0], d[i-1][1]),d[i-1][2]);
			}
			sb.append(Math.max(Math.max(d[n][0], d[n][1]),d[n][2]) + "\n");
		}
		System.out.println(sb);
	}
}
