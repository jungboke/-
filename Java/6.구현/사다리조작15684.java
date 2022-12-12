//import java.io.*;
//import java.util.*;
//
//public class Main {
//
//	static int[][] board = new int[50][50];
//	static boolean flag = false;
//	static int answer = Integer.MAX_VALUE;
//	static int N,M,H;
//	
//	static boolean ladder_check() {
//		for(int i=1;i<=N;i++) {
//			int now = i;
//			for(int j=1;j<=H;j++) {
//				if(now>1&&now<N) {
//					if(board[now][j]==1) now += 1;
//					else if(board[now-1][j]==1) now-=1;
//				} else if(now==N&&board[now-1][j]==1) {
//					now -= 1;
//				} else if(now==1&&board[now][j]==1) {
//					now += 1;
//				}
//			}
//			if(now!=i) return false;
//		}
//		return true;
//	}
//	
//	static void dfs(int cnt, int target) {
//		if(flag==true) return;
//		if(cnt==target) {
//			if(ladder_check()) {
//				answer = target;
//				flag = true;
//			}
//			return;
//		}
//		for(int i=1;i<=H;i++) {
//			for(int j=1;j<N;j++) {
//				if(board[j][i]==0&&board[j+1][i]==0&&board[j-1][i]==0) {
//					board[j][i] = 1;
//					dfs(cnt+1,target);
//					board[j][i] = 0;					
//				}
//			}
//		}
//	}
//	
//	public static void main(String[] args) throws NumberFormatException, IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		st = new StringTokenizer(br.readLine());
//		int n = Integer.parseInt(st.nextToken());
//		int m = Integer.parseInt(st.nextToken());
//		int h = Integer.parseInt(st.nextToken());
//		N=n;M=m;H=h;
//		for(int i=0;i<m;i++) {
//			st = new StringTokenizer(br.readLine());
//			int x = Integer.parseInt(st.nextToken());
//			int y = Integer.parseInt(st.nextToken());
//			board[y][x] = 1;
//		}
//		for(int i=0;i<=3;i++) {
//			dfs(0,i);
//			if(flag==true) break;
//		}
//		if(answer==Integer.MAX_VALUE) answer = -1;
//		System.out.println(sb.append(answer));
//	}
//}
import java.io.*;
import java.util.*;

public class Main {
	
	static int[][] board = new int[31][11];
	static int answer = -1;
	static int N,H;
	
	static boolean ladder_check() {
		for(int j=1;j<=N;j++) {
			int now = j;
			for(int i=1;i<=H;i++) {
				if(board[i][now]==1) now+=1;
				else if(board[i][now-1]==1) now-=1;
			}
			if(now!=j) return false;
		}
		return true;
	}
	
	static boolean dfs(int cnt, int limit) {
		if(cnt==limit) {
			if(ladder_check()) {
				return true;
			} else return false;
		}
		for(int j=1;j<N;j++) {
			for(int i=1;i<=H;i++) {
				if(!(board[i][j-1]==0&&board[i][j]==0&&board[i][j+1]==0)) continue;
				board[i][j] = 1;
				if(dfs(cnt+1,limit)) return true;
				board[i][j] = 0;
			}
		}
		return false;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		N=n;
		int m = Integer.parseInt(st.nextToken());
		int h = Integer.parseInt(st.nextToken());
		H=h;
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			board[x][y] = 1;
		}
		for(int i=0;i<=3;i++) {
			if(dfs(0,i)) {
				answer = i;
				break;
			}
		}
		System.out.println(sb.append(answer));
	}
}

