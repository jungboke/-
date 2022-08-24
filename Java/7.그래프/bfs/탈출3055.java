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
//	static int[] dx = {0,-1,0,1};
//	static int[] dy = {-1,0,1,0};
//	static char[][] board = new char[51][51];
//	static int[][] dist = new int[51][51];
//	static boolean[][] w_check = new boolean[51][51];
//	static int N,M;
//	
//	static void move(List<int[]> temp) {
//		List<int[]> result = new ArrayList<>();
//		for(int i=0;i<temp.size();i++) {
//			for(int j=0;j<4;j++) {
//				int nx = temp.get(i)[0]+dx[j];
//				int ny = temp.get(i)[1]+dy[j];
//				if(nx>=0&&nx<N&&ny>=0&&ny<M&&w_check[nx][ny]==false) {
//					if(board[nx][ny]!='D'&&board[nx][ny]!='X') {						
//						result.add(new int[] {nx,ny});
//						w_check[nx][ny] = true;
//					}
//				}
//			}
//		}
//		temp.addAll(result);
//	}
//	
//	static boolean water_wall_check(int x ,int y, List<int[]> temp) {
//		for(int i=0;i<temp.size();i++) {
//			if(temp.get(i)[0]==x&&temp.get(i)[1]==y) return true;
//		}
//		if(board[x][y]=='X') return true;
//		return false;
//	}
//	
//	static String bfs(int sx ,int sy, int ex, int ey, List<int[]> temp) {
//		for(int i=0;i<dist.length;i++) {
//			Arrays.fill(dist[i], -1);
//		}
//		Queue<int[]> q = new LinkedList<>();
//		q.offer(new int[] {sx,sy});
//		dist[sx][sy] = 0;
//		while(!q.isEmpty()) {
//			int cnt = q.size();
//			move(temp);
//			for(int c=0;c<cnt;c++) {
//				int[] now = q.poll();
//				int x = now[0]; int y = now[1];
//				for(int i=0;i<4;i++) {
//					int nx = x+dx[i];
//					int ny = y+dy[i];
//					if(nx>=0&&nx<N&&ny>=0&&ny<M&&dist[nx][ny]==-1) {
//						if(!(water_wall_check(nx,ny,temp))) {
//							q.offer(new int[] {nx,ny});
//							dist[nx][ny] = dist[x][y]+1;
//						}
//					}
//				}
//			}
//		}
//		if(dist[ex][ey]==-1) return "KAKTUS";
//		else return Integer.toString(dist[ex][ey]);
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
//		int sx = 0; int sy = 0; int ex = 0; int ey = 0;
//		List<int[]> w_temp = new ArrayList<>();
//		for(int i=0;i<n;i++) {
//			String temp = br.readLine();
//			for(int j=0;j<m;j++) {
//				board[i][j] = temp.charAt(j);
//				if(temp.charAt(j)=='S') {
//					sx = i;
//					sy = j;
//					board[i][j]='.';
//				} else if(temp.charAt(j)=='D') {
//					ex = i;
//					ey = j;
//				} else if(temp.charAt(j)=='*') {
//					w_temp.add(new int[] {i,j});
//					board[i][j]='.';
//					w_check[i][j] = true;
//				}
//			}
//		}
//		System.out.println(sb.append(bfs(sx,sy,ex,ey,w_temp)));
//	}
//}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static char[][] board = new char[51][51];
	static int[][] dist = new int[51][51];
	static boolean[][] check = new boolean[51][51];
	static int N,M;
	
	static int bfs(int sx, int sy, int ex, int ey, List<int[]> water) {
		for(int i=0;i<N;i++) Arrays.fill(dist[i], -1);
		Queue<int[]> q = new LinkedList<>();
		Queue<int[]> q2 = new LinkedList<>();
		q.offer(new int[] {sx,sy});
		dist[sx][sy] = 0;
		for(int i=0;i<water.size();i++) {
			q2.offer(water.get(i));
			check[water.get(i)[0]][water.get(i)[1]] = true;
		};
		while(!q.isEmpty()) {
			int size2 = q2.size();
			for(int c=0;c<size2;c++) {
				int[] now = q2.poll();
				int x = now[0]; int y = now[1];
				for(int i=0;i<4;i++) {
					int nx = x+dx[i];
					int ny = y+dy[i];
					if(nx>=0&&nx<N&&ny>=0&&ny<M&&check[nx][ny]==false) {
						if(board[nx][ny]=='.') {
							q2.offer(new int[] {nx,ny});
							check[nx][ny] = true;
						}
					}
				}
			}
			int size = q.size();
			for(int c=0;c<size;c++) {
				int[] now = q.poll();
				int x = now[0]; int y = now[1];
				for(int i=0;i<4;i++) {
					int nx = x+dx[i];
					int ny = y+dy[i];
					if(nx>=0&&nx<N&&ny>=0&&ny<M&&dist[nx][ny]==-1&&check[nx][ny]==false) {
						if(board[nx][ny]=='D'||board[nx][ny]=='.') {
							q.offer(new int[] {nx,ny});
							dist[nx][ny] = dist[x][y]+1;
						}
					}
				}	
			}
		}
		return dist[ex][ey];
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		N=n;M=m;
		int sx=0,sy=0,ex=0,ey=0,wx=0,wy=0;
		List<int[]> water = new ArrayList<>();
		for(int i=0;i<n;i++) {
			String temp = br.readLine();
			for(int j=0;j<m;j++) {
				board[i][j] = temp.charAt(j);
				if(board[i][j]=='S') {
					sx = i; sy = j;
					board[i][j] = '.';
				} else if(board[i][j]=='D') {
					ex = i; ey = j;
				} else if(board[i][j]=='*') {
					water.add(new int[] {i,j});
				}
			}
		}
		int answer = bfs(sx,sy,ex,ey,water);
		if(answer==-1) sb.append("KAKTUS");
		else sb.append(answer);
		System.out.println(sb);
	}
}
