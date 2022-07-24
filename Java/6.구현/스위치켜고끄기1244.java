import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static int[] a = new int[101];
	public static int N;

	public static void man(int x) {
		for(int i=0;i<N;i++) {
			if((i+1)%x==0) {
				a[i] = 1-a[i];
			}
		}
	}

	public static void woman(int x) {
		int cnt = 1;
		a[x-1] = 1-a[x-1];
		while(x-cnt>=1&&x+cnt<=N) {
			if(a[x-cnt-1]==a[x+cnt-1]) {
				a[x-cnt-1] = 1-a[x-cnt-1];
				a[x+cnt-1] = 1-a[x+cnt-1];
			} else break;
			cnt+=1;
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		int n = Integer.parseInt(br.readLine());
		N=n;
		st = new StringTokenizer(br.readLine()," ");
		for(int i=0;i<n;i++) {
			a[i] = Integer.parseInt(st.nextToken());
		}
		int m = Integer.parseInt(br.readLine());
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine()," ");
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			if(x==1) man(y);
			else woman(y);
		}
		for(int i=0;i<n;i++) {
			sb.append(a[i]).append(" ");
			if((i+1)%20==0) sb.append("\n");
		}
		System.out.println(sb);
	}
}

