//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Collections;
//import java.util.Comparator;
//import java.util.List;
//import java.util.PriorityQueue;
//import java.util.StringTokenizer;
//
//public class Main {
//	
//	static List<int[]> gem = new ArrayList<>();
//	static List<Integer> bag = new ArrayList<>();
//	
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		st = new StringTokenizer(br.readLine());
//		int n = Integer.parseInt(st.nextToken());
//		int m = Integer.parseInt(st.nextToken());
//		for(int i=0;i<n;i++) {
//			st = new StringTokenizer(br.readLine());
//			int x = Integer.parseInt(st.nextToken());
//			int y = Integer.parseInt(st.nextToken());
//			gem.add(new int[] {x,y});
//		}
//		for(int i=0;i<m;i++) {
//			int x = Integer.parseInt(br.readLine());
//			bag.add(x);
//		}
//		Collections.sort(bag);
//		Collections.sort(gem, new Comparator<int[]>() {
//			public int compare(int[] x, int[] y) {
//				if(x[0]==y[0]) return Integer.compare(x[1], y[1])*-1;
//				return Integer.compare(x[0], y[0]);
//			}
//		});
//		PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
//		long answer = 0;
//		int idx = 0;
//		for(int i=0;i<bag.size();i++) {
//			while(idx<n&&gem.get(idx)[0]<=bag.get(i)) {
//				pq.offer(gem.get(idx++)[1]);
//			}
//			if(!pq.isEmpty()) {
//				answer += pq.poll();
//			}
//		}
//		System.out.println(sb.append(answer));
//	}
//}
import java.io.*;
import java.util.*;

public class Main {

	static List<int[]> gem = new ArrayList<>(); 
	static List<Integer> bag = new ArrayList<>();
	static PriorityQueue<Integer> pq = new PriorityQueue<>(new Comparator<Integer>() {
		public int compare(Integer o1, Integer o2) {
			return (o1-o2)*-1;
		}
	});
	static long answer = 0;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			gem.add(new int[] {x,y});
		}
		Collections.sort(gem, new Comparator<int[]>() {
			public int compare(int[] o1, int[] o2) {
				return o1[0]-o2[0];
			}
		});
		for(int i=0;i<k;i++) {
			int x = Integer.parseInt(br.readLine());
			bag.add(x);
		}
		Collections.sort(bag);
		int idx = 0;
		for(int i=0;i<bag.size();i++) {
			int w = bag.get(i);
			while(idx<n&&gem.get(idx)[0]<=w) {
				pq.offer(gem.get(idx++)[1]);
			}
			if(!pq.isEmpty()) answer += pq.poll();
		}
		System.out.println(sb.append(answer));
	}
}