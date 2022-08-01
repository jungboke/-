import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Map.Entry;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {

	static List<Integer>[] a = new ArrayList[100001];
	static int[] parent = new int[100001];

	static void dfs(int x, int before) {
		parent[x] = before;
		for(int k : a[x]) {
			if(parent[k]==0) {
				dfs(k,x);
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;


		int n = Integer.parseInt(br.readLine());
		for(int i=1;i<=n;i++) {
			a[i] = new ArrayList<Integer>();
		}
		for(int i=0;i<n-1;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			a[x].add(y);
			a[y].add(x);
		}
		dfs(1,-1);
		for(int i=2;i<=n;i++) {
			sb.append(parent[i] + "\n");
		}
		System.out.println(sb);
	}
}
