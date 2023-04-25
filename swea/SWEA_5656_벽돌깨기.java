import java.util.*;
import java.io.*;

public class Solution {
	
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] board = new int[16][13];
	static int[][] tmp_board = new int[16][13];
	static int answer = Integer.MAX_VALUE;
	static int N,M,K;
	
	static void tearDown() {
		for(int i=1;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(tmp_board[i][j]!=0) continue;
				for(int k=i;k>0;k--) {
					int temp = tmp_board[k][j];
					tmp_board[k][j] = tmp_board[k-1][j];
					tmp_board[k-1][j] = temp;
				}
			}
		}
	}
	
	static void blockBreak(int x, int y, int cnt) {
		for(int i=0;i<4;i++) {
			int nx = x-dx[i]; int ny = y-dy[i];
			for(int j=0;j<cnt;j++) {
				nx+=dx[i]; ny+=dy[i];
				if(!(nx>=0&&nx<N&&ny>=0&&ny<M)) continue;
				if(tmp_board[nx][ny]!=0) {
					int how = tmp_board[nx][ny];
					tmp_board[nx][ny] = 0;
					blockBreak(nx,ny,how);
				}
			}
		}
	}
	
	static void cal(List<Integer> temp) {
		for(int i=0;i<temp.size();i++) {
			int x = temp.get(i);
			for(int j=0;j<N;j++) {
				if(tmp_board[j][x]!=0) {
					blockBreak(j,x,tmp_board[j][x]);
					break;
				}
			}
			tearDown();
		}
	}
	
	static void dfs(List<Integer> temp) {
		if(temp.size()==K) {
			for(int i=0;i<N;i++) {
				for(int j=0;j<M;j++) tmp_board[i][j] = board[i][j];
			}
			cal(temp);
			int result = 0;
			for(int i=0;i<N;i++) {
				for(int j=0;j<M;j++) {
					if(tmp_board[i][j]!=0) result+=1;
				}
			}
			answer = Math.min(answer, result);
			return;
		}
		for(int i=0;i<M;i++) {
			temp.add(i);
			dfs(temp);
			temp.remove(temp.size()-1);
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
			st = new StringTokenizer(br.readLine());
			int k = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			int n = Integer.parseInt(st.nextToken());
			N=n;M=m;K=k;
			for(int i=0;i<n;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<m;j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			List<Integer> temp = new ArrayList<>();
			dfs(temp);
			sb.append("#"+(ot-t)+" "+answer+"\n");
			answer = Integer.MAX_VALUE;
		}
		System.out.println(sb);
	}
}
