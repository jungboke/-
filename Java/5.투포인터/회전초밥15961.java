import java.io.*;
import java.util.*;

public class Main {

	static List<Integer> a = new ArrayList<>();
	static TreeMap<Integer,Integer> map1 = new TreeMap<>();
	static int answer = -1;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		for(int i=0;i<n;i++) {
			int x = Integer.parseInt(br.readLine());
			a.add(x);
		}
		map1.put(c, map1.getOrDefault(c, 0)+1);
		for(int i=0;i<k;i++) {
			map1.put(a.get(i), map1.getOrDefault(a.get(i), 0)+1);
		}
		answer = Math.max(answer, map1.size());
		for(int i=k;i<n+k;i++) {
			if(map1.put(a.get(i-k), map1.get(a.get(i-k))-1)==1) {
				map1.remove(a.get(i-k));
			}
			map1.put(a.get(i%n), map1.getOrDefault(a.get(i%n), 0)+1);
			answer = Math.max(answer, map1.size());
		}
		System.out.println(sb.append(answer));
	}
}
