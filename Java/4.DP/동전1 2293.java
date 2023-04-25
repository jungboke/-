import java.util.*;
import java.io.*;

public class Main {
	
	static int[] d = new int[10001];
			
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		d[0] = 1;
		for(int i=1;i<=n;i++) {
			int x = Integer.parseInt(br.readLine());
			for(int j=1;j<=m;j++) {
				if(j-x>0) d[j]+=d[j-x];
				else if(j-x==0) d[j]+=1;
			}
		}
		System.out.println(sb.append(d[m]));
	}
}
