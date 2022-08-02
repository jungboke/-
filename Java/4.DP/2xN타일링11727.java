import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int[] d = new int[1001];

	public static void main(String[] args) throws Exception, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		int n = Integer.parseInt(br.readLine());
		d[0] = 1;
		d[1] = 1;
		for(int i=2;i<=n;i++) {
			d[i] = d[i-1] + 2*d[i-2];
			d[i]%=10007;
		}
		System.out.println(sb.append(d[n] + "\n"));
	}
}
