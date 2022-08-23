import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		char[] s = br.readLine().toCharArray();
		Arrays.sort(s);
		int sum = 0;
		for(int i=0;i<s.length;i++) {
			sum += (s[i]-'0');
		}
		if(s[0]!='0'||sum%3!=0) {
			System.out.println(sb.append("-1"));
			return;
		}
		for(int i=s.length-1;i>0;i--) {
			sb.append(s[i]);
		}
		sb.append("0");
		System.out.println(sb);
	}
}
