//import java.io.BufferedReader;
//import java.io.FileInputStream;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Arrays;
//import java.util.LinkedList;
//import java.util.List;
//import java.util.Queue;
//import java.util.StringTokenizer;
//
//public class Main {
//	
//	static int[] a = new int[100001];
//	static int[] dist = new int[100001];
//	
//	static int bfs(int n, int k) {
//		Arrays.fill(dist, Integer.MAX_VALUE);
//		Queue<Integer> q = new LinkedList<>();
//		q.offer(n);
//		dist[n] = 0;
//		while(!q.isEmpty()) {
//			int x = q.poll();
//			if(x-1>=0&&dist[x-1]>dist[x]+1) {
//				q.offer(x-1);
//				dist[x-1] = dist[x]+1;
//			}
//			if(x+1<a.length&&dist[x+1]>dist[x]+1) {
//				q.offer(x+1);
//				dist[x+1] = dist[x]+1;
//			}
//			if(2*x<a.length&&dist[2*x]>dist[x]+1) {
//				q.offer(2*x);
//				dist[2*x] = dist[x]+1;
//			}
//		}
//		return dist[k];
//	}
//	
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		st = new StringTokenizer(br.readLine());
//		int n = Integer.parseInt(st.nextToken());
//		int k = Integer.parseInt(st.nextToken());
//		System.out.println(sb.append(bfs(n,k)));
//	}
//}
import java.io.*;
import java.util.*;

public class Main {
		
	static int[] dist = new int[100001];
	
	static void bfs(int s, int t) {
		Arrays.fill(dist, Integer.MAX_VALUE);
		Queue<Integer> q = new LinkedList<>();
		q.offer(s);
		dist[s] = 0;
		while(!q.isEmpty()) {
			int x = q.poll();
			if(x-1>=0&&dist[x-1]>dist[x]+1) {
				q.offer(x-1);
				dist[x-1] = dist[x]+1;
			}
			if(x+1<=100000&&dist[x+1]>dist[x]+1) {
				q.offer(x+1);
				dist[x+1] = dist[x]+1;
			}
			if(x*2<=100000&&dist[x*2]>dist[x]+1) {
				q.offer(x*2);
				dist[x*2] = dist[x]+1;
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		bfs(n,k);
		System.out.println(sb.append(dist[k]));
	}
}