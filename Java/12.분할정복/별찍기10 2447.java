import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int[][] board = new int[5001][5001];
	
	static void dfs(int x, int y, int n) {
		if(n==1) {
			board[x][y] = 1;
			return;
		}
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				if(i==1&&j==1) continue;
				dfs(x+(n/3)*i,y+(n/3)*j,n/3);
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		dfs(0,0,n);
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(board[i][j]==1) sb.append("*");
				else sb.append(" ");
			}
			sb.append("\n");
		}
		System.out.println(sb);
	} 
}
