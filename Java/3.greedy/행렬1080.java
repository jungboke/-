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
//	static int[][] board = new int[51][51];
//	static int[][] ans_board = new int[51][51];
//	static int N,M;
//	
//	static void toggle_map(int px, int py) {
//		for(int i=0;i<3;i++) {
//			for(int j=0;j<3;j++) {
//				board[px+i][py+j] = 1-board[px+i][py+j];
//			}
//		}
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
//				board[i][j] = temp.charAt(j)-'0';
//			}
//		}
//		int answer = 0;
//		for(int i=0;i<n;i++) {
//			String temp = br.readLine();
//			for(int j=0;j<m;j++) {
//				ans_board[i][j] = temp.charAt(j)-'0';
//			}
//		}
//		for(int i=0;i<=n-3;i++) {
//			for(int j=0;j<=m-3;j++) {
//				if(board[i][j]!=ans_board[i][j]) {
//					toggle_map(i,j);
//					answer+=1;
//				}
//			}
//		}
//		for(int i=0;i<n;i++) {
//			for(int j=0;j<m;j++) {
//				if(board[i][j]!=ans_board[i][j]) {
//					System.out.println(sb.append(-1));
//					return;
//				}
//			}
//		}
//		System.out.println(sb.append(answer));
//	}
//}
import java.io.*;
import java.util.*;

public class Main {

	static int[][] a = new int[51][51];
	static int[][] b = new int[51][51];
	static int answer = 0;
	
	static void change(int x, int y) {
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				a[x+i][y+j] = 1-a[x+i][y+j];
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		for(int i=0;i<n;i++) {
			String temp = br.readLine();
			for(int j=0;j<m;j++) {
				a[i][j] = temp.charAt(j)-'0';
			}
		}
		for(int i=0;i<n;i++) {
			String temp = br.readLine();
			for(int j=0;j<m;j++) {
				b[i][j] = temp.charAt(j)-'0';
			}
		}
		for(int i=0;i<n-2;i++) {
			for(int j=0;j<m-2;j++) {
				if(a[i][j]!=b[i][j]) {
					change(i,j);
					answer+=1;
				}
			}
		}
		boolean flag = true;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(a[i][j]!=b[i][j]) flag = false;
			}
		}
		if(flag==true) System.out.println(sb.append(answer));
		else System.out.println(sb.append(-1));
	}
}