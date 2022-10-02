//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.Arrays;
//import java.util.LinkedList;
//import java.util.Queue;
//import java.util.StringTokenizer;
//
//public class Main {
//	
//	static int[] dx = {0,-1,0,1};
//	static int[] dy = {-1,0,1,0};
//	static char[][] board = new char[101][101];
//	static int[][] dist = new int[101][101]; 
//	static int N,M;
//	
//	static int bfs(int sx, int sy, int ex, int ey) {
//		for(int i=0;i<N;i++) Arrays.fill(dist[i], -1);
//		Queue<int[]> q = new LinkedList<>();
//		q.offer(new int[] {sx,sy});
//		dist[sx][sy] = 0;
//		while(!q.isEmpty()) {
//			int[] now = q.poll();
//			int x = now[0]; int y = now[1];
//			for(int i=0;i<4;i++) {
//				int nx = x+dx[i];
//				int ny = y+dy[i];
//				while(true) {
//					boolean flag = false;
//					if(nx>=0&&nx<N&&ny>=0&&ny<M&&board[nx][ny]!='*') {
//						flag = true; 
//						if(dist[nx][ny]==-1) {
//							q.offer(new int[] {nx,ny});
//							dist[nx][ny] = dist[x][y]+1;
//						}
//					}
//					if(flag==false) break;
//					nx+=dx[i];
//					ny+=dy[i];
//				}
//			}
//		}
//		return dist[ex][ey]-1;
//	}
//	
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		st = new StringTokenizer(br.readLine());
//		int m = Integer.parseInt(st.nextToken());
//		int n = Integer.parseInt(st.nextToken());
//		N=n;M=m;
//		int sx=-1,sy=-1,ex=-1,ey=-1;
//		for(int i=0;i<n;i++) {
//			String temp = br.readLine();
//			for(int j=0;j<m;j++) {
//				board[i][j] = temp.charAt(j);
//				if(board[i][j]=='C') {
//					if(sx==-1&&sy==-1) {
//						sx = i;
//						sy = j;
//					} else {
//						ex = i;
//						ey = j;
//					}
//				}
//			}
//		}
//		System.out.println(sb.append(bfs(sx,sy,ex,ey)));
//	}
//}
import java.io.*;
import java.util.*;

public class Main {
		
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static char[][] board = new char[101][101];
	static int[][] dist = new int[101][101];
	static int N,M;
	
	static int bfs(int sx, int sy, int ex, int ey) {
		Queue<int[]> q = new LinkedList<>();
		q.offer(new int[] {sx,sy});
		dist[sx][sy] = 1;
		while(!q.isEmpty()) {
			int now[] = q.poll();
			int x = now[0]; int y = now[1];
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				while(nx>=0&&nx<N&&ny>=0&&ny<M&&board[nx][ny]!='*') {
					if(dist[nx][ny]==0) {						
						q.offer(new int[] {nx,ny});
						dist[nx][ny] = dist[x][y]+1;
					}
					nx+=dx[i];
					ny+=dy[i];
				}
			}
		}
		return dist[ex][ey]-2;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int m = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		N=n;M=m;
		int sx=-1,sy=-1,ex=-1,ey=-1;
		for(int i=0;i<n;i++) {
			String temp = br.readLine();
			for(int j=0;j<m;j++) {
				board[i][j] = temp.charAt(j);
				if(board[i][j]=='C') {
					if(sx==-1&&sy==-1) {
						sx=i;sy=j;
					} else ex=i;ey=j;
				}
			}
		}
		System.out.println(sb.append(bfs(sx,sy,ex,ey)));
	}
}