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

	static int[] dx = {0,0,-1,-1,-1,0,1,1,1};
	static int[] dy = {0,-1,-1,0,1,1,1,0,-1};
	static List<int[]> a = new ArrayList<>();
	static boolean[][] check = new boolean[8][8];
	static int answer = 0;

	static void move() {
		for(int i=0;i<a.size();i++) {
			int x = a.get(i)[0];
			int y = a.get(i)[1];
			if(x+1<8) a.set(i, new int[] {x+1,y});
			else {
				a.remove(i);
				i-=1;
			}
		}
	}

	static boolean wall_check(int x, int y) {
		for(int i=0;i<a.size();i++) {
			if((a.get(i)[0]==x&&a.get(i)[1]==y)) return true;
			if((a.get(i)[0]+1==x&&a.get(i)[1]==y)) return true;
		}
		return false;
	}

	static int bfs(int sx, int sy, int ex, int ey) {
		Queue<int[]> q = new LinkedList<>();
		q.offer(new int[] {sx,sy});
		check[sx][sy] = true;
		int t = 0;
		while(!q.isEmpty()) {
			if(t>7) return 1;
			int cnt = q.size();
			for(int c=0;c<cnt;c++) {
				int[] now = q.poll();
				int x = now[0]; int y = now[1];
				for(int i=0;i<9;i++) {
					int nx = x+dx[i];
					int ny = y+dy[i];
					if(nx>=0&&nx<8&&ny>=0&&ny<8) {
						if(!(wall_check(nx,ny))) {
							q.offer(new int[] {nx,ny});
						}
					}
				}
			}
			move();
			t+=1;
		}
		return 0;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		for(int i=0;i<8;i++) {
			String temp = br.readLine();
			for(int j=0;j<8;j++) {
				if(temp.charAt(j)=='#') {
					a.add(new int[] {i,j});
				}
			}
		}
		int sx = 7; int sy = 0;
		int ex = 0; int ey = 7;
		System.out.println(sb.append(bfs(sx,sy,ex,ey)));
	}
}
