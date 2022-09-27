//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.List;
//import java.util.StringTokenizer;
//
//public class Main {
//	
//	static int[][] board = new int[51][51];
//	static List<int[]> info = new ArrayList<>();
//	static boolean[] check = new boolean[7];
//	static int N,M;
//	static int mini = Integer.MAX_VALUE;
//	
//	static int cal_board(int[][] temp) {
//		int result = Integer.MAX_VALUE;
//		for(int i=0;i<N;i++) {
//			int sum = 0;
//			for(int j=0;j<M;j++) {
//				sum += temp[i][j];
//			}
//			result = Math.min(result, sum);
//		}
//		return result;
//	}
//	
//	static void rotate(int[][] temp, int r, int c, int s) {
//		int[][] tmp_board = new int[N][M];
//		int sx = r-s-1; int sy = c-s-1;
//		int ex = r+s-1; int ey = c+s-1;
//		int col = ex-sx+1;
//		int row = ey-sy+1;
//		while(col>0&&row>0) {
//			for(int i=sx;i<sx+col-1;i++) {
//				tmp_board[i][sy] = temp[i+1][sy];
//			}
//			for(int j=sy;j<sy+row-1;j++) {
//				tmp_board[sx+col-1][j] = temp[sx+col-1][j+1];
//			}
//			for(int i=sx+col-1;i>sx;i--) {
//				tmp_board[i][sy+row-1] = temp[i-1][sy+row-1];
//			}
//			for(int j=sy+row-1;j>sy;j--) {
//				tmp_board[sx][j] = temp[sx][j-1];
//			}
//			sx+=1;
//			sy+=1;
//			col-=2;
//			row-=2;
//		}
//		for(int i=0;i<N;i++) {
//			for(int j=0;j<M;j++) {
//				if(tmp_board[i][j]==0) continue;
//				temp[i][j] = tmp_board[i][j];
//			}
//		}
//	}
//	
//	static void dfs(List<Integer> temp, int limit) {
//		if(temp.size()==limit) {
//			int[][] tmp_board = new int[N][M];
//			for(int i=0;i<N;i++) {
//				for(int j=0;j<M;j++) {
//					tmp_board[i][j] = board[i][j];
//				}
//			}
//			for(int i=0;i<temp.size();i++) {
//				int[] now = info.get(temp.get(i));
//				rotate(tmp_board,now[0],now[1],now[2]);
//			}
//			mini = Math.min(mini, cal_board(tmp_board));
//			return;
//		}
//		for(int i=0;i<info.size();i++) {
//			if(check[i]==true) continue;
//			check[i] = true;
//			temp.add(i);
//			dfs(temp,limit);
//			temp.remove(temp.size()-1);
//			check[i] = false;
//		}
//	}
//	
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		st = new StringTokenizer(br.readLine());
//		int n = Integer.parseInt(st.nextToken());
//		int m = Integer.parseInt(st.nextToken());
//		N=n;M=m;
//		int k = Integer.parseInt(st.nextToken());
//		for(int i=0;i<n;i++) {
//			st = new StringTokenizer(br.readLine());
//			for(int j=0;j<m;j++) {
//				board[i][j] = Integer.parseInt(st.nextToken());
//			}
//		}
//		for(int i=0;i<k;i++) {
//			st = new StringTokenizer(br.readLine());
//			int x = Integer.parseInt(st.nextToken());
//			int y = Integer.parseInt(st.nextToken());
//			int z = Integer.parseInt(st.nextToken());
//			info.add(new int[] {x,y,z});
//		}
//		List<Integer> temp = new ArrayList<>();
//		dfs(temp,k);
//		System.out.println(sb.append(mini));
//	}
//}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
	
	static int[][] board = new int[51][51];
	static List<int[]> a = new ArrayList<>();
	static boolean[] check = new boolean[10];
	static int mini = Integer.MAX_VALUE;
	static int N,M;
	
	static int cal_board(int[][] temp) {
		int result = Integer.MAX_VALUE;
		for(int i=0;i<N;i++) {
			int sum = 0;
			for(int j=0;j<M;j++) {
				sum += temp[i][j];
			}
			result = Math.min(result, sum);
		}
		return result;
	}
	
	static void rotate(int[][] temp, int r, int c, int s) {
		int[][] tmp_board = new int[N][M];
		int sx = r-s-1; int sy = c-s-1;
		int ex = r+s-1; int ey = c+s-1;
		int col = ex-sx+1;
		int row = ey-sy+1;
		while(col>0&&row>0) {
			for(int i=sx;i<sx+col-1;i++) {
				tmp_board[i][sy] = temp[i+1][sy];
			}
			for(int j=sy;j<sy+row-1;j++) {
				tmp_board[sx+col-1][j] = temp[sx+col-1][j+1];
			}
			for(int i=sx+col-1;i>sx;i--) {
				tmp_board[i][sy+row-1] = temp[i-1][sy+row-1];
			}
			for(int j=sy+row-1;j>sy;j--) {
				tmp_board[sx][j] = temp[sx][j-1];
			}
			sx+=1;
			sy+=1;
			col-=2;
			row-=2;
		}
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(tmp_board[i][j]==0) continue;
				temp[i][j] = tmp_board[i][j];
			}
		}
	}
	static void dfs(List<int[]> temp) {
		if(temp.size()==a.size()) {
			int[][] tmp_board = new int[N][M];
			for(int i=0;i<N;i++) {
				for(int j=0;j<M;j++) {
					tmp_board[i][j] = board[i][j];
				}
			}
			for(int i=0;i<temp.size();i++) {
				int[] now = temp.get(i);
				rotate(tmp_board,now[0],now[1],now[2]);
			}
			mini = Math.min(mini, cal_board(tmp_board));
			return;
		}
		for(int i=0;i<a.size();i++) {
			if(check[i]==true) continue;
			check[i] = true;
			temp.add(a.get(i));
			dfs(temp);
			temp.remove(temp.size()-1);
			check[i] = false;
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
		int k = Integer.parseInt(st.nextToken());
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<m;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for(int i=0;i<k;i++) {
			st = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int s = Integer.parseInt(st.nextToken());
			a.add(new int[] {r,c,s});
		}
		List<int[]> temp = new ArrayList<>();
		dfs(temp);
		System.out.println(sb.append(mini));
	}
}