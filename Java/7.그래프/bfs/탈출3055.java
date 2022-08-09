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
	
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] board = new int[51][51];
	static int[][] dist = new int[51][51];
	static int N,M;
	
	static void move(List<int[]> temp) {
		List<int[]> result = new ArrayList<>();
		for(int i=0;i<temp.size();i++) {
			for(int j=0;j<4;j++) {
				int nx = temp.get(i)[0]+dx[j];
				int ny = temp.get(i)[1]+dy[j];
				if(nx>=0&&nx<N&&ny>=0&&ny<M&&board[nx][ny]!='D') {
					result.add(new int[] {nx,ny});
				}
			}
		}
		temp.clear();
		temp.addAll(result);
	}
	
	static boolean water_wall_check(int x ,int y, List<int[]> temp) {
		for(int i=0;i<temp.size();i++) {
			
		}
	}
	
	static String bfs(int sx ,int sy, int ex, int ey, List<int[]> temp) {
		Arrays.fill(dist, -1);
		Queue<int[]> q = new LinkedList<>();
		Queue<int[]> wq = new LinkedList<>();
		q.offer(new int[] {sx,sy});
		dist[sx][sy] = 0;
		while(!q.isEmpty()) {
			int cnt = q.size();
			for(int c=0;c<cnt;c++) {
				int[] now = q.poll();
				int x = now[0]; int y = now[1];
				for(int i=0;i<4;i++) {
					int nx = x+dx[i];
					int ny = y+dy[i];
					if(nx>=0&&nx<N&&ny>=0&&ny<M&&dist[nx][ny]==-1) {
						if(!(water_wall_check(nx,ny,temp))) {
							q.offer(new int[] {nx,ny});
							dist[nx][ny] = dist[x][y]+1;
						}
					}
				}
			}
			move(temp);
		}
		if(dist[ex][ey]==-1) return "KAKTUS";
		else return Integer.toString(dist[ex][ey]);
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		N=n;M=m;
		int sx = 0; int sy = 0; int ex = 0; int ey = 0;
		int wx = 0; int wy = 0;
		for(int i=0;i<n;i++) {
			String temp = br.readLine();
			for(int j=0;j<m;j++) {
				if(temp.charAt(j)=='S') {
					sx = i;
					sy = j;
				} else if(temp.charAt(j)=='D') {
					ex = i;
					ey = j;
				} else if(temp.charAt(j)=='*') {
					wx = i;
					wy = j;
				}
			}
		}
		List<int[]> temp = new ArrayList<>();
		temp.add(new int[] {wx,wy});
		System.out.println(sb.append(bfs(sx,sy,ex,ey,temp)));
	}
}