//import java.io.BufferedReader;
//import java.io.FileInputStream;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Arrays;
//import java.util.List;
//import java.util.StringTokenizer;
//
//public class SWEA_1861_정사각형방 {
//	
//	static int[] dx = {0,-1,0,1};
//	static int[] dy = {-1,0,1,0};
//	static int[][] a = new int[1001][1001];
//	static int N;
//	static int maxi;
//	static int max_idx;
//	
//	static void move(int x, int y, int cnt, int target) {
//		for(int i=0;i<4;i++) {
//			int nx = x+dx[i];
//			int ny = y+dy[i];
//			if(nx>=0&&nx<N&&ny>=0&&ny<N) {
//				if(a[nx][ny]==a[x][y]+1) {
//					move(nx,ny,cnt+1,target);
//				}
//			}
//		}
//		if(maxi<=cnt) {
//			if(maxi==cnt&&max_idx>target) {
//				max_idx = target;
//			}
//			else if(maxi<cnt) {
//				maxi = cnt;
//				max_idx = target;
//			}
//		}
//	}
//	
//	public static void main(String[] args) throws NumberFormatException, IOException {
//		System.setIn(new FileInputStream("data/1861.txt"));
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		int t= Integer.parseInt(br.readLine());
//		int ot = t;
//		while(t-->0) {
//			int n = Integer.parseInt(br.readLine());
//			N=n;
//			for(int i=0;i<n;i++) {
//				st = new StringTokenizer(br.readLine());
//				for(int j=0;j<n;j++) {
//					a[i][j] = Integer.parseInt(st.nextToken());
//				}
//			}
//			for(int i=0;i<n;i++) {
//				for(int j=0;j<n;j++) {
//					move(i,j,1,a[i][j]);
//				}
//			}
//			sb.append("#"+(ot-t)+" "+max_idx+" "+maxi+"\n");
//			maxi = -1;
//			max_idx = -1;
//		}
//		System.out.println(sb);
//	}
//}
import java.io.*;
import java.util.*;

public class Solution {
	
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] board = new int[1001][1001];
	static boolean[][] check = new boolean[1001][1001];
	static int answer = 0;
	static int maxi = -1;
	static int N;
	
	static void dfs(int x, int y, int cnt, int target) {
		boolean flag = false;
		for(int i=0;i<4;i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx>=0&&nx<N&&ny>=0&&ny<N&&check[nx][ny]==false) {
				if(board[nx][ny]==board[x][y]+1) {
					flag = true;
					check[nx][ny] = true;
					dfs(nx,ny,cnt+1,target);
					check[nx][ny] = false;
				}
			}
		}
		if(flag==false) {
			if(maxi<=cnt) {
				if(maxi<cnt) {
					maxi = cnt;
					answer = target;
				} else if(maxi==cnt&&board[x][y]<answer) {
					maxi = cnt;
					answer = target;
				}
			}
		}
	}
	
    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("data/1861.txt"));
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int t = Integer.parseInt(br.readLine());
        int ot = t;
        while(t-->0) {
        	int n = Integer.parseInt(br.readLine());
        	N=n;
        	for(int i=0;i<n;i++) {
        		st = new StringTokenizer(br.readLine());
        		for(int j=0;j<n;j++) {
        			board[i][j] = Integer.parseInt(st.nextToken());
        		}
        	}
        	for(int i=0;i<n;i++) {
        		for(int j=0;j<n;j++) {
        			dfs(i,j,1,board[i][j]);
        		}
        	}
        	sb.append("#"+(ot-t)+" "+answer+" "+maxi+"\n");
        	answer = 0;
        	maxi = -1;
        }
        System.out.println(sb);
     }
}
