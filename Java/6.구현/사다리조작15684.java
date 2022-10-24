import java.io.*;
import java.util.*;

public class Main {

	static int[][] board = new int[50][50];
	static boolean flag = false;
	static int answer = Integer.MAX_VALUE;
	static int N,M,H;
	
	static boolean ladder_check() {
		for(int i=1;i<=N;i++) {
			int now = i;
			for(int j=1;j<=H;j++) {
				if(now>1&&now<N) {
					if(board[now][j]==1) now += 1;
					else if(board[now-1][j]==1) now-=1;
				} else if(now==N&&board[now-1][j]==1) {
					now -= 1;
				} else if(now==1&&board[now][j]==1) {
					now += 1;
				}
			}
			if(now!=i) return false;
		}
		return true;
	}
	
	static void dfs(int cnt, int target) {
		if(flag==true) return;
		if(cnt==target) {
			if(ladder_check()) {
				answer = target;
				flag = true;
			}
			return;
		}
		for(int i=1;i<=H;i++) {
			for(int j=1;j<N;j++) {
				if(board[j][i]==0&&board[j+1][i]==0&&board[j-1][i]==0) {
					board[j][i] = 1;
					dfs(cnt+1,target);
					board[j][i] = 0;					
				}
			}
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int h = Integer.parseInt(st.nextToken());
		N=n;M=m;H=h;
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			board[y][x] = 1;
		}
		for(int i=0;i<=3;i++) {
			dfs(0,i);
			if(flag==true) break;
		}
		if(answer==Integer.MAX_VALUE) answer = -1;
		System.out.println(sb.append(answer));
	}
}
