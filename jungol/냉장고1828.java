import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	
	static List<int[]> a = new LinkedList<>();
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			a.add(new int[] {x,y});
		}
		Collections.sort(a, new Comparator<int[]>() {
			public int compare(int[] x, int[] y) {
				return Integer.compare(x[0], y[0]);
			}
		});
		int answer = 1;
		int now = a.get(0)[1];
		for(int i=1;i<a.size();i++) {
			if(now>a.get(i)[1]) {
				now = a.get(i)[1];
			} else if(now<a.get(i)[0]) {
				answer+=1;
				now = a.get(i)[1];
			}
		}
		System.out.println(sb.append(answer));
	}
}