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
	
	static int[][] board = new int[3001][3001];
	static int one=0,two=0,three=0;
	
	static void dfs(int x ,int y, int n) {
		boolean flag = true;
		for(int i=x;i<x+n;i++) {
			for(int j=y;j<y+n;j++) {
				if(board[i][j]!=board[x][y]) flag = false; 
			}
		}
		if(flag==true) {
			if(board[x][y]==-1) one+=1;
			else if(board[x][y]==0) two+=1;
			else three+=1;
		} else {
			dfs(x,y,n/3);
			dfs(x,y+n/3,n/3);
			dfs(x,y+n/3+n/3,n/3);
			dfs(x+n/3,y,n/3);
			dfs(x+n/3,y+n/3,n/3);
			dfs(x+n/3,y+n/3+n/3,n/3);
			dfs(x+n/3+n/3,y,n/3);
			dfs(x+n/3+n/3,y+n/3,n/3);
			dfs(x+n/3+n/3,y+n/3+n/3,n/3);
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
	
		int n = Integer.parseInt(br.readLine());
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<n;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		dfs(0,0,n);
		sb.append(one+"\n"+two+"\n"+three);
		System.out.println(sb);
	} 
}
