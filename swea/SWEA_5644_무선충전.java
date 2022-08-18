import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Solution {

	static int[] dx = {0,-1,0,1,0};
	static int[] dy = {0,0,1,0,-1};
	static List<Integer> a = new ArrayList<>();
	static List<Integer> b = new ArrayList<>();
	static List<int[]>[][] board = new ArrayList[11][11];
	
	static int move() {
		int result = 0;
		int sx=0,sy=0;
		int ex=9,ey=9;
		result+=board[sx][sy].get(0)[0];
		result+=board[ex][ey].get(0)[0];
		for(int i=0;i<a.size();i++) {
			sx+=dx[a.get(i)];
			sy+=dy[a.get(i)];
			ex+=dx[b.get(i)];
			ey+=dy[b.get(i)];
			if(board[sx][sy].get(0)[1]==board[ex][ey].get(0)[1]) {
				if(board[sx][sy].get(0)[1]==-1) continue;
				int x = board[sx][sy].get(1)[0]+board[ex][ey].get(0)[0];
				int y = board[sx][sy].get(0)[0]+board[ex][ey].get(1)[0];
				int maxi = Math.max(x, y);
				result+=maxi;
			} else {
				result+=board[sx][sy].get(0)[0];
				result+=board[ex][ey].get(0)[0];
			}
		}
		return result;
	}
	
	static void spark(int x, int y, int c, int p, int cnt) {
		for(int i=0;i<10;i++) {
			for(int j=0;j<10;j++) {
				int dist = Math.abs(x-i)+Math.abs(y-j);
				if(dist<=c) {
					board[i][j].add(new int[] {p,cnt});
				}
			}
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("data/5644.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
			for(int i=0;i<10;i++) {
				for(int j=0;j<10;j++) {
					board[i][j] = new ArrayList<>();
					board[i][j].add(new int[] {0,-1});
				}
			}
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<n;i++) {
				int x = Integer.parseInt(st.nextToken());
				a.add(x);
			}
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<n;i++) {
				int x = Integer.parseInt(st.nextToken());
				b.add(x);
			}
			int cnt = 0;
			for(int i=0;i<m;i++) {
				st = new StringTokenizer(br.readLine());
				int y = Integer.parseInt(st.nextToken())-1;
				int x = Integer.parseInt(st.nextToken())-1;
				int c = Integer.parseInt(st.nextToken());
				int p = Integer.parseInt(st.nextToken());
				spark(x,y,c,p,cnt++);
			}
			for(int i=0;i<10;i++) {
				for(int j=0;j<10;j++) {
					Collections.sort(board[i][j], new Comparator<int[]>() {
						public int compare(int[] x, int[] y) {
							return Integer.compare(x[0], y[0])*-1;
						}
					});
				}
			}
			int answer = move();
			sb.append("#"+(ot-t)+" "+answer+"\n");
			a.clear();
			b.clear();
			for(int i=0;i<10;i++) {
				for(int j=0;j<10;j++) {
					board[i][j].clear();
				}
			}
		}
		System.out.println(sb);
	}
}