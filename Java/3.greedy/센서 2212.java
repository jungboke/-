import java.util.*;
import java.io.*;

public class Main {
	
	static List<Integer> a = new ArrayList<>();	
	static List<Integer> diff = new ArrayList<>();
	static int answer = 0;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		int k = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			int x = Integer.parseInt(st.nextToken());
			a.add(x);
		}
		Collections.sort(a);
		for(int i=0;i<n-1;i++) {
			diff.add(a.get(i+1)-a.get(i));
		}
		Collections.sort(diff);
		for(int i=0;i<diff.size()-(k-1);i++) {
			answer += diff.get(i);
		}
		System.out.println(answer);
	}
}
