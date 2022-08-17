import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;


public class Main {
	
	static List<Integer> a = new ArrayList<>();
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			int x = Integer.parseInt(st.nextToken());
			a.add(x);
		}
		Collections.sort(a);
		int answer = 0;
		int sum = 0;
		for(int i=0;i<n;i++) {
			sum+=a.get(i);
			answer+=sum;
		}
		System.out.println(sb.append(answer));
	}
}