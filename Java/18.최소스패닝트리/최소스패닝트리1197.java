//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.LinkedList;
//import java.util.List;
//import java.util.PriorityQueue;
//import java.util.Queue;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	static class Edge implements Comparable<Edge>{
//		int to;
//		int cost;
//		Edge(int to,int cost) {
//			this.to = to;
//			this.cost = cost;
//		}
//		public int compareTo(Edge x) {
//			return Integer.compare(this.cost, x.cost);
//		}
//	}
//
//	static List<Edge>[] a = new ArrayList[10001];
//	static boolean[] check = new boolean[10001];
//	static PriorityQueue<Edge> pq = new PriorityQueue<>();
//
//	public static void main(String[] args) throws NumberFormatException, IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//
//		st = new StringTokenizer(br.readLine());
//		int n = Integer.parseInt(st.nextToken());
//		for(int i=1;i<=n;i++) a[i] = new ArrayList<>();
//		int m = Integer.parseInt(st.nextToken());
//		for(int i=0;i<m;i++) {
//			st = new StringTokenizer(br.readLine());
//			int x = Integer.parseInt(st.nextToken());
//			int y = Integer.parseInt(st.nextToken());
//			int z = Integer.parseInt(st.nextToken());
//			a[x].add(new Edge(y,z));
//			a[y].add(new Edge(x,z));
//		}
//		for(Edge k:a[1]) {
//			pq.add(k);
//		}
//		check[1] = true;
//		int answer = 0;
//		while(!pq.isEmpty()) {
//			Edge e = pq.poll();
//			int x = e.to;
//			if(check[x]==true) continue;
//			check[x] = true;
//			answer+=e.cost;
//			for(Edge k:a[x]) {
//				pq.add(k);
//			}
//		}
//		System.out.println(sb.append(answer));
//	}
//}
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
	}
	static PriorityQueue<Edge> pq = new PriorityQueue<>(new Comparator<Edge>() {
		public int compare(Edge o1, Edge o2) {
			return o1.cost-o2.cost;
		}
	});
	static List<Edge>[] a = new ArrayList[10001];
	static boolean[] check = new boolean[10001];
	static int answer = 0;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		for(int i=1;i<=n;i++) a[i] = new ArrayList<>();
		int m = Integer.parseInt(st.nextToken());
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			int z = Integer.parseInt(st.nextToken());
			a[x].add(new Edge(y,z));
			a[y].add(new Edge(x,z));
		}
		for(Edge k:a[1]) {
			pq.add(k);
		}
		check[1] = true;
		while(!pq.isEmpty()) {
			Edge e = pq.poll();
			int x = e.to;
			if(check[x]==true) continue;
			check[x] = true;
			answer+=e.cost;
			for(Edge k:a[x]) {
				pq.add(k);
			}
		}
		System.out.println(sb.append(answer));
	}
}
