import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static char[][] board = new char[21][21];
	static boolean[][] check = new boolean[21][21];
	static boolean[] alpha = new boolean[30];
	static int N,M;
	static int answer = -1;


	static void dfs(int x ,int y, int cnt) {
		alpha[board[x][y]-'A'] = true;
		check[x][y] = true;
		boolean flag = false;
		for(int i=0;i<4;i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx>=0&&nx<N&&ny>=0&&ny<M&&check[nx][ny]==false) {
				if(alpha[board[nx][ny]-'A']==false) {
					flag = true;
					dfs(nx,ny,cnt+1);
				}
			}
		}
		check[x][y] = false;
		alpha[board[x][y]-'A'] = false;
		if(flag==false) {
			answer = Math.max(answer, cnt);
			return;
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
			String temp = br.readLine();
			for(int j=0;j<m;j++) {
				board[i][j] = temp.charAt(j);
			}
		}
		dfs(0,0,1);
		System.out.println(sb.append(answer));
	}
}
