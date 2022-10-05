import java.io.*;
import java.util.*;

public class Main {

	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] board = new int[101][101];
	static boolean[][] check = new boolean[101][101];
	static int N,M;

	static int bfs() {
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) check[i][j] = false;
		}
		int prev_cnt = 0;
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(board[i][j]==1) prev_cnt+=1;
			}
		}
		Queue<int[]> q = new LinkedList<>();
		q.offer(new int[] {0,0});
		check[0][0] = true;
		while(!q.isEmpty()) {
			int[] now = q.poll();
			int x = now[0]; int y = now[1];
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx>=0&&nx<N&&ny>=0&&ny<M&&check[nx][ny]==false) {
					if(board[nx][ny]==0) {
						q.offer(new int[] {nx,ny});
						check[nx][ny] = true;
					}
				}
			}
		}
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(board[i][j]!=1) continue;
				for(int k=0;k<4;k++) {
					int nx = i+dx[k];
					int ny = j+dy[k];
					if(nx>=0&&nx<N&&ny>=0&&ny<M&&check[nx][ny]==true) {
						board[i][j] = 0;
						break;
					}
				}
			}
		}
		boolean flag = true;
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(board[i][j]!=0) flag = false;
			}
		}
		if(flag==true) return prev_cnt;
		else return -1;
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		N=n;M=m;
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<m;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		int time = 0;
		int answer = 0;
		while(true) {
			answer = bfs();
			time+=1;
			if(answer!=-1) break;
		}
		System.out.println(sb.append(time+"\n"+answer));
	}
}
