import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static boolean[] col = new boolean[16];
	// \
	static boolean[] dig1 = new boolean[32];
	// /
	static boolean[] dig2 = new boolean[32];
	static int answer = 0;
	static int N;

	static void dfs(int row) {
		if(row==N) {
			answer+=1;
			return;
		}
		for(int i=0;i<N;i++) {
			if(col[i]==false&&dig1[row-i+N-1]==false&&dig2[row+i]==false) {
				col[i] = true;
				dig1[row-i+N-1] = true;
				dig2[row+i] = true;
				dfs(row+1);
				dig2[row+i] = false;
				dig1[row-i+N-1] = false;
				col[i] = false;
			}
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		int n = Integer.parseInt(br.readLine());
		N=n;
		dfs(0);
		System.out.println(sb.append(answer));
	}
}
