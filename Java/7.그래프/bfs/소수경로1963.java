//import java.io.BufferedReader;
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
//	static int[] dist = new int[10000];
//	
//	static boolean prime_check(int num) {
//		if(num==0||num==1) return false;
//		for(int i=2;i<=Math.sqrt(num);i++) {
//			if(num%i==0) return false;
//		}
//		return true;
//	}
//	
//	static List<Integer> prime_change(String x) {
//		List<Integer> temp = new ArrayList<>();
//		for(int i=0;i<4;i++) {
//			char[] ary_x = x.toCharArray();
//			for(int j=0;j<=9;j++) {
//				if(i==0&&j==0) continue;
//				ary_x[i] = (char)(j+'0');
//				int num = Integer.parseInt(String.valueOf(ary_x));
//				if(prime_check(num)) {
//					temp.add(num);
//				}
//			}
//		}
//		return temp;
//	}
//	
//	static String bfs(int px, int py) {
//		Arrays.fill(dist, Integer.MAX_VALUE);
//		Queue<Integer> q = new LinkedList<>();
//		q.offer(px);
//		dist[px] = 0;
//		while(!q.isEmpty()) {
//			int x = q.poll();
//			List<Integer> temp = prime_change(Integer.toString(x));
//			for(int i=0;i<temp.size();i++) {
//				if(dist[temp.get(i)]>dist[x]+1) {
//					q.offer(temp.get(i));
//					dist[temp.get(i)] = dist[x]+1;
//				}
//			}
//		}
//		if(dist[py]==Integer.MAX_VALUE) return "Impossible";
//		else return Integer.toString(dist[py]);
//	}
//	
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		int t = Integer.parseInt(br.readLine());
//		while(t-->0) {
//			st = new StringTokenizer(br.readLine());
//			int x = Integer.parseInt(st.nextToken());
//			int y = Integer.parseInt(st.nextToken());
//			sb.append(bfs(x,y)+"\n");
//		}
//		System.out.println(sb);
//	}
//}
import java.io.*;
import java.util.*;

public class Main {
		
	static final int INF = Integer.MAX_VALUE;
	static int[] dist = new int[10000];
	
	static boolean prime_check(int x) {
		if(x<1000) return false;
		if(x==0||x==1) return false;
		for(int i=2;i<=Math.sqrt(x);i++) {
			if(x%i==0) return false;
		}
		return true;
	}
	
	static String bfs(int s, int t) {
		Arrays.fill(dist, INF);
		Queue<Integer> q = new LinkedList<>();
		q.offer(s);
		dist[s] = 0;
		while(!q.isEmpty()) {
			int x = q.poll();
			for(int i=0;i<4;i++) {
				for(int j=0;j<=9;j++) {
					StringBuilder sb = new StringBuilder(Integer.toString(x));
					sb.setCharAt(i, (char)('0'+j));
					int nx = Integer.parseInt(sb.toString());
					if(prime_check(nx)&&dist[nx]>dist[x]+1) {
						q.offer(nx);
						dist[nx] = dist[x]+1;
					}
				}
			}
		}
		if(dist[t]==INF) return "Impossible";
		else return Integer.toString(dist[t]);
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			sb.append(bfs(x,y)+"\n");
		}
		System.out.println(sb);
	}
}