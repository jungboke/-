//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Arrays;
//import java.util.Collections;
//import java.util.HashMap;
//import java.util.LinkedList;
//import java.util.List;
//import java.util.Queue;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	static List<Integer> a = new ArrayList<>();
//	static List<Integer> b = new ArrayList<>();
//
//
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//
//		st = new StringTokenizer(br.readLine());
//		int n = Integer.parseInt(st.nextToken());
//		int m = Integer.parseInt(st.nextToken());
//		st = new StringTokenizer(br.readLine());
//		for(int i=0;i<n;i++) {
//			int x = Integer.parseInt(st.nextToken());
//			a.add(x);
//		}
//		st = new StringTokenizer(br.readLine());
//		for(int i=0;i<m;i++) {
//			int x = Integer.parseInt(st.nextToken());
//			b.add(x);
//		}
//		a.addAll(b);
//		Collections.sort(a);
//		for(int i=0;i<a.size();i++) {
//			sb.append(a.get(i)+" ");
//		}
//		System.out.println(sb);
//	}
//}
import java.io.*;
import java.util.*;

public class Main {
	
	static List<Integer> a = new ArrayList<>();
	static List<Integer> b = new ArrayList<>();
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			int x = Integer.parseInt(st.nextToken());
			a.add(x);
		}
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<m;i++) {
			int x = Integer.parseInt(st.nextToken());
			b.add(x);
		}
		a.addAll(b);
		Collections.sort(a);
		for(int i=0;i<a.size();i++) {
			sb.append(a.get(i)+" ");
		}
		System.out.println(sb);
	}
}
