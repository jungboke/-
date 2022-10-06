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
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//
//		st = new StringTokenizer(br.readLine());
//		int n = Integer.parseInt(st.nextToken());
//		int m = Integer.parseInt(st.nextToken());
//		for(int i=0;i<n;i++) {
//			int x = Integer.parseInt(br.readLine());
//			a.add(x);
//		}
//		Collections.sort(a,Collections.reverseOrder());
//		int answer = 0;
//		for(int i=0;i<a.size();i++) {
//			if(m/a.get(i)!=0) {
//				answer += m/a.get(i);
//				m%=a.get(i);
//			}
//		}
//		System.out.println(sb.append(answer));
//	}
//}
//
import java.io.*;
import java.util.*;

public class Main {

	static List<Integer> a = new ArrayList<>();
	static int answer = 0;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		for(int i=0;i<n;i++) {
			int x = Integer.parseInt(br.readLine());
			a.add(x);
		}
		Collections.reverse(a);
		for(int i=0;i<a.size();i++) {
			int x = a.get(i);
			if(k/x!=0) {
				answer+=k/x;
				k%=x;
			}
		}
		System.out.println(sb.append(answer));
	}
}
