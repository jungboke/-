import java.io.*;
import java.util.*;

public class Main {

	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] board = new int[9][9];
	static boolean[][] check = new boolean[9][9];
	static List<int[]> a = new ArrayList<>();
	static List<int[]> virus = new ArrayList<>();
	static int N,M;
	static int maxi = -1;

	static void cal(List<int[]> temp) {
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) check[i][j] = false;
		}
		int[][] tmp_board = new int[N][M];
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) tmp_board[i][j] = board[i][j];
		}
		for(int i=0;i<temp.size();i++) {
			int x = temp.get(i)[0]; int y = temp.get(i)[1];
			tmp_board[x][y] = 1;
		}
		Queue<int[]> q = new LinkedList<>();
		for(int i=0;i<virus.size();i++) {
			int x = virus.get(i)[0]; int y = virus.get(i)[1];
			q.offer(new int[] {x,y});
			check[x][y] = true;
		}
		while(!q.isEmpty()) {
			int[] now = q.poll();
			int x = now[0]; int y = now[1];
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx>=0&&nx<N&&ny>=0&&ny<M&&check[nx][ny]==false) {
					if(tmp_board[nx][ny]!=1) {
						q.offer(new int[] {nx,ny});
						check[nx][ny] = true;
					}
				}
			}
		}
		int result = 0;
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(tmp_board[i][j]==0&&check[i][j]==false) result+=1;
			}
		}
		maxi = Math.max(maxi, result);
	}

	static void dfs(List<int[]> temp, int start) {
		if(temp.size()==3) {
			cal(temp);
			return;
		}
		for(int i=start;i<a.size();i++) {
			temp.add(a.get(i));
			dfs(temp,i+1);
			temp.remove(temp.size()-1);
		}
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
				if(board[i][j]==0) a.add(new int[] {i,j});
				else if(board[i][j]==2) virus.add(new int[] {i,j});
			}
		}
		List<int[]> temp = new ArrayList<>();
		dfs(temp,0);
		System.out.println(sb.append(maxi));
	}
}
