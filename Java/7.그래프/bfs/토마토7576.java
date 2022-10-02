//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Arrays;
//import java.util.Collections;
//import java.util.LinkedList;
//import java.util.List;
//import java.util.Queue;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	static int[] dx = {0,-1,0,1};
//	static int[] dy = {-1,0,1,0};
//	static int[][] board = new int[1001][1001];
//	static int[][] dist = new int[1001][1001];
//	static Queue<int[]> q = new LinkedList<>();
//	static int N,M;
//
//	static int bfs() {
//		while(!q.isEmpty()) {
//			int[] temp = q.poll();
//			int x = temp[0];
//			int y = temp[1];
//			for(int i=0;i<4;i++) {
//				int nx = x+dx[i];
//				int ny = y+dy[i];
//				if(nx>=0&&nx<N&&ny>=0&&ny<M&&dist[nx][ny]==-1) {
//					if(board[nx][ny]==0) {
//						q.offer(new int[] {nx,ny});
//						dist[nx][ny] = dist[x][y]+1;
//					}
//				}
//			}
//		}
//		int maxi = 0;
//		for(int i=0;i<N;i++) {
//			for(int j=0;j<M;j++) {
//				if(board[i][j]==0&&dist[i][j]==-1) return -1;
//				maxi = Math.max(maxi, dist[i][j]);
//			}
//		}
//		return maxi;
//	}
//
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		for(int i=0;i<dist.length;i++) {
//			Arrays.fill(dist[i], -1);
//		}
//
//		st = new StringTokenizer(br.readLine());
//		int m = Integer.parseInt(st.nextToken());
//		int n = Integer.parseInt(st.nextToken());
//		N=n;M=m;
//		for(int i=0;i<n;i++) {
//			st = new StringTokenizer(br.readLine());
//			for(int j=0;j<m;j++) {
//				board[i][j] = Integer.parseInt(st.nextToken());
//				if(board[i][j]==1) {
//					q.offer(new int[] {i,j});
//					dist[i][j] = 0;
//				}
//			}
//		}
//		int answer = bfs();
//		System.out.println(sb.append(answer+"\n"));
//	}
//}
//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Arrays;
//import java.util.Collections;
//import java.util.LinkedList;
//import java.util.List;
//import java.util.Queue;
//import java.util.StringTokenizer;
//
//public class Main {
//	
//	static int[] dx = {0,-1,0,1};
//	static int[] dy = {-1,0,1,0};
//	static int[][] board = new int[1001][1001];
//	static int[][] dist = new int[1001][1001];
//	static int N,M;
//	
//	static int bfs(List<int[]> temp) {
//		for(int i=0;i<N;i++) Arrays.fill(dist[i], -1);
//		Queue<int[]> q = new LinkedList<>();
//		for(int i=0;i<temp.size();i++) {
//			int x = temp.get(i)[0]; int y = temp.get(i)[1];
//			q.offer(new int[] {x,y});
//			dist[x][y] = 0;
//		}
//		while(!q.isEmpty()) {
//			int[] now = q.poll();
//			int x = now[0]; int y = now[1];
//			for(int i=0;i<4;i++) {
//				int nx = x+dx[i];
//				int ny = y+dy[i];
//				if(nx>=0&&nx<N&&ny>=0&&ny<M&&dist[nx][ny]==-1) {
//					if(board[nx][ny]==0) {
//						q.offer(new int[] {nx,ny});
//						dist[nx][ny] = dist[x][y]+1;
//					}
//				}
//			}
//		}
//		int maxi = -1;
//		for(int i=0;i<N;i++) {
//			for(int j=0;j<M;j++) {
//				if(board[i][j]!=-1) maxi = Math.max(maxi, dist[i][j]);
//				if(board[i][j]==0&&dist[i][j]==-1) return -1;
//			}
//		}
//		return maxi;
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
//		List<int[]> temp = new ArrayList<>();
//		for(int i=0;i<n;i++) {
//			st = new StringTokenizer(br.readLine());
//			for(int j=0;j<m;j++) {
//				board[i][j] = Integer.parseInt(st.nextToken());
//				if(board[i][j]==1) temp.add(new int[] {i,j});
//			}
//		}
//		System.out.println(sb.append(bfs(temp)));
//	}
//}
import java.io.*;
import java.util.*;

public class Main {
		
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] board = new int[1001][1001];
	static int[][] dist = new int[1001][1001];
	static List<int[]> a = new ArrayList<>();
	static int N,M;
	
	static int bfs() {
		Queue<int[]> q = new LinkedList<>();
		for(int i=0;i<a.size();i++) {
			int x = a.get(i)[0]; int y = a.get(i)[1];
			q.offer(new int[] {x,y});
			dist[x][y] = 1;
		}
		while(!q.isEmpty()) {
			int[] now = q.poll();
			int x = now[0]; int y = now[1];
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx>=0&&nx<N&&ny>=0&&ny<M&&dist[nx][ny]==0) {
					if(board[nx][ny]==0) {
						q.offer(new int[] {nx,ny});
						dist[nx][ny] = dist[x][y]+1;
					}
				}
			}
		}
		int maxi = -1;
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(board[i][j]!=-1&&dist[i][j]==0) return -1;
				maxi = Math.max(maxi, dist[i][j]);
			}
		}
		return maxi-1;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int m = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		N=n;M=m;
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<m;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				if(board[i][j]==1) {
					a.add(new int[] {i,j});
				}
			}
		}
		System.out.println(sb.append(bfs()));
	}
}
