import java.util.*;
import java.io.*;

public class Solution {
	
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] board = new int[9][9];
	static boolean[][] check = new boolean[9][9];
	static List<int[]> a = new ArrayList<>();
	static int answer = 0;
	static int N,M;
	
	static void dfs(int sx, int sy, int cnt, int dig) {
		boolean flag = false;
		for(int i=0;i<4;i++) {
			int nx = sx+dx[i];
			int ny = sy+dy[i];
			if(!(nx>=0&&nx<N&&ny>=0&&ny<N&&check[nx][ny]==false)) continue;
			if(board[nx][ny]<board[sx][sy]) {
				flag = true;
				check[nx][ny] = true;
				dfs(nx,ny,cnt+1,dig);
				check[nx][ny] = false;
			} else if(board[nx][ny]>=board[sx][sy]&&board[nx][ny]-board[sx][sy]<M&&dig==1) {
				flag = true;
				int temp = board[nx][ny];
				board[nx][ny] = board[sx][sy]-1;
				if(board[nx][ny]<0) board[nx][ny] = 0;
				check[nx][ny] = true;
				dfs(nx,ny,cnt+1,dig-1);
				check[nx][ny] = false;
				board[nx][ny] = temp;
			}
		}
		if(flag==false) {
			answer = Math.max(answer, cnt);
			return;
		}
	}
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("data/1949.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			N=n;M=m;
			int maxi = -1;
			for(int i=0;i<n;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<n;j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
					maxi = Math.max(maxi, board[i][j]);
				}
			}
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					if(board[i][j]==maxi) a.add(new int[] {i,j});
				}
			}
			for(int i=0;i<a.size();i++) {
				check[a.get(i)[0]][a.get(i)[1]] = true;
				dfs(a.get(i)[0],a.get(i)[1],1,1);
				check[a.get(i)[0]][a.get(i)[1]] = false;
			}
			sb.append("#"+(ot-t)+" "+answer+"\n");
			a.clear();
			answer = 0;
		}
		System.out.println(sb);
	}
}
