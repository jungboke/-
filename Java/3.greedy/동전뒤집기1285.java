//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Arrays;
//import java.util.Collections;
//import java.util.List;
//import java.util.StringTokenizer;
//
//public class Main {
//	
//	static char[][] board = new char[20][20];
//	static int N;
//	
//	static void row_toggle(char[][] a, int x) {
//		for(int j=0;j<N;j++) {
//			if(a[x][j]=='H') a[x][j] = 'T';
//			else a[x][j] = 'H';
//		}
//	}
//	
//	static int cal(char[][] a) {
//		int result = 0;
//		for(int j=0;j<N;j++) {
//			int H = 0;
//			int T = 0;
//			for(int i=0;i<N;i++) {
//				if(a[i][j]=='H') H+=1;
//				else T+=1;
//			}
//			result += Math.min(H, T);
//		}
//		return result;
//	}
//	
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		int n = Integer.parseInt(br.readLine());
//		N=n;
//		for(int i=0;i<n;i++) {
//			String temp = br.readLine();
//			for(int j=0;j<n;j++) {
//				board[i][j] = temp.charAt(j);
//			}
//		}
//		int mini = Integer.MAX_VALUE;
//		for(int i=0;i<(1<<N);i++) {
//			for(int j=0;j<N;j++) {
//				if((i&(1<<j))!=0) {
//					row_toggle(board,j);
//				}
//			}
//			mini = Math.min(mini, cal(board));
//			for(int j=0;j<N;j++) {
//				if((i&(1<<j))!=0) {
//					row_toggle(board,j);
//				}
//			}
//		}
//		System.out.println(sb.append(mini));
//	}
//}
import java.io.*;
import java.util.*;

public class Main {

	static char[][] board = new char[21][21];
	static int mini = Integer.MAX_VALUE;
	static int N;
	
	static void reverse_row(char[][] tmp_board, int x) {
		for(int j=0;j<N;j++) {
			if(tmp_board[x][j]=='H') tmp_board[x][j] = 'T';
			else tmp_board[x][j] = 'H';
		}
	}
	
	static int check_col(char[][] tmp_board, int y) {
		int t_cnt = 0;
		int h_cnt = 0;
		for(int i=0;i<N;i++) {
			if(tmp_board[i][y]=='T') t_cnt+=1;
			else h_cnt+=1;
		}
		return Math.min(t_cnt, h_cnt);
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		N=n;
		for(int i=0;i<n;i++) {
			String temp = br.readLine();
			for(int j=0;j<n;j++) {
				board[i][j] = temp.charAt(j);
			}
		}
		for(int i=0;i<(1<<n);i++) {
			for(int j=0;j<n;j++) {
				if((i&(1<<j))!=0) {
					reverse_row(board,j);
				}
			}
			int sum = 0;
			for(int j=0;j<N;j++) {
				sum += check_col(board,j);
			}
			mini = Math.min(mini, sum);
			for(int j=0;j<n;j++) {
				if((i&(1<<j))!=0) {
					reverse_row(board,j);
				}
			}
		}
		System.out.println(sb.append(mini));
	}
}