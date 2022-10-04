//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.List;
//import java.util.StringTokenizer;
//
//public class Main {
//	
//	static int[] dx = {0,-1,0,1};
//	static int[] dy = {-1,0,1,0};
//	static int[][] dir = {{2},{0,2},{1,2},{0,1,2},{0,1,2,3}};
//	static int[][] board = new int[9][9];
//	static List<int[]> camera = new ArrayList<>();
//	static int mini = Integer.MAX_VALUE;
//	static int N,M;
//	
//	static int go(List<Integer> temp) {
//		int result = 0;
//		int[][] tmp_board = new int[N][M];
//		for(int i=0;i<N;i++) {
//			for(int j=0;j<M;j++) {
//				tmp_board[i][j] = board[i][j];
//			}
//		}
//		for(int i=0;i<camera.size();i++) {
//			int[] now = camera.get(i);
//			int x = now[0]; int y = now[1];
//			for(int j=0;j<dir[board[x][y]-1].length;j++) {
//				int k = dir[board[x][y]-1][j]-temp.get(i);
//				while(k>3) k-=4;
//				while(k<0) k+=4;
//				int nx = x+dx[k];
//				int ny = y+dy[k];
//				while(true) {
//					if(nx>=0&&nx<N&&ny>=0&&ny<M&&tmp_board[nx][ny]!=6) {
//						tmp_board[nx][ny] = -1;
//					} else break;
//					nx+=dx[k];
//					ny+=dy[k];
//				}
//			}
//		}
//		for(int i=0;i<N;i++) {
//			for(int j=0;j<M;j++) {
//				if(tmp_board[i][j]==0) result+=1;
//			}
//		}
//		return result;
//	}
// 	
//	static void dfs(List<Integer> temp, int limit) {
//		if(temp.size()==limit) {
//			int sum = go(temp);
//			mini = Math.min(mini, sum);
//			return;
//		}
//		for(int i=0;i<=3;i++) {
//			temp.add(i);
//			dfs(temp,limit);
//			temp.remove(temp.size()-1);
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
//			st = new StringTokenizer(br.readLine());
//			for(int j=0;j<m;j++) {
//				board[i][j] = Integer.parseInt(st.nextToken());
//				if(board[i][j]>=1&&board[i][j]<=5) {
//					camera.add(new int[] {i,j});
//				}
//			}
//		}
//		List<Integer> temp = new ArrayList<>();
//		dfs(temp,camera.size());
//		System.out.println(sb.append(mini));
//	}
//}
import java.io.*;
import java.util.*;

public class Main {
		
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] num = {{2},{0,2},{1,2},{0,1,2},{0,1,2,3}};
	static int[][] board = new int[9][9];
	static List<int[]> a = new ArrayList<>();
	static int mini = Integer.MAX_VALUE;
	static int N,M;
	
	static void cal(List<Integer> temp) {
		int result = 0;
		int[][] tmp_board = new int[N][M];
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) tmp_board[i][j] = board[i][j];
		}
		for(int i=0;i<a.size();i++) {
			int x=a.get(i)[0]; int y=a.get(i)[1]; int z=a.get(i)[2]-1;
			for(int j=0;j<num[z].length;j++) {
				int dir = (num[z][j]+temp.get(i))%4;
				int nx = x+dx[dir];
				int ny = y+dy[dir];
				while(nx>=0&&nx<N&&ny>=0&&ny<M&&tmp_board[nx][ny]!=6) {
					tmp_board[nx][ny] = '*';
					nx+=dx[dir];
					ny+=dy[dir];
				}
			}
		}
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(tmp_board[i][j]==0) result+=1;
			}
		}
		mini = Math.min(mini, result);
	}
	
	static void dfs(List<Integer> temp) { 
		if(temp.size()==a.size()) {
			cal(temp);
			return;
		}
		for(int i=0;i<4;i++) {
			temp.add(i);
			dfs(temp);
			temp.remove(temp.size()-1);
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		N=n;M=m;
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<m;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				if(board[i][j]!=0&&board[i][j]!=6) {
					a.add(new int[] {i,j,board[i][j]});
				}
			}
		}
		List<Integer> temp = new ArrayList<>();
		dfs(temp);
		System.out.println(sb.append(mini));
	}
}