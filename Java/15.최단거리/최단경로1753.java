//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Collections;
//import java.util.List;
//import java.util.PriorityQueue;
//import java.util.Stack;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	static final int INF = 1000000000;
//	static class Node implements Comparable<Node>{
//		int to;
//		int cost;
//		Node(int to, int cost) {
//			this.to = to;
//			this.cost = cost;
//		}
//		public int compareTo(Node x) {
//			return Integer.compare(this.cost, x.cost);
//		}
//	}
//	static List<Node>[] a = new ArrayList[20001];
//	static PriorityQueue<Node> pq = new PriorityQueue<>();
//	static int dist[] = new int[20001];
//	static boolean check[] = new boolean[20001];
//
//
//	public static void main(String[] args) throws NumberFormatException, IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//
//		st = new StringTokenizer(br.readLine());
//		int n = Integer.parseInt(st.nextToken());
//		for(int i=1;i<=n;i++) a[i] = new ArrayList<>();
//		for(int i=1;i<=n;i++) dist[i] = INF;
//		int m = Integer.parseInt(st.nextToken());
//		int sx = Integer.parseInt(br.readLine());
//		for(int i=0;i<m;i++) {
//			st = new StringTokenizer(br.readLine());
//			int x = Integer.parseInt(st.nextToken());
//			int y = Integer.parseInt(st.nextToken());
//			int z = Integer.parseInt(st.nextToken());
//			a[x].add(new Node(y,z));
//		}
//		pq.add(new Node(sx,0));
//		dist[sx] = 0;
//		while(!pq.isEmpty()) {
//			Node now = pq.poll();
//			int x = now.to;
//			if(check[x]==true) continue;
//			check[x] = true;
//			for(Node k:a[x]) {
//				int y = k.to;
//				if(dist[y]>dist[x]+k.cost) {
//					dist[y] = dist[x]+k.cost;
//					pq.add(new Node(y,dist[y]));
//				}
//			}
//		}
//		for(int i=1;i<=n;i++) {
//			if(dist[i]==INF) sb.append("INF"+"\n");
//			else sb.append(dist[i]+"\n");
//		}
//		System.out.println(sb);
//	}
//}
// import java.io.*;
// import java.util.*;

// public class Main {
	
// 	static class Edge {
// 		int to;
// 		int cost;
// 		Edge(int to, int cost) {
// 			this.to = to;
// 			this.cost = cost;
// 		}
// 	}
	
// 	static List<Edge>[] a = new ArrayList[20001]; 
// 	static int[] dist = new int[20001];
	
// 	public static void main(String[] args) throws NumberFormatException, IOException {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;
		
// 		st = new StringTokenizer(br.readLine());
// 		int n = Integer.parseInt(st.nextToken());
// 		for(int i=1;i<=n;i++) {
// 			dist[i] = Integer.MAX_VALUE;
// 			a[i] = new ArrayList<>();
// 		}
// 		int m = Integer.parseInt(st.nextToken());
// 		int k = Integer.parseInt(br.readLine());
// 		for(int i=0;i<m;i++) {
// 			st = new StringTokenizer(br.readLine());
// 			int x = Integer.parseInt(st.nextToken());
// 			int y = Integer.parseInt(st.nextToken());
// 			int z = Integer.parseInt(st.nextToken());
// 			a[x].add(new Edge(y,z));
// 		}
// 		PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
// 			public int compare(int[] o1, int[] o2) {
// 				return (o1[1]-o2[1]);
// 			}
// 		});
// 		pq.add(new int[] {k,0});
// 		dist[k] = 0;
// 		while(!pq.isEmpty()) {
// 			int[] now = pq.poll();
// 			int x = now[0];
// 			for(Edge e:a[x]) {
// 				int y = e.to;
// 				if(dist[y]>dist[x]+e.cost) {
// 					dist[y] = dist[x]+e.cost;
// 					pq.offer(new int[] {y,dist[x]});
// 				}
// 			}
// 		}
// 		for(int i=1;i<=n;i++) {
// 			if(dist[i]==Integer.MAX_VALUE) sb.append("INF"+"\n");
// 			else sb.append(dist[i]+"\n");
// 		}
// 		System.out.println(sb);
// 	}
// }
import java.util.*;
import java.io.*;

public class Main {
	
	static class Edge {
		int to;
		int cost;
		Edge(int to, int cost) {
			this.to = to;
			this.cost = cost;
		}
	}
	static PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
		public int compare(int[] o1, int[] o2) {
			return o1[1]-o2[1];
		}
	});
	static List<Edge>[] a = new ArrayList[20001];
	static int[] dist = new int[20001];
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(br.readLine());
		for(int i=1;i<=n;i++) {
			a[i] = new ArrayList<>();
			dist[i] = Integer.MAX_VALUE;
		}
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			int z = Integer.parseInt(st.nextToken());
			a[x].add(new Edge(y,z));
		}
		dist[k] = 0;
		pq.add(new int[] {k,0});
		while(!pq.isEmpty()) {
			int[] now = pq.poll();
			int x = now[0];
			for(Edge e:a[x]) {
				int y = e.to;
				if(dist[y]>dist[x]+e.cost) {
					dist[y] = dist[x]+e.cost;
					pq.add(new int[] {y,dist[y]});
				}
			}
		}
		for(int i=1;i<=n;i++) {
			if(dist[i]==Integer.MAX_VALUE) sb.append("INF"+"\n");
			else sb.append(dist[i]+"\n");
		}
		System.out.println(sb);
	}
}
