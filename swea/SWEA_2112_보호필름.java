import java.util.*;
import java.io.*;

public class Solution {
	
	static int[][] board = new int[14][21];
	static int answer = 0;
	static int N,M,K;
	
	static boolean real_test(List<Integer> temp, List<Integer> temp2) {
		int[][] tmp_board = new int[N][M];
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) tmp_board[i][j] = board[i][j];
		}
		for(int i=0;i<temp.size();i++) {
			int idx = temp.get(i);
			int color = temp2.get(i);
			for(int j=0;j<M;j++) {
				tmp_board[idx][j] = color;
			}
		}
		for(int j=0;j<M;j++) {
			int cnt = 1;
			boolean flag = false;
			for(int i=1;i<N;i++) {
				if(tmp_board[i][j]==tmp_board[i-1][j]) cnt+=1;
				else cnt = 1;
				if(cnt==K) flag = true;
			}
			if(flag==false) return false;
		}
		return true;
	}
	
	static boolean test(List<Integer> temp) {
		int x = temp.size();
		for(int i=0;i<(1<<x);i++) {
			List<Integer> temp2 = new ArrayList<>();
			for(int j=0;j<x;j++) {
				if((i&(1<<j))!=0) temp2.add(1);
				else temp2.add(0);
			}
			if(real_test(temp,temp2)) return true;
		}
		return false;
	}
	
	static boolean dfs(List<Integer> temp, int x, int start) {
		if(temp.size()==x) {
			if(test(temp)) {
				return true;
			}
			return false;
		}
		for(int i=start;i<N;i++) {
			temp.add(i);
			if(dfs(temp,x,i+1)) return true;
			temp.remove(temp.size()-1);
		}
		return false;
	}
	
	static boolean cal(int x) {
		List<Integer> temp = new ArrayList<>();
		return dfs(temp,x,0);
	}
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("data/2112.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			int k = Integer.parseInt(st.nextToken());
			N=n;M=m;K=k;
			for(int i=0;i<n;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<m;j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			for(int i=0;i<n;i++) {
				if(cal(i)) {
					answer = i;
					break;
				}
			}
			sb.append("#"+(ot-t)+" "+answer+"\n");
			answer = 0;
		}
		System.out.println(sb);
	}
}
