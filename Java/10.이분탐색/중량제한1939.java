import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static class Node {
		int to;
		int cost;
		Node(int to, int cost) {
			this.to = to;
			this.cost = cost;
		}
	}

	static List<Node> a[] = new ArrayList[10001];
	static boolean check[] = new boolean[10001];

	static boolean bfs(int limit, int sx, int ex) {
		Arrays.fill(check, false);
		Queue<Integer> q = new LinkedList<>();
		q.offer(sx);
		check[sx] = true;
		while(!q.isEmpty()) {
			int x = q.poll();
			for(Node k:a[x]) {
				int y = k.to;
				if(check[y]==false&&k.cost>=limit) {
					q.offer(y);
					check[y] = true;
				}
			}
		}
		if(check[ex]==true) return true;
		else return false;
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		for(int i=1;i<=n;i++) a[i] = new ArrayList<>();
		int m = Integer.parseInt(st.nextToken());
		int maxi = -1;
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			int z = Integer.parseInt(st.nextToken());
			a[x].add(new Node(y,z));
			a[y].add(new Node(x,z));
			maxi = Math.max(maxi, z);
		}
		st = new StringTokenizer(br.readLine());
		int sx = Integer.parseInt(st.nextToken());
		int ex = Integer.parseInt(st.nextToken());

		int start = 0;
		int end = maxi;
		maxi = -1;
		while(start<=end) {
			int mid = (start+end)/2;
			if(bfs(mid,sx,ex)) {
				maxi = Math.max(maxi, mid);
				start = mid+1;
			} else {
				end = mid-1;
			}
		}
		System.out.println(sb.append(maxi));
	}

}
