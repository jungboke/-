import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int answer = 0;
		while(true) {
			if(n-2<0||m-1<0) break;
			n-=2;m-=1;
			answer+=1;
		}
		int sum = n+m;
		while(true) {
			k-=sum;
			if(k>0) {
				sum=3;
				answer-=1;
			} else break;
		}
		System.out.println(sb.append(answer));
	}
}
