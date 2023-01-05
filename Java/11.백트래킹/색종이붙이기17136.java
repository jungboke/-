// import java.io.*;
// import java.util.*;

// public class Main {
	
// 	static int[][] board = new int[10][10];
// 	static int[] sticker = new int[] {5,5,5,5,5};
// 	static int answer = Integer.MAX_VALUE;
	
// 	static boolean stickCheck(int x, int y, int k) {
// 		for(int i=x;i<x+k;i++) {
// 			for(int j=y;j<y+k;j++) {
// 				if(!(i>=0&&i<10&&j>=0&&j<10)) return false;
// 				if(board[i][j]==0) return false;
// 			}
// 		}
// 		return true;
// 	}
	
// 	static void stick(int x, int y, int k) {
// 		for(int i=x;i<x+k;i++) {
// 			for(int j=y;j<y+k;j++) {
// 				board[i][j] = 0;
// 			}
// 		}
// 	}
	
// 	static void unstick(int x, int y, int k) {
// 		for(int i=x;i<x+k;i++) {
// 			for(int j=y;j<y+k;j++) {
// 				board[i][j] = 1;
// 			}
// 		}
// 	}
	
// 	static void dfs(int x, int y, int cnt) {
// 		if(x==10) {
// 			answer = Math.min(answer, cnt);
// 			return;
// 		}
// 		if(y>9) {
// 			dfs(x+1,0,cnt);
// 			return;
// 		}
// 		if(board[x][y]==1) {
// 			for(int k=1;k<=5;k++) {
// 				if(sticker[k-1]>0&&stickCheck(x,y,k)) {
// 					sticker[k-1]-=1;
// 					stick(x,y,k);
// 					dfs(x,y+1,cnt+1);
// 					unstick(x,y,k);
// 					sticker[k-1]+=1;
// 				}
// 			}
// 		} else dfs(x,y+1,cnt);
// 	}
	
// 	public static void main(String[] args) throws IOException {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;
		
// 		for(int i=0;i<10;i++) {
// 			st = new StringTokenizer(br.readLine());
// 			for(int j=0;j<10;j++) {
// 				board[i][j] = Integer.parseInt(st.nextToken());
// 			}
// 		}
// 		dfs(0,0,0);
// 		if(answer==Integer.MAX_VALUE) answer = -1;
// 		System.out.println(sb.append(answer));
// 	}
// }
import java.io.*;
import java.util.*;

public class Main {
	
	static int[][] board = new int[10][10];
	static int[] sticker = new int[6];
	static int answer = Integer.MAX_VALUE;
	
	static boolean stickCheck(int x, int y, int l) {
		for(int i=0;i<l;i++) {
			for(int j=0;j<l;j++) {
				if(!(x+i>=0&&x+i<10&&y+j>=0&&y+j<10)) return false;
				if(board[x+i][y+j]==0) return false;
			}
		}
		return true;
	}
	
	static void stick(int x, int y, int l, boolean flag) {
		if(flag==true) {
			for(int i=0;i<l;i++) {
				for(int j=0;j<l;j++) {
					board[x+i][y+j] = 0;
				}
			}
		} else {
			for(int i=0;i<l;i++) {
				for(int j=0;j<l;j++) {
					board[x+i][y+j] = 1;
				}
			}
		}
	}
	
	static void dfs(int idx, int cnt) {
		int x = idx/10; int y = idx%10;
		if(idx==100) {
			boolean flag = true;
			for(int i=0;i<10;i++) {
				for(int j=0;j<10;j++) {
					if(board[i][j]==1) flag = false;
				}
			}
			if(flag==true) {
				answer = Math.min(answer, cnt);
			}
			return;
		}
		if(board[x][y]==0) dfs(idx+1,cnt);
		else {
			for(int i=1;i<=5;i++) {
				if(stickCheck(x,y,i)&&sticker[i]<5) {
					sticker[i]+=1;
					stick(x,y,i,true);
					dfs(idx+1,cnt+1);
					stick(x,y,i,false);
					sticker[i]-=1;
				}
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		for(int i=0;i<10;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<10;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		dfs(0,0);
		if(answer==Integer.MAX_VALUE) answer = -1;
		System.out.println(sb.append(answer));
	}
}
