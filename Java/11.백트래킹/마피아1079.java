import java.io.*;
import java.util.*;

public class Main {
	
	static int[][] board = new int[17][17];
	static int[] gp = new int[17];
	static boolean[] check = new boolean[17];
	static int answer = 0;
	static int N,K;
	
	
	static void dfs(int cnt, int day) {
		if(cnt%2==0) {
			if(cnt==2) {
				answer = Math.max(answer, day+1);
				return;
			}
			for(int i=0;i<N;i++) {
				if(i==K) continue;
				if(check[i]==true) continue;
				check[i] = true;
				for(int j=0;j<N;j++) {
					gp[j]+=board[i][j];
				}
				dfs(cnt-1,day+1);
				for(int j=0;j<N;j++) {
					gp[j]-=board[i][j];
				}
				check[i] = false;
			}
		} else {
			int maxi = Integer.MIN_VALUE;
			int max_idx = -1;
			for(int i=0;i<N;i++) {
				if(check[i]==true) continue;
				if(gp[i]>maxi) {
					maxi = gp[i];
					max_idx = i;
				}
			}
			if(max_idx==K) {
				answer = Math.max(answer, day);
				return;
			}
			check[max_idx] = true;
			dfs(cnt-1,day);
			check[max_idx] = false;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		N=n;
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			gp[i] = Integer.parseInt((st.nextToken()));
		}
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<n;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		int k = Integer.parseInt(br.readLine());
		K=k;
		dfs(n,0);
		System.out.println(sb.append(answer));
	} 
}
