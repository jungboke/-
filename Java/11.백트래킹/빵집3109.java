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
//	static int[] dx = {-1,0,1};
//	static int[] dy = {1,1,1};
//	static char[][] board = new char[10001][501];
//	static boolean[][] check = new boolean[10001][501];
//	static int N,M;
//	static int answer = 0;
//	
//	static boolean dfs(int x, int y, int limit) {
//		check[x][y] = true;
//		if(y==limit-1) {
//			answer+=1;
//			return true;
//		}
//		for(int i=0;i<3;i++) {
//			int nx = x+dx[i];
//			int ny = y+dy[i];
//			if(nx>=0&&nx<N&&ny>=0&&ny<M&&check[nx][ny]==false) {
//				if(board[nx][ny]!='x') {
//					if(dfs(nx,ny,limit)) return true;
//				}
//			}
//		}
//		return false;
//	}
//	
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		st = new StringTokenizer(br.readLine());
//		int n = Integer.parseInt(st.nextToken());
//		int m = Integer.parseInt(st.nextToken());
//		N=n;M=m;
//		for(int i=0;i<n;i++) {
//			String temp = br.readLine();
//			for(int j=0;j<m;j++) {
//				board[i][j] = temp.charAt(j);
//			}
//		}
//		for(int i=0;i<n;i++) {
//			dfs(i,0,m);
//		}
//		System.out.println(sb.append(answer));
//	}
//}
// import java.io.*;
// import java.util.*;

// public class Main {

// 	static int[] dx = {-1,0,1};
// 	static int[] dy = {1,1,1};
// 	static char[][] board = new char[10001][501];
// 	static boolean[][] check = new boolean[10001][501];
// 	static int N,M;
// 	static int answer = 0;
	
// 	static boolean dfs(int x, int y) {
// 		check[x][y] = true;
// 		if(y==M-1) {
// 			answer+=1;
// 			return true;
// 		}
// 		for(int i=0;i<3;i++) {
// 			int nx = x+dx[i];
// 			int ny = y+dy[i];
// 			if(nx>=0&&nx<N&&ny>=0&&ny<M&&check[nx][ny]==false) {
// 				if(board[nx][ny]!='x') {
// 					if(dfs(nx,ny)) return true;
// 				}
// 			}
// 		}
// 		return false;
// 	}
	
// 	public static void main(String[] args) throws IOException {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;
		
// 		st = new StringTokenizer(br.readLine());
// 		int n = Integer.parseInt(st.nextToken());
// 		int m = Integer.parseInt(st.nextToken());
// 		N=n;M=m;
// 		for(int i=0;i<n;i++) {
// 			String temp = br.readLine();
// 			for(int j=0;j<m;j++) {
// 				board[i][j] = temp.charAt(j);
// 			}
// 		}
// 		for(int i=0;i<n;i++) {
// 			dfs(i,0);
// 		}
// 		System.out.println(sb.append(answer));
// 	}
// }
import java.util.*;
import java.io.*;

public class Main {
	
	static int[] dx = {-1,0,1};
	static char[][] board = new char[10001][501];
	static boolean[][] check = new boolean[10001][501];
	static int answer = 0;
	static int N,M;
	
	static boolean dfs(int x, int y) {
		check[x][y] = true;
		if(y==M-1) {
			answer+=1;
			return true;
		}
		for(int i=0;i<3;i++) {
			int nx = x+dx[i];
			int ny = y+1;
			if(nx>=0&&nx<N&&ny>=0&&ny<M&&board[nx][ny]!='x') {
				if(check[nx][ny]==false) {
					if(dfs(nx,ny)) return true;
				}
			}
		}
		return false;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		N=n;M=m;
		for(int i=0;i<n;i++) {
			String temp = br.readLine();
			for(int j=0;j<m;j++) {
				board[i][j] = temp.charAt(j);
			}
		}
		for(int i=0;i<n;i++) {
			dfs(i,0);
		}
		System.out.println(sb.append(answer));
	}
}
