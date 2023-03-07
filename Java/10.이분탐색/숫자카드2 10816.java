//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Arrays;
//import java.util.Collections;
//import java.util.LinkedList;
//import java.util.List;
//import java.util.Queue;
//import java.util.StringTokenizer;
//
//public class Main {
//	
//	static List<Integer> a = new ArrayList<>();
//	
//	static int lower_bound(List<Integer> temp, int target) {
//		int start = 0;
//		int end = temp.size();
//		while(start<end) {
//			int mid = (start+end)/2;
//			if(temp.get(mid)>=target) {
//				end = mid;
//			} else start = mid+1;
//		}
//		return end;
//	}
//	
//	static int upper_bound(List<Integer> temp, int target) {
//		int start = 0;
//		int end = temp.size();
//		while(start<end) {
//			int mid = (start+end)/2;
//			if(temp.get(mid)<=target) {
//				start = mid+1;
//			} else end = mid;
//		}
//		return end;
//	}
//	
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		int n = Integer.parseInt(br.readLine());
//		st = new StringTokenizer(br.readLine());
//		for(int i=0;i<n;i++) {
//			int x = Integer.parseInt(st.nextToken());
//			a.add(x);
//		}
//		Collections.sort(a);
//		int m = Integer.parseInt(br.readLine());
//		st = new StringTokenizer(br.readLine());
//		for(int i=0;i<m;i++) {
//			int x = Integer.parseInt(st.nextToken());
//			int idx1 = upper_bound(a,x);
//			int idx2 = lower_bound(a,x);
//			sb.append(idx1-idx2+" ");
//		}
//		System.out.println(sb);
//	}
//}
// import java.io.*;
// import java.util.*;

// public class Main {
	
// 	static List<Integer> a = new ArrayList<>();
	
// 	static int lower_bound(List<Integer> temp, int target) {
// 		int start = 0;
// 		int end = temp.size();
// 		while(start<end) {
// 			int mid = (start+end)/2;
// 			if(temp.get(mid)>=target) {
// 				end = mid;
// 			} else start = mid+1;
// 		}
// 		return end;
// 	}
	
// 	static int upper_bound(List<Integer> temp, int target) {
// 		int start = 0;
// 		int end = temp.size();
// 		while(start<end) {
// 			int mid = (start+end)/2;
// 			if(temp.get(mid)<=target) {
// 				start = mid+1;
// 			} else end = mid;
// 		}
// 		return end;
// 	}
	
// 	public static void main(String[] args) throws NumberFormatException, IOException {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;
		
// 		int n = Integer.parseInt(br.readLine());
// 		st = new StringTokenizer(br.readLine());
// 		for(int i=0;i<n;i++) {
// 			int x = Integer.parseInt(st.nextToken());
// 			a.add(x);
// 		}
// 		Collections.sort(a);
// 		int m = Integer.parseInt(br.readLine());
// 		st = new StringTokenizer(br.readLine());
// 		for(int i=0;i<m;i++) {
// 			int x = Integer.parseInt(st.nextToken());
// 			int idx = lower_bound(a,x);
// 			sb.append(upper_bound(a,x)-lower_bound(a,x)+" ");
			
// 		}
// 		System.out.println(sb);
// 	}
// }
import java.util.*;
import java.io.*;

public class Main {
	
	static List<Integer> a = new ArrayList<>();
	
	static int lowerBound(List<Integer> temp, int target) {
		int start = 0;
		int end = temp.size();
		while(start<end) {
			int mid = (start+end)/2;
			if(temp.get(mid)>=target) {
				end = mid;
			} else start = mid+1;
		}
		return end;
	}
	
	static int upperBound(List<Integer> temp, int target) {
		int start = 0;
		int end = temp.size();
		while(start<end) {
			int mid = (start+end)/2;
			if(temp.get(mid)<=target) {
				start = mid+1;
			} else end = mid;
		}
		return end;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			int x = Integer.parseInt(st.nextToken());
			a.add(x);
		}
		Collections.sort(a);
		int m = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<m;i++) {
			int x = Integer.parseInt(st.nextToken());
			sb.append(upperBound(a,x)-lowerBound(a,x)+" ");
		}
		System.out.println(sb);
	}
}
