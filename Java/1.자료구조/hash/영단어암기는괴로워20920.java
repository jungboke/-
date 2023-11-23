import java.util.*;
import java.io.*;

public class Main {
	
	static class Edge {
		String x;
		Integer y;
		Edge(String x, Integer y) {
			this.x = x;
			this.y = y;
		}
	}
	
	static String answer = "";
	static HashMap<String, Integer> map1 = new HashMap<>();
	static List<Edge> a = new ArrayList<>();
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		for(int i=0;i<n;i++) {
			String x = br.readLine();
			if(x.length()<m) continue;
			map1.put(x, map1.getOrDefault(x, 0)+1);
		}
		for(Map.Entry<String,Integer> e : map1.entrySet()) {
			String x = e.getKey();
			Integer y = e.getValue();
			a.add(new Edge(x,y));
		}
		Collections.sort(a, new Comparator<Edge>() {
			public int compare(Edge o1, Edge o2) {
				if(o1.y-o2.y==0) {
					if(o1.x.length() - o2.x.length()==0) {
						return o1.x.compareTo(o2.x);
					}
					return (o1.x.length() - o2.x.length())*-1;
				}
				return (o1.y - o2.y)*-1;
			}
		});
		for(Edge e : a) {
			sb.append(e.x+"\n");
		}
		System.out.println(sb);
	}
	
}
