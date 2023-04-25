import java.util.*;
import java.io.*;

public class Solution {
	
	static int[] cost = new int[4];
	static int[] day = new int[13];
	static int[] d = new int[13];
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("data/1952.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<4;i++) {
				cost[i] = Integer.parseInt(st.nextToken());
			}
			st = new StringTokenizer(br.readLine());
			for(int i=1;i<=12;i++) {
				day[i] = Integer.parseInt(st.nextToken());
			}
			for(int i=1;i<=12;i++) {
				List<Integer> temp = new ArrayList<>();
				temp.add(d[i-1]+day[i]*cost[0]);
				temp.add(d[i-1]+cost[1]);
				if(i-3>=0) temp.add(d[i-3]+cost[2]);
				temp.add(cost[3]);
				d[i] = Collections.min(temp);
			}
			sb.append("#"+(ot-t)+" "+d[12]+"\n");
			for(int i=1;i<=12;i++) {
				d[i] = 0;
			}
		}
		System.out.println(sb);
	}
}
