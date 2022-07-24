import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int[][] a = new int[201][201];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		st = new StringTokenizer(br.readLine(), " ");
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			a[x][y] = 1;
			a[y][x] = 1;
		}
		int answer = 0;
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				if(a[i][j]==1) continue;
				for(int k=j+1;k<=n;k++) {
					if(a[j][k]==1||a[i][k]==1) continue;
					answer+=1;
				}
			}
		}
		System.out.println(sb.append(answer).append("\n"));
	}
}
