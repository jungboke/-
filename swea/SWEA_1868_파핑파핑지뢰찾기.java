import java.io.*;
import java.util.*;

public class Solution {
	
	static int[] dx = {0,-1,-1,-1,0,1,1,1};
	static int[] dy = {-1,-1,0,1,1,1,0,-1};
	static char[][] board = new char[301][301];
	static boolean[][] check = new boolean[301][301];
	static int N;
	
	static boolean around_check(int x, int y) {
		for(int i=0;i<8;i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx>=0&nx<N&&ny>=0&&ny<N) {
				if(board[nx][ny]=='*') return false;
			}
		}
		return true;
	}
	
	static void bfs(int sx, int sy) {
		Queue<int[]> q = new LinkedList<>();
		q.offer(new int[] {sx,sy});
		check[sx][sy] = true;
		while(!q.isEmpty()) {
			int[] now = q.poll();
			int x = now[0]; int y = now[1];
			for(int i=0;i<8;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx>=0&&nx<N&&ny>=0&&ny<N&&check[nx][ny]==false) {
					check[nx][ny] = true;
					if(around_check(nx,ny)) {
						q.offer(new int[] {nx,ny});
					}
				}
			}
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("data/1868.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
			int n = Integer.parseInt(br.readLine());
			N=n;
			for(int i=0;i<n;i++) {
				String temp = br.readLine();
				for(int j=0;j<n;j++) {
					board[i][j] = temp.charAt(j);
				}
			}
			int answer = 0;
			for(int i=0;i<n;i++) {
				outer:for(int j=0;j<n;j++) {
					if(board[i][j]=='*'||check[i][j]==true) continue;
					for(int k=0;k<8;k++) {
						int nx = i+dx[k];
						int ny = j+dy[k];
						if(nx>=0&&nx<n&&ny>=0&&ny<n) {
							if(board[nx][ny]=='*') continue outer;
						}
					}
					bfs(i,j);
					answer+=1;
				}
			}
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					if(board[i][j]=='.'&&check[i][j]==false) {
						answer+=1;
					}
				}
			}
			sb.append("#"+(ot-t)+" "+answer+"\n");
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) check[i][j] = false;
			}
		}
		System.out.println(sb);
	}
}
