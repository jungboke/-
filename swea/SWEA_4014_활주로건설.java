import java.util.*;
import java.io.*;

public class Solution {
	
	static int[][] board = new int[21][21];
	static int answer = 0;
	static int N,M;
	
	static boolean list_check(List<int[]> temp) {
		for(int i=0;i<temp.size()-1;i++) {
			int x_value = temp.get(i)[0]; int y_value = temp.get(i+1)[0];
			int x_cnt = temp.get(i)[1]; int y_cnt = temp.get(i+1)[1];
			if(Math.abs(x_value-y_value)>1) return false;
			if(x_value<y_value) {
				if(x_cnt<M) return false;
				temp.set(i, new int[] {x_value,x_cnt-M});
			} else if(x_value>y_value) {
				if(y_cnt<M) return false;
				temp.set(i+1, new int[] {y_value,y_cnt-M});
			}
		}
		return true;
	}
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("data/4014.txt"));
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
			for(int i=0;i<n;i++) {
				int cnt = 1;
				List<int[]> temp = new ArrayList<>();
				for(int j=1;j<n;j++) {
					if(board[i][j]==board[i][j-1]) cnt+=1;
					else {
						temp.add(new int[] {board[i][j-1],cnt});
						cnt = 1;
					}
				}
				temp.add(new int[] {board[i][n-1],cnt});
				if(list_check(temp)) answer+=1;
			}
			for(int j=0;j<n;j++) {
				int cnt = 1;
				List<int[]> temp = new ArrayList<>();
				for(int i=1;i<n;i++) {
					if(board[i][j]==board[i-1][j]) cnt+=1;
					else {
						temp.add(new int[] {board[i-1][j],cnt});
						cnt = 1;
					}
				}
				temp.add(new int[] {board[n-1][j],cnt});
				if(list_check(temp)) answer+=1;
			}
			sb.append("#"+(ot-t)+" "+answer+"\n");
			answer = 0;
		}
		System.out.println(sb);
	}
}
