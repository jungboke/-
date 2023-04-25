import java.util.*;
import java.io.*;

public class Solution {
	
	static Set<Integer> s = new HashSet<>();
	
	static void cal(StringBuilder temp, int k) {
		int n = temp.length();
		int m = n/4;
		int maxi = Integer.MIN_VALUE;
		for(int i=0;i<4;i++) {
			String x = temp.substring(m*i,m*i+m);
			int y = Integer.parseInt(x,16);
			s.add(y);
		}
	}
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("data/5658.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int k = Integer.parseInt(st.nextToken());
			StringBuilder temp = new StringBuilder(br.readLine());
			for(int i=0;i<n/4;i++) {
				cal(temp,k);
				char x = temp.charAt(0);
				temp.deleteCharAt(0);
				temp.append(x);
			}
			ArrayList<Integer> a = new ArrayList<>(s);
			Collections.sort(a,Comparator.reverseOrder());
			int answer = a.get(k-1);
			sb.append("#"+(ot-t)+" "+answer+"\n");
			s.clear();
		}
		System.out.println(sb);
	}
}
