//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	static boolean[] col = new boolean[16];
//	// \
//	static boolean[] dig1 = new boolean[32];
//	// /
//	static boolean[] dig2 = new boolean[32];
//	static int answer = 0;
//	static int N;
//
//	static void dfs(int row) {
//		if(row==N) {
//			answer+=1;
//			return;
//		}
//		for(int i=0;i<N;i++) {
//			if(col[i]==false&&dig1[row-i+N-1]==false&&dig2[row+i]==false) {
//				col[i] = true;
//				dig1[row-i+N-1] = true;
//				dig2[row+i] = true;
//				dfs(row+1);
//				dig2[row+i] = false;
//				dig1[row-i+N-1] = false;
//				col[i] = false;
//			}
//		}
//	}
//
//	public static void main(String[] args) throws NumberFormatException, IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//
//		int n = Integer.parseInt(br.readLine());
//		N=n;
//		dfs(0);
//		System.out.println(sb.append(answer));
//	}
//}
import java.io.*;
import java.util.*;

public class Main {

	static int answer = 0;
	static boolean[] col = new boolean[15];
	static boolean[] r_dig = new boolean[31];
	static boolean[] l_dig = new boolean[31];
	static int N;
	
	static boolean queen_check(int r, int c) {
		if(col[c]==true) return false;
		if(r_dig[r-c+N-1]==true) return false;
		if(l_dig[r+c]==true) return false;
		return true;
	}
	
	static void dfs(int r) {
		if(r==N) {
			answer+=1;
			return;
		}
		for(int i=0;i<N;i++) {
			if(!queen_check(r,i)) continue;
			col[i] = true;
			r_dig[r-i+N-1] = true;
			l_dig[r+i] = true;
			dfs(r+1);
			l_dig[r+i] = false;
			r_dig[r-i+N-1] = false;
			col[i] = false;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		N=n;
		dfs(0);
		System.out.println(sb.append(answer));
	}
}
