import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Kruskal {
	
	static class Edge {
		int from;
		int to;
		int cost;
		Edge(int from, int to, int cost) {
			this.from = from;
			this.to = to;
			this.cost = cost;
		}
	}
 	
	static List<Edge> a = new ArrayList<>();
	static int[] parent = new int[1001];
	static int[] rank = new int[1001];
	
	static int Find(int x) {
		if(x==parent[x]) return x;
		else return parent[x] = Find(parent[x]);
	}
	
	static void Union(int x, int y) {
		x = Find(x);
		y = Find(y);
		if(x==y) return;
		if(rank[x]<rank[y]) {
			int temp = x; x = y; y = temp;
		}
		parent[y] = x;
		if(rank[x]==rank[y]) rank[x]+=1;
	}
	
	static void make(int n) {
		for(int i=1;i<=n;i++) {
			parent[i] = i;
			rank[i] = 0;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		make(n);
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			int z = Integer.parseInt(st.nextToken());
			a.add(new Edge(x,y,z));
		}
		Collections.sort(a,(o1,o2) -> o1.cost - o2.cost);
		int answer = 0;
		int cnt = 0;
		for(Edge k : a) {
			if(Find(k.from)!=Find(k.to)) {
				Union(k.from,k.to);
				answer+=k.cost;
				if(++cnt==n-1) break;
			}
		}
		System.out.println(sb.append(answer));
	}
}
