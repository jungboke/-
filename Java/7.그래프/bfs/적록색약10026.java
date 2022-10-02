//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Arrays;
//import java.util.LinkedList;
//import java.util.List;
//import java.util.Queue;
//import java.util.StringTokenizer;
//
//public class Main {
//	
//	static int[] dx = {0,-1,0,1};
//	static int[] dy = {-1,0,1,0};
//	static char[][] board = new char[101][101];
//	static int[][] color = new int[101][101];
//	static List<int[]> green = new ArrayList<>();
//	static int maxi;
//	static int N;
//	
//	static int bfs() {
//		for(int i=0;i<N;i++) Arrays.fill(color[i], -1);
//		maxi = 1;
//		for(int i=0;i<N;i++) {
//			for(int j=0;j<N;j++) {
//				if(color[i][j]!=-1) continue;
//				Queue<int[]> q = new LinkedList<>();
//				q.offer(new int[] {i,j});
//				color[i][j] = maxi;
//				while(!q.isEmpty()) {
//					int now[] = q.poll();
//					int x = now[0]; int y = now[1];
//					for(int k=0;k<4;k++) {
//						int nx = x+dx[k];
//						int ny = y+dy[k];
//						if(nx>=0&&nx<N&&ny>=0&&ny<N&&color[nx][ny]==-1) {
//							if(board[nx][ny]==board[x][y]) {
//								q.offer(new int[] {nx,ny});
//								color[nx][ny] = maxi;
//							}
//						}
//					}
//				}
//				maxi+=1;
//			}
//		}
//		return maxi-1;
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
//				if(board[i][j]=='G') green.add(new int[] {i,j});
//			}
//		}
//		sb.append(bfs()+" ");
//		for(int i=0;i<green.size();i++) {
//			board[green.get(i)[0]][green.get(i)[1]] = 'R';
//		}
//		sb.append(bfs());
//		System.out.println(sb);
//	}
//}
import java.io.*;
import java.util.*;

public class Main {
		
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static char[][] board = new char[101][101];
	static boolean[][] check = new boolean[101][101];
	static int N;
	
	static int bfs() {
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) check[i][j] = false;
		}
		int result = 0;
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(check[i][j]==true) continue;
				result+=1;
				Queue<int[]> q = new LinkedList<>();
				q.offer(new int[] {i,j});
				check[i][j] = true;
				while(!q.isEmpty()) {
					int[] now = q.poll();
					int x = now[0]; int y = now[1];
					for(int k=0;k<4;k++) {
						int nx = x+dx[k];
						int ny = y+dy[k];
						if(nx>=0&&nx<N&&ny>=0&&ny<N&&check[nx][ny]==false) {
							if(board[nx][ny]==board[x][y]) {
								q.offer(new int[] {nx,ny});
								check[nx][ny] = true;
							}
						}
					}
				}
			}
		}
		return result;
	}
	
	static void makeR() {
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(board[i][j]=='G') board[i][j] = 'R';
			}
		}
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
		sb.append(bfs()+" ");
		makeR();
		sb.append(bfs());
		System.out.println(sb);
	}
}
