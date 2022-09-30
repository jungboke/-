//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Arrays;
//import java.util.LinkedList;
//import java.util.List;
//import java.util.Queue;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	static List<int[]> home = new ArrayList<>();
//	static List<int[]> chicken = new ArrayList<>();
//	static int mini = Integer.MAX_VALUE;
//
//	static int cal(List<int[]> temp) {
//		int result = 0;
//		for(int i=0;i<home.size();i++) {
//			int sum = Integer.MAX_VALUE;
//			for(int j=0;j<temp.size();j++) {
//				int dist = Math.abs(home.get(i)[0]-temp.get(j)[0]) +
//						Math.abs(home.get(i)[1]-temp.get(j)[1]);
//				sum = Math.min(sum, dist);
//			}
//			result+=sum;
//		}
//		return result;
//	}
//
//	static void dfs(List<int[]> temp, int start, int limit) {
//		if(temp.size()==limit) {
//			mini = Math.min(mini,cal(temp));
//			return;
//		}
//		for(int i=start;i<chicken.size();i++) {
//			temp.add(chicken.get(i));
//			dfs(temp,i+1,limit);
//			temp.remove(temp.size()-1);
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
//		for(int i=0;i<n;i++) {
//			st = new StringTokenizer(br.readLine());
//			for(int j=0;j<n;j++) {
//				int x = Integer.parseInt(st.nextToken());
//				if(x==1) home.add(new int[] {i,j});
//				else if(x==2) chicken.add(new int[] {i,j});
//			}
//		}
//		List<int[]> temp = new ArrayList<>();
//		dfs(temp,0,m);
//		System.out.println(sb.append(mini));
//	}
//}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
	
	static int[][] board = new int[51][51];
	static List<int[]> home = new ArrayList<>();
	static List<int[]> chicken = new ArrayList<>();
	static int mini = Integer.MAX_VALUE;
	
	static int cal(List<int[]> temp) {
		int sum = 0;
		for(int i=0;i<home.size();i++) {
			int dist = Integer.MAX_VALUE;
			int sx = home.get(i)[0];
			int sy = home.get(i)[1];
			for(int j=0;j<temp.size();j++) {
				int ex = temp.get(j)[0];
				int ey = temp.get(j)[1];
				dist = Math.min(dist, Math.abs(sx-ex) + Math.abs(sy-ey));
			}
			sum += dist;
		}
		return sum;
	}
	
	static void dfs(List<int[]> temp, int limit, int start) {
		if(temp.size()==limit) {
			mini = Math.min(mini, cal(temp));
			return;
		}
		for(int i=start;i<chicken.size();i++) {
			temp.add(chicken.get(i));
			dfs(temp,limit,i+1);
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
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<n;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				if(board[i][j]==1) {
					home.add(new int[] {i,j});
				} else if(board[i][j]==2) {
					chicken.add(new int[] {i,j});
				}
			}
		}
		List<int[]> temp = new ArrayList<>();
		dfs(temp,m,0);
		System.out.println(sb.append(mini));
	}
}
