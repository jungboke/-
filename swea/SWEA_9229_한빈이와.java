import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class SWEA_9229_한빈이와 {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("data/9229.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
			List<Integer> a = new ArrayList<>();
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<n;i++) {
				a.add(Integer.parseInt(st.nextToken()));
			}
			int maxi = -1;
			for(int i=0;i<n;i++) {
				for(int j=i+1;j<n;j++) {
					int sum = a.get(i)+a.get(j);
					if(sum<=m) {
						maxi = Math.max(maxi, sum);
					}
				}
			}
			sb.append("#"+(ot-t)+" "+maxi+"\n");
		}
		System.out.println(sb);
	}
}
