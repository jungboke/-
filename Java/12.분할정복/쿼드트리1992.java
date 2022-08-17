import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	
	static int[][] board = new int[65][65];
	
	static void dfs(int px, int py, int n) {
		boolean flag = true;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(board[px+i][py+j]!=board[px][py]) {
					flag = false;
				}
			}
		}
		if(flag==true) {
			if(board[px][py]==0) System.out.print("0");
			else System.out.print("1");
		} else {
			System.out.print("(");
			dfs(px,py,n/2);
			dfs(px,py+n/2,n/2);
			dfs(px+n/2,py,n/2);
			dfs(px+n/2,py+n/2,n/2);
			System.out.print(")");
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		for(int i=0;i<n;i++) {
			String temp = br.readLine();
			for(int j=0;j<n;j++) {
				board[i][j] = temp.charAt(j)-'0';
			}
		}
		dfs(0,0,n);
	}
}