//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Collections;
//import java.util.List;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//
//		st = new StringTokenizer(br.readLine());
//		int n = Integer.parseInt(st.nextToken());
//		int k = Integer.parseInt(st.nextToken());
//		List<Integer> a = new ArrayList<>();
//		st = new StringTokenizer(br.readLine());
//		for(int i=0;i<n;i++) {
//			int x = Integer.parseInt(st.nextToken());
//			a.add(x);
//		}
//		List<Integer> diff = new ArrayList<>();
//		for(int i=0;i<n-1;i++) {
//			diff.add(a.get(i+1)-a.get(i));
//		}
//		Collections.sort(diff);
//		int answer = 0;
//		for(int i=0;i<diff.size()-k+1;i++) {
//			answer += diff.get(i);
//		}
//		System.out.println(sb.append(answer + "\n"));
//	}
//}
import java.io.*;
import java.util.*;

public class Main {
	
	static List<Integer> a = new ArrayList<>();
	static List<Integer> diff = new ArrayList<>();
	static int answer = 0;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			int x = Integer.parseInt(st.nextToken());
			a.add(x);
		}
		for(int i=1;i<n;i++) {
			int x = a.get(i)-a.get(i-1);
			diff.add(x);
		}
		Collections.sort(diff,Collections.reverseOrder());
		for(int i=k-1;i<diff.size();i++) {
			answer+=diff.get(i);
		}
		System.out.println(sb.append(answer));
	}
}
