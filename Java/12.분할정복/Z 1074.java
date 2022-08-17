import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int R,C;
	static int cnt = 0;
	
	static void dfs(int px, int py, int n) {
		if(n==1) {
			System.out.println(cnt);
			System.exit(0);
		}
		if(R<px+n/2&&C<py+n/2) {
			dfs(px,py,n/2);
		} else if(R<px+n/2&&C<py+n/2+n/2) {
			cnt+=(n*n)/4;
			dfs(px,py+n/2,n/2);
		} else if(R<px+n/2+n/2&&C<py+n/2) {
			cnt+=(n*n)/4*2;
			dfs(px+n/2,py,n/2);
		} else {
			cnt+=(n*n)/4*3;
			dfs(px+n/2,py+n/2,n/2);
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		R=r;C=c;
		int rn = (int)Math.pow(2, n);
		dfs(0,0,rn);
	}
}