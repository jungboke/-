import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class SWEA_1238_Contact {

	static List<Integer>[] a = new ArrayList[101];
	static int[] dist = new int[101];
	
	static int bfs(int m) {
		Queue<Integer> q = new LinkedList<>();
		q.offer(m);
		dist[m] = 0;
		while(!q.isEmpty()) {
			int x = q.poll();
			for(int k:a[x]) {
				if(dist[k]==-1) {
					q.offer(k);
					dist[k] = dist[x]+1;
				}
			}
		}
		int maxi = -1;
		for(int i=1;i<=100;i++) {
			maxi = Math.max(maxi, dist[i]);
		}
		int result = -1;
		for(int i=1;i<=100;i++) {
			if(dist[i]==maxi) result = Math.max(result, i);
		}
		return result;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("data/1238.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = 10;
		int ot = t;
		while(t-->0) {
			for(int i=1;i<=100;i++) a[i] = new ArrayList<>();
			Arrays.fill(dist, -1);
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<n/2;i++) {
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				a[x].add(y);
			}
			sb.append("#"+(ot-t)+" "+bfs(m)+"\n");
		}
		System.out.println(sb);
	}
}