// import java.io.*;
// import java.util.*;

// public class Main {
	
// 	static int[][] board = new int[17][17];
// 	static int[] gp = new int[17];
// 	static boolean[] check = new boolean[17];
// 	static int answer = 0;
// 	static int N,K;
	
	
// 	static void dfs(int cnt, int day) {
// 		if(cnt%2==0) {
// 			if(cnt==2) {
// 				answer = Math.max(answer, day+1);
// 				return;
// 			}
// 			for(int i=0;i<N;i++) {
// 				if(i==K) continue;
// 				if(check[i]==true) continue;
// 				check[i] = true;
// 				for(int j=0;j<N;j++) {
// 					gp[j]+=board[i][j];
// 				}
// 				dfs(cnt-1,day+1);
// 				for(int j=0;j<N;j++) {
// 					gp[j]-=board[i][j];
// 				}
// 				check[i] = false;
// 			}
// 		} else {
// 			int maxi = Integer.MIN_VALUE;
// 			int max_idx = -1;
// 			for(int i=0;i<N;i++) {
// 				if(check[i]==true) continue;
// 				if(gp[i]>maxi) {
// 					maxi = gp[i];
// 					max_idx = i;
// 				}
// 			}
// 			if(max_idx==K) {
// 				answer = Math.max(answer, day);
// 				return;
// 			}
// 			check[max_idx] = true;
// 			dfs(cnt-1,day);
// 			check[max_idx] = false;
// 		}
// 	}
	
// 	public static void main(String[] args) throws NumberFormatException, IOException {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;
		
// 		int n = Integer.parseInt(br.readLine());
// 		N=n;
// 		st = new StringTokenizer(br.readLine());
// 		for(int i=0;i<n;i++) {
// 			gp[i] = Integer.parseInt((st.nextToken()));
// 		}
// 		for(int i=0;i<n;i++) {
// 			st = new StringTokenizer(br.readLine());
// 			for(int j=0;j<n;j++) {
// 				board[i][j] = Integer.parseInt(st.nextToken());
// 			}
// 		}
// 		int k = Integer.parseInt(br.readLine());
// 		K=k;
// 		dfs(n,0);
// 		System.out.println(sb.append(answer));
// 	} 
// }
import java.io.*;
import java.util.*;

public class Main {
	
	static int[] point = new int[17];
	static int[][] a = new int[17][17];
	static boolean[] check = new boolean[17];
	static int answer = Integer.MIN_VALUE;
	static int N,M;
	
	static void kill(int x, boolean flag) {
		if(flag==true) {
			for(int i=0;i<N;i++) {
				point[i]+=a[x][i];
			}
		} else {
			for(int i=0;i<N;i++) {
				point[i]-=a[x][i];
			}
		}
	}
	
	static void dfs(int cnt, int day) {
		if(cnt%2==0) {
			if(cnt==2) {
				answer = Math.max(answer, day+1);
				return;
			}
			for(int i=0;i<N;i++) {
				if(i==M) continue;
				if(check[i]==true) continue;
				check[i] = true;
				kill(i,true);
				dfs(cnt-1,day+1);
				kill(i,false);
				check[i] = false;
			}			
		} else {
			int maxi = Integer.MIN_VALUE;
			int max_num = -1;
			for(int i=0;i<N;i++) {
				if(check[i]==true) continue;
				if(maxi<point[i]) {
					maxi = point[i];
					max_num = i;
				}
			}
			if(max_num==M) {
				answer = Math.max(answer, day);
				return;
			}
			check[max_num] = true;
			dfs(cnt-1,day);
			check[max_num] = false;
		}
		
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		N=n;
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			point[i] = Integer.parseInt(st.nextToken());
		}
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<n;j++) {
				a[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		int m = Integer.parseInt(br.readLine());
		M=m;
		dfs(n,0);
		System.out.println(sb.append(answer));
	}
}

