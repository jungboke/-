//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Collections;
//import java.util.Comparator;
//import java.util.List;
//import java.util.StringTokenizer;
//
//public class Main {
//	
//	static List<int[]> a = new ArrayList<>();
//	static boolean[] day = new boolean[10001];
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
//				return Integer.compare(x[0], y[0])*-1;
//			}
//		});
//		int answer = 0;
//		for(int i=0;i<n;i++) {
//			int x = a.get(i)[1];
//			for(int j=x;j>0;j--) {
//				if(day[j]==false) {
//					day[j] = true;
//					answer+=a.get(i)[0];
//					break;
//				}
//			}
//		}
//		System.out.println(sb.append(answer));
//	}
//}
import java.io.*;
import java.util.*;

public class Main {

	static List<int[]> a = new ArrayList<>();
	static boolean[] check = new boolean[10001];
	static int answer = 0;
	
	public static void main(String[] args) throws IOException {
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
				return (o1[0]-o2[0])*-1;
			}
		});
		for(int i=0;i<n;i++) {
			int p = a.get(i)[0]; int d = a.get(i)[1];
			for(int j=d;j>0;j--) {
				if(check[j]==false) {
					answer+=p;
					check[j] = true;
					break;
				}
			}
		}
		System.out.println(sb.append(answer));
	}
}