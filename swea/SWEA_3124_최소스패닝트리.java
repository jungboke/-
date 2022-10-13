//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Arrays;
//import java.util.List;
//import java.util.PriorityQueue;
//import java.util.StringTokenizer;
//
//public class SWEA_3124_최소스패닝트리 {
//
//    static class Edge {
//        int to;
//        int cost;
//        Edge(int to,int cost) {
//            this.to = to;
//            this.cost = cost;
//        }
//    }
//
//    static List<Edge>[] a = new ArrayList[100001];
//    static boolean[] check = new boolean[100001];
//    static PriorityQueue<Edge> pq = new PriorityQueue<>((o1,o2) -> (o1.cost - o2.cost));
//
//    public static void main(String[] args) throws IOException {
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        StringBuilder sb = new StringBuilder();
//        StringTokenizer st;
//
//        int t = Integer.parseInt(br.readLine());
//        int ot = t;
//        while(t-->0) {
//            st = new StringTokenizer(br.readLine());
//            int n = Integer.parseInt(st.nextToken());            
//            int m = Integer.parseInt(st.nextToken());
//            for(int i=1;i<=n;i++) a[i] = new ArrayList<>();
//            for(int i=0;i<m;i++) {
//                st = new StringTokenizer(br.readLine());
//                int x = Integer.parseInt(st.nextToken());
//                int y = Integer.parseInt(st.nextToken());
//                int z = Integer.parseInt(st.nextToken());
//                a[x].add(new Edge(y,z));
//                a[y].add(new Edge(x,z));
//            }
//            for(Edge k : a[1]) {
//                pq.offer(k);
//            }
//            check[1] = true;
//            long answer = 0;
//            while(!pq.isEmpty()) {
//                Edge e = pq.poll();
//                int x = e.to;
//                if(check[x]==true) continue;
//                check[x] = true;
//                answer += (long) e.cost;
//                for(Edge k : a[x]) {
//                    pq.offer(k);
//                }
//            }
//            sb.append("#"+(ot-t)+" "+answer+"\n");
//            Arrays.fill(check, false);
//        }
//        System.out.println(sb);
//    }
//}
import java.io.*;
import java.util.*;

public class Solution {
	
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
	static PriorityQueue<Edge> pq = new PriorityQueue<>(new Comparator<Edge>() {
		public int compare(Edge o1, Edge o2) {
			return o1.cost-o2.cost;
		}
	});
	static int[] parent = new int[100001];
	
	static int Find(int x) {
		if(parent[x]==x) return x;
		else return parent[x] = Find(parent[x]);
	}
	
	static void Union(int x, int y) {
		x = Find(x);
		y = Find(y);
		if(x==y) return;
		parent[y] = x; 
	}
	
    public static void main(String[] args) throws IOException {
    	System.setIn(new FileInputStream("data/3124.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int t = Integer.parseInt(br.readLine());
        int ot = t;
        while(t-->0) {
        	st = new StringTokenizer(br.readLine());
        	int n = Integer.parseInt(st.nextToken());
        	for(int i=1;i<=n;i++) parent[i] = i;
        	int m = Integer.parseInt(st.nextToken());
        	for(int i=0;i<m;i++) {
        		st = new StringTokenizer(br.readLine());
        		int x = Integer.parseInt(st.nextToken());
        		int y = Integer.parseInt(st.nextToken());
        		int z = Integer.parseInt(st.nextToken());
        		pq.add(new Edge(x,y,z));
        	}
        	long answer = 0;
        	while(!pq.isEmpty()) {
        		Edge e = pq.poll();
        		if(Find(e.to)!=Find(e.from)) {
        			answer+=e.cost;
        			Union(e.to,e.from);
        		}
        	}
        	sb.append("#"+(ot-t)+" "+answer+"\n");
        }
        System.out.println(sb);
	}
}