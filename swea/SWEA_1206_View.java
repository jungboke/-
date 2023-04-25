import java.util.*;
import java.io.*;

public class Solution {
	
	static int[] a = new int[1001];
	static int answer = 0;
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("data/1206.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = 10;
		int ot = t;
		while(t-->0) {
			int n = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<n;i++) {
				a[i] = Integer.parseInt(st.nextToken());
			}
			for(int i=0;i<n;i++) {
				outer:for(int j=0;j<=a[i];j++) {
					for(int k=i-2;k<=i+2;k++) {
						if(k<0||i==k) continue;
						if(a[k]>=j) continue outer;
					}
					answer+=1;
				}
			}
			sb.append("#"+(ot-t)+" "+answer+"\n");
			answer = 0;
		}
		System.out.println(sb);
	}
}
