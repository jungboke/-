//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.Arrays;
//import java.util.Collections;
//import java.util.LinkedList;
//import java.util.Queue;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	static void dfs(String a, String b) {
//		if(a.length()==b.length()) {
//			if(a.equals(b)) {
//				System.out.println(1);
//				System.exit(0);
//			}
//			return;
//		}
//		if(a.endsWith("A")) {
//			String temp = a.substring(0, a.length()-1);
//			dfs(temp,b);
//		}
//		String temp = new StringBuilder(a).reverse().toString();
//		if(temp.endsWith("B")) {
//			String temp2 = temp.substring(0, temp.length()-1);
//			dfs(temp2,b);
//		}
//	}
//
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//
//		String a = br.readLine();
//		String b = br.readLine();
//		dfs(b,a);
//		System.out.println(0);
//	}
//}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
	
	static int[][] d = new int[100][2];
	
	static void dfs(String t, String s) {
		if(t.length()==s.length()) {
			if(t.equals(s)) {
				System.out.println(1);
				System.exit(0);
			}
			return;
		}
		if(t.endsWith("A")) {
			StringBuilder sb = new StringBuilder(t); 
			sb.deleteCharAt(sb.length()-1);
			dfs(sb.toString(),s);
		}
		
		if(t.startsWith("B")) {
			StringBuilder sb = new StringBuilder(t); 
			sb.deleteCharAt(0);
			sb.reverse();
			dfs(sb.toString(),s);
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		String s = br.readLine();
		String t = br.readLine();
		dfs(t,s);
		System.out.println(0);
	}
}