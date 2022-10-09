//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.LinkedList;
//import java.util.List;
//import java.util.Queue;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	static List<Integer>[] a = new ArrayList[1001];
//	static int[] ind = new int[1001];
//	static int[] dist = new int[1001];
//	static Queue<Integer> q = new LinkedList<>();
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
//			a[x].add(y);
//			ind[y]+=1;
//		}
//		for(int i=1;i<=n;i++) {
//			if(ind[i]==0) {
//				q.offer(i);
//				dist[i] = 1;
//			}
//		}
//		while(!q.isEmpty()) {
//			int x = q.poll();
//			for(int k:a[x]) {
//				ind[k]-=1;
//				dist[k] = Math.max(dist[k], dist[x]+1);
//				if(ind[k]==0) {
//					q.offer(k);
//				}
//			}
//		}
//		for(int i=1;i<=n;i++) {
//			sb.append(dist[i]+" ");
//		}
//		System.out.println(sb);
//	}
//}
import java.io.*;
import java.util.*;

public class Main {
	
	static List<Integer>[] a = new ArrayList[1001];
	static int[] ind = new int[1001];
	static int[] dist = new int[1001];
	
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
			a[x].add(y);
			ind[y]+=1;
		}
		Queue<Integer> q = new LinkedList<>();
		for(int i=1;i<=n;i++) {
			if(ind[i]==0) {
				q.offer(i);
				dist[i] = 1;
			}
		}
		while(!q.isEmpty()) {
			int x = q.poll();
			for(int k:a[x]) {
				ind[k]-=1;
				if(ind[k]==0) {
					q.offer(k);
					dist[k] = dist[x]+1;
				}
			}
		}
		for(int i=1;i<=n;i++) {
			sb.append(dist[i]+" ");
		}
		System.out.println(sb);
	}
}
