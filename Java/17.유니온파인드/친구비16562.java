import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static final int INF = 1000000000;
	static int[] a = new int[10002];
	static int[] best = new int[10002];
	static int[] parent = new int[10002];
	static int[] rank = new int[10002];

	static int Find(int x) {
		if(parent[x]==x) return x;
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

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		for(int i=1;i<=n;i++) {
			parent[i] = i;
			rank[i] = 0;
			best[i] = INF;
		}
		int m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for(int i=1;i<=n;i++) {
			a[i] = Integer.parseInt(st.nextToken());
		}
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			Union(x,y);
		}
		for(int i=1;i<=n;i++) {
			int temp = Find(i);
			best[temp] = Math.min(best[temp], a[i]);
		}
		int answer = 0;
		for(int i=1;i<=n;i++) {
			if(best[i]==INF) continue;
			answer+=best[i];
		}
		if(k<answer) sb.append("Oh no");
		else sb.append(answer);
		System.out.println(sb);
	}
}

