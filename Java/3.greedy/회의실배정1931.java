//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Arrays;
//import java.util.Collections;
//import java.util.Comparator;
//import java.util.LinkedList;
//import java.util.List;
//import java.util.Queue;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	static List<int[]> a = new ArrayList<>();
//
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//
//		int n = Integer.parseInt(br.readLine());
//		for(int i=0;i<n;i++) {
//			st = new StringTokenizer(br.readLine());
//			int x = Integer.parseInt(st.nextToken());
//			int y = Integer.parseInt(st.nextToken());
//			a.add(new int[] {x,y});
//		}
//		Collections.sort(a, new Comparator<int[]>() {
//			public int compare(int[] x, int[] y) {
//				if(x[1]==y[1]) return Integer.compare(x[0], y[0]);
//				return Integer.compare(x[1], y[1]);
//			}
//		});
//		int answer = 0;
//		int end = -1;
//		for(int i=0;i<a.size();i++) {
//			if(a.get(i)[0]>=end) {
//				answer+=1;
//				end = a.get(i)[1];
//			}
//		}
//		System.out.println(sb.append(answer));
//	}
//}
//
import java.io.*;
import java.util.*;

public class Main {
	
	static List<int[]> a = new ArrayList<>();
	static int answer = 0;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			a.add(new int[] {x,y});
		}
		Collections.sort(a,new Comparator<int[]>() {
			public int compare(int[] o1, int[] o2) {
				if(o1[1]==o2[1]) return o1[0]-o2[0];
				return o1[1]-o2[1];
			}
		});
		int start = 0;
		for(int i=0;i<n;i++) {
			if(start<=a.get(i)[0]) {
				answer+=1;
				start = a.get(i)[1];
			}
		}
		System.out.println(sb.append(answer));
	}
}
