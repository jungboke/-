import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int INF = 1000000000;
	static int[][] board = new int[16][16];
	static List<int[]> enemy = new ArrayList<>();
	static int maxi = -1;
	static int N,M;

	static int kill(List<Integer> temp) {
		for(int c=0;c<temp.size();c++) {
			int mini = INF;
			int mx = -1;
			int my = -1;
			for(int i=0;i<enemy.size();i++) {
				int x = enemy.get(i)[0];
				int y = enemy.get(i)[1];
				int dist = Math.abs(x-N)+Math.abs(y-temp.get(c));
				if(mini>dist) {
					mini = dist;
					mx = x;
					my = y;
				}
			}
		}
		return 0;
	}

	static void dfs(List<Integer> temp, int start) {
		if(temp.size()==3) {
			int result = 0;
			while(!enemy.isEmpty()) {
				result+=kill(temp);
//				move();
			}
			maxi = Math.max(maxi, result);
		}
		for(int i=start;i<M;i++) {
			temp.add(i);
			dfs(temp,i+1);
			temp.remove(temp.size()-1);
		}
	}

	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//
//		st = new StringTokenizer(br.readLine());
//		int n = Integer.parseInt(st.nextToken());
//		int m = Integer.parseInt(st.nextToken());
//		N=n;M=m;
//		int d = Integer.parseInt(st.nextToken());
//		for(int i=0;i<n;i++) {
//			st = new StringTokenizer(br.readLine());
//			for(int j=0;j<m;j++) {
//				board[i][j] = Integer.parseInt(st.nextToken());
//				if(board[i][j]==1) {
//					enemy.add(new int[] {i,j});
//				}
//			}
//		}
//		List<Integer> temp = new ArrayList<>();
//		dfs(temp,0);
//		System.out.println(sb.append(maxi+"\n"));
		HashSet<int[]> s = new HashSet<>();
		s.add(new int[] {0,0});
		s.add(new int[] {0,0});
		System.out.println(s.size());
	}
}
