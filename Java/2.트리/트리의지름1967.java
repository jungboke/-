import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static class Node {
		int to;
		int cost;
		public Node(int to, int cost) {
			this.to = to;
			this.cost = cost;
		}
	}

	static List<Node>[] a = new ArrayList[10001];
	static int[] dist = new int[10001];
	static int N;

	static int[] bfs(int x) {
		Queue<Integer> q = new LinkedList<>();
		q.offer(x);
		dist[x] = 0;
		while(!q.isEmpty()) {
			int nx = q.poll();
			for(Node k : a[nx]) {
				int ny = k.to;
				if(dist[ny]==-1) {
					q.offer(ny);
					dist[ny] = dist[nx]+k.cost;
				}
			}
		}
		int maxi = -1;
		int max_idx = -1;
		for(int i=1;i<=N;i++) {
			if(maxi<dist[i]) {
				maxi = dist[i];
				max_idx = i;
			}
		}
		return new int[] {maxi,max_idx};
	}


	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		int n = Integer.parseInt(br.readLine());
		N=n;
		for(int i=1;i<=n;i++) {
			a[i] = new ArrayList<Node>();
		}
		for(int i=0;i<n-1;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			int z = Integer.parseInt(st.nextToken());
			a[x].add(new Node(y,z));
			a[y].add(new Node(x,z));
		}
		Arrays.fill(dist, -1);
		int[] temp = bfs(1);
		Arrays.fill(dist,-1);
		temp = bfs(temp[1]);
		System.out.println(sb.append(temp[0] + "\n"));
	}
}
