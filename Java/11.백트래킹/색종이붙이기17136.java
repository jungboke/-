import java.io.*;
import java.util.*;

public class Main {
	
	static int[][] board = new int[10][10];
	static int[] sticker = new int[] {5,5,5,5,5};
	static int answer = Integer.MAX_VALUE;
	
	static boolean stickCheck(int x, int y, int k) {
		for(int i=x;i<x+k;i++) {
			for(int j=y;j<y+k;j++) {
				if(!(i>=0&&i<10&&j>=0&&j<10)) return false;
				if(board[i][j]==0) return false;
			}
		}
		return true;
	}
	
	static void stick(int x, int y, int k) {
		for(int i=x;i<x+k;i++) {
			for(int j=y;j<y+k;j++) {
				board[i][j] = 0;
			}
		}
	}
	
	static void unstick(int x, int y, int k) {
		for(int i=x;i<x+k;i++) {
			for(int j=y;j<y+k;j++) {
				board[i][j] = 1;
			}
		}
	}
	
	static void dfs(int x, int y, int cnt) {
		if(x==10) {
			answer = Math.min(answer, cnt);
			return;
		}
		if(y>9) {
			dfs(x+1,0,cnt);
			return;
		}
		if(board[x][y]==1) {
			for(int k=1;k<=5;k++) {
				if(sticker[k-1]>0&&stickCheck(x,y,k)) {
					sticker[k-1]-=1;
					stick(x,y,k);
					dfs(x,y+1,cnt+1);
					unstick(x,y,k);
					sticker[k-1]+=1;
				}
			}
		} else dfs(x,y+1,cnt);
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		for(int i=0;i<10;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<10;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		dfs(0,0,0);
		if(answer==Integer.MAX_VALUE) answer = -1;
		System.out.println(sb.append(answer));
	}
}