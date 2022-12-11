import java.io.*;
import java.util.*;

public class Main {
	
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] board = new int[100][100];
	static boolean[][] check = new boolean[100][100];
	static int K;
	
	static void real_rotate(int x, int y, int l) {
		int[][] tmp_board = new int[K][K];
		for(int i=0;i<l;i++) {
			for(int j=0;j<l;j++) {
				tmp_board[x+j][y+l-i-1] = board[x+i][y+j];
			}
		}
		for(int i=x;i<x+l;i++) {
			for(int j=y;j<y+l;j++) board[i][j] = tmp_board[i][j];
		}
	}
	
	static void rotate(int x) {
		int l = (int) Math.pow(2, x);
		for(int i=0;i<K;i+=l) {
			for(int j=0;j<K;j+=l) {
				real_rotate(i,j,l);
			}
		}
	}
	
	static void melt() {
		int[][] tmp_board = new int[K][K];
		for(int i=0;i<K;i++) {
			for(int j=0;j<K;j++) {
				if(board[i][j]==0) continue;
				int cnt = 0;
				for(int c=0;c<4;c++) {
					int nx = i+dx[c];
					int ny = j+dy[c];
					if(nx>=0&&nx<K&&ny>=0&&ny<K&&board[nx][ny]!=0) {
						cnt+=1;
					}
				}
				if(cnt<3) tmp_board[i][j]-=1;
			}
		}
		for(int i=0;i<K;i++) {
			for(int j=0;j<K;j++) board[i][j]+=tmp_board[i][j];
		}
	}
	
	static int bfs(int px, int py) {
		Queue<int[]> q = new LinkedList<>();
		q.offer(new int[] {px,py});
		check[px][py] = true;
		int cnt = 1;
		while(!q.isEmpty()) {
			int[] now = q.poll();
			int x = now[0]; int y = now[1];
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx>=0&&nx<K&&ny>=0&&ny<K&&check[nx][ny]==false) {
					if(board[nx][ny]!=0) {
						q.offer(new int[] {nx,ny});
						check[nx][ny] = true;
						cnt+=1;
					}
				}
			}
		}
		return cnt;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int k = (int) Math.pow(2,n);
		K=k;
		for(int i=0;i<k;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<k;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<m;i++) {
			int x = Integer.parseInt(st.nextToken());
			rotate(x);
			melt();
		}
		int answer1 = 0;
		for(int i=0;i<k;i++) {
			for(int j=0;j<k;j++) {
				if(board[i][j]!=0) answer1+=board[i][j];
			}
		}
		int answer2 = 0;
		for(int i=0;i<k;i++) {
			for(int j=0;j<k;j++) {
				if(board[i][j]!=0&&check[i][j]==false) {
					int sum = bfs(i,j);
					answer2 = Math.max(answer2, sum);
				}
			}
		}
		System.out.println(sb.append(answer1+"\n"+answer2));
	} 
}
