import java.util.*;
import java.io.*;

public class Main {
	
	static int answer = 0;
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		if(n==1) answer = 1;
		else if(n==2) answer = Math.min(4,(m+1)/2);
		else {
			if(m==1) answer = 1;
			else if(m==2) answer = 2;
			else if(m==3) answer = 3;
			else if(m==4) answer = 4;
			else if(m==5) answer = 4;
			else if(m==6) answer = 4;
			else answer = m-2;
		}
		
		System.out.println(sb.append(answer));
	}
	
}
