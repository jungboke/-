import java.util.*;
import java.io.*;

public class Solution {
	
	static int[][] board = new int[21][21];
	static int answer = 0;
	static int N,M;
	
	static int[] cal(int sx, int sy, int cnt) {
		int cost = 0;
		int home = 0;
		for(int i=0;i<cnt;i++) {
			for(int j=0;j<2*i+1;j++) {
				cost-=1;
				int nx = sx-(cnt-1)+i;
				int ny = sy-i+j;
				if(!(nx>=0&&nx<N&&ny>=0&&ny<N)) continue;
				if(board[nx][ny]==1) {
					cost+=M;
					home+=1;
				}
			}
		}
		for(int i=0;i<cnt-1;i++) {
			for(int j=0;j<2*i+1;j++) {
				cost-=1;
				int nx = sx+(cnt-1)-i;
				int ny = sy-i+j;
				if(!(nx>=0&&nx<N&&ny>=0&&ny<N)) continue;
				if(board[nx][ny]==1) {
					cost+=M;
					home+=1;
				}
			}
		}
		return new int[] {cost,home};
	}
	
	static void checkBoard(int cnt) {
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				int[] temp = cal(i,j,cnt);
				if(temp[0]>=0) answer = Math.max(answer, temp[1]);
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("data/2117.txt"));
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
			for(int i=0;i<n;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<n;j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			int cnt = 1;
			while(cnt<=2*N) {
				checkBoard(cnt);
				cnt+=1;
			}
			sb.append("#"+(ot-t)+" "+answer+"\n");
			answer = 0;
		}
		System.out.println(sb);
	}
}
