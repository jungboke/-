import java.io.*;
import java.util.*;

public class Main {
	
	static List<int[]> star = new ArrayList<>();
	static int answer = Integer.MAX_VALUE;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int l = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		for(int i=0;i<k;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			star.add(new int[] {x,y});
		}
		for(int i=0;i<star.size();i++) {
			for(int j=0;j<star.size();j++) {
				int result = 0;
				int px = star.get(i)[0]; int py = star.get(j)[1];
				for(int c=0;c<star.size();c++) {
					int x = star.get(c)[0]; int y = star.get(c)[1];
					if(x>=px&&x<=px+l&&y>=py&&y<=py+l) result+=1; 
				}
				answer = Math.min(answer,k-result);
			}
		}
		System.out.println(sb.append(answer));
	} 
}
