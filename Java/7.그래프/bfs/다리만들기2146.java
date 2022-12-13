//import java.io.*;
//import java.util.*;
//
//public class Main {
//	
//	static int[] dx = {0,-1,0,1};
//	static int[] dy = {-1,0,1,0};
//	static int[][] board = new int[101][101];
//	static boolean[][] check = new boolean[101][101];
//	static List<List<int[]>> island = new ArrayList<>();
//	static int N;
//	static int mini = Integer.MAX_VALUE;
//	
//	
//	static int cal(List<int[]> a, List<int[]> b) {
//		int result = Integer.MAX_VALUE;
//		for(int i=0;i<a.size();i++) {
//			int sx = a.get(i)[0]; int sy = a.get(i)[1];
//			for(int j=0;j<b.size();j++) {
//				int ex = b.get(j)[0]; int ey = b.get(j)[1];
//				int dist = Math.abs(ex-sx)+Math.abs(ey-sy);
//				result = Math.min(result, dist);
//			}
//		}
//		return result;
//	}
//	
//	static void bfs(int sx, int sy) {
//		List<int[]> temp = new ArrayList<>();
//		Queue<int[]> q = new LinkedList<>();
//		q.offer(new int[] {sx,sy});
//		check[sx][sy] = true;
//		temp.add(new int[] {sx,sy});
//		while(!q.isEmpty()) {
//			int[] now = q.poll();
//			int x = now[0]; int y = now[1];
//			for(int i=0;i<4;i++) {
//				int nx = x+dx[i];
//				int ny = y+dy[i];
//				if(nx>=0&&nx<N&&ny>=0&&ny<N&&check[nx][ny]==false) {
//					if(board[nx][ny]==1) {
//						q.offer(new int[] {nx,ny});
//						check[nx][ny] = true;
//						temp.add(new int[] {nx,ny});
//					}
//				}
//			}
//		}
//		island.add(temp);
//	}
//	
//	
//	public static void main(String[] args) throws NumberFormatException, IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		int n = Integer.parseInt(br.readLine());
//		N=n;
//		for(int i=0;i<n;i++) {
//			st = new StringTokenizer(br.readLine());
//			for(int j=0;j<n;j++) {
//				board[i][j] = Integer.parseInt(st.nextToken());
//			}
//		}
//		for(int i=0;i<n;i++) {
//			for(int j=0;j<n;j++) {
//				if(board[i][j]==1&&check[i][j]==false) {
//					bfs(i,j);
//				}
//			}
//		}
//		for(int i=0;i<island.size();i++) {
//			for(int j=i+1;j<island.size();j++) {
//				int dist = cal(island.get(i),island.get(j));
//				mini = Math.min(mini, dist);
//			}
//		}
//		System.out.println(sb.append(mini-1));
//	}
//}
import java.io.*;
import java.util.*;

public class Main {
	
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] board = new int[101][101];
	static boolean[][] check = new boolean[101][101];
	static List<List<int[]>> island = new ArrayList<>();
	static int answer = Integer.MAX_VALUE;
	static int N;
	
	static void bfs(int px, int py) {
		List<int[]> result = new ArrayList<>();
		Queue<int[]> q = new LinkedList<>();
		q.offer(new int[] {px,py});
		check[px][py] = true;
		result.add(new int[] {px,py});
		while(!q.isEmpty()) {
			int[] now = q.poll();
			int x = now[0]; int y = now[1];
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx>=0&&nx<N&&ny>=0&&ny<N&&check[nx][ny]==false) {
					if(board[nx][ny]==1) {
						q.offer(new int[] {nx,ny});
						check[nx][ny] = true;
						result.add(new int[] {nx,ny});
					}
				}
			}
		}
		island.add(result);
	}
	
	static void cal(List<int[]> o1, List<int[]> o2) {
		for(int i=0;i<o1.size();i++) {
			int sx = o1.get(i)[0]; int sy = o1.get(i)[1];
			for(int j=0;j<o2.size();j++) {
				int ex = o2.get(j)[0]; int ey = o2.get(j)[1];
				int dist = Math.abs(ex-sx) + Math.abs(ey-sy);
				answer = Math.min(answer, dist-1);
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		N=n;
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<n;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(board[i][j]==1&&check[i][j]==false) {
					bfs(i,j);
				}
			}
		}
		for(int i=0;i<island.size();i++) {
			for(int j=i+1;j<island.size();j++) {
				cal(island.get(i),island.get(j));
			}
		}
		System.out.println(sb.append(answer));
	}
}
