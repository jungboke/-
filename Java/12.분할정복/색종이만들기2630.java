import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int[][] board = new int[150][150];
	static int white = 0;
	static int blue = 0;

	static void dfs(int px, int py, int n) {
		boolean flag = true;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(board[px+i][py+j]!=board[px][py]) {
					flag = false;
				}
			}
		}
		if(flag==false) {
			dfs(px,py,n/2);
			dfs(px+n/2,py,n/2);
			dfs(px+n/2,py+n/2,n/2);
			dfs(px,py+n/2,n/2);
		} else {
			if(board[px][py]==1) blue+=1;
			else white+=1;
			return;
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
		System.out.println(sb.append(white+"\n"+blue));
	}
}
