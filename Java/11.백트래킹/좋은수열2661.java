import java.util.*;
import java.io.*;

public class Main {
	
	static StringBuilder answer = new StringBuilder();
	
	static boolean stringCheck(StringBuilder s) {
		StringBuilder temp = new StringBuilder(s);
		temp.reverse();
		for(int i=1;i<=temp.length()/2;i++) {
			String x = temp.substring(0, i);
			String y = temp.substring(i,i+i);
			if(x.equals(y)) {
				return false;
			}
		}
		return true;
	}
	
	static boolean dfs(StringBuilder s, int target) {
		if(s.length()==target) {
			answer.append(s);
			return true;
		}
		for(int i=1;i<=3;i++) {
			s.append(i);
			if(stringCheck(s)) {
				if(dfs(s,target)) return true;
			}
			s.setLength(s.length()-1);
		}
		return false;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		dfs(new StringBuilder(),n);
		System.out.println(sb.append(answer));
	}
}
