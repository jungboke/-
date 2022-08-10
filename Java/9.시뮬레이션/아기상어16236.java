import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] board = new int[21][21];
	static int[][] dist = new int[21][21];
	static int sx,sy;
	static int N;

	static int move(int level) {
		for(int i=0;i<dist.length;i++) Arrays.fill(dist[i], Integer.MAX_VALUE);
		Queue<int[]> q = new LinkedList<>();
		q.add(new int[] {sx,sy});
		dist[sx][sy] = 0;
		while(!q.isEmpty()) {
			int[] now = q.poll();
			int x = now[0]; int y = now[1];
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx>=0&&nx<N&&ny>=0&&ny<N&&dist[nx][ny]==Integer.MAX_VALUE) {
					if(board[nx][ny]<=level) {
						q.add(new int[] {nx,ny});
						dist[nx][ny] = dist[x][y]+1;
					}
				}
			}
		}
		int mini = Integer.MAX_VALUE;
		int mx = -1; int my = -1;
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(dist[i][j]<mini&&board[i][j]<level&&board[i][j]!=0) {
					mini = dist[i][j];
					mx = i;
					my = j;
				}
			}
		}
		if(mx==-1&&my==-1) return 0;
		else {
			board[mx][my] = 0;
			sx = mx;
			sy = my;
			return mini;
		}

	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		int n = Integer.parseInt(br.readLine());
		N=n;
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<n;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				if(board[i][j]==9) {
					sx = i;
					sy = j;
					board[i][j] = 0;
				}
			}
		}
		int answer = 0;
		int level = 2;
		int cnt = 0;
		while(true) {
			int time = move(level);
			if(time==0) {
				break;
			}
			answer+=time;
			cnt+=1;
			if(cnt==level) {
				level+=1;
				cnt=0;
			}
		}
		System.out.println(sb.append(answer));
	}
}
