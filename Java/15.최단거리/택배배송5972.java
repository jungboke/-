import java.io.*;
import java.util.*;

public class Main {
	
	static class Edge {
		int to;
		int cost;
		Edge(int to, int cost) {
			this.to = to;
			this.cost = cost;
		}
	};
	
	static List<Edge>[] a = new ArrayList[50001];
	static PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
		public int compare(int[] o1, int[] o2) {
			return o1[1]-o2[1];
		}
	});
	static int[] dist = new int[50001];
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        for(int i=1;i<=n;i++) {
        	a[i] = new ArrayList<>();
        	dist[i] = Integer.MAX_VALUE;
        }
        int m = Integer.parseInt(st.nextToken());
        for(int i=0;i<m;i++) {
        	st = new StringTokenizer(br.readLine());
        	int x = Integer.parseInt(st.nextToken());
        	int y = Integer.parseInt(st.nextToken());
        	int z = Integer.parseInt(st.nextToken());
        	a[x].add(new Edge(y,z));
        	a[y].add(new Edge(x,z));
        }
        dist[1] = 0;
        pq.add(new int[] {1,dist[1]});
        while(!pq.isEmpty()) {
        	int[] now = pq.poll();
        	int x = now[0];
        	for(Edge k:a[x]) {
        		int y = k.to;
        		if(dist[y]>dist[x]+k.cost) {
        			dist[y] = dist[x]+k.cost;
        			pq.offer(new int[] {y,dist[y]});
        		}
        	}
        }
        System.out.println(sb.append(dist[n]));
	} 
}