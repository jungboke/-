//import java.io.*;
//import java.util.*;
//
//public class Main {
//	
//	static int[] dx = {0,-1,0,1};
//	static int[] dy = {-1,0,1,0};
//	static char[][] board = new char[5][5];
//	static boolean[][] bcheck = new boolean[5][5];
//	static boolean[] check = new boolean[25];
//	static int answer = 0;
//	
//	static boolean count_check(List<int[]> temp) {
//		int scnt = 0;
//		int ycnt = 0;
//		for(int i=0;i<temp.size();i++) {
//			int x = temp.get(i)[0]; int y = temp.get(i)[1];
//			if(board[x][y]=='S') scnt+=1;
//			else ycnt+=1;
//		}
//		if(scnt>ycnt) return true;
//		else return false;
//	}
//	
//	static boolean bfs_check(List<int[]> temp) {
//		for(int i=0;i<5;i++) {
//			for(int j=0;j<5;j++) bcheck[i][j] = false;
//		}
//		Queue<int[]> q = new LinkedList<>();
//		int sx = temp.get(0)[0]; int sy = temp.get(0)[1];
//		q.offer(new int[] {sx,sy});
//		bcheck[sx][sy] = true;
//		while(!q.isEmpty()) {
//			int[] now = q.poll();
//			int x = now[0]; int y = now[1];
//			for(int i=0;i<4;i++) {
//				int nx = x+dx[i];
//				int ny = y+dy[i];
//				if(nx>=0&&nx<5&&ny>=0&&ny<5&&bcheck[nx][ny]==false) {
//					for(int k=0;k<temp.size();k++) {
//						int ex = temp.get(k)[0]; int ey = temp.get(k)[1];
//						if(nx==ex&&ny==ey) {
//							q.offer(new int[] {nx,ny});
//							bcheck[nx][ny] = true;
//						}
//					}
//				}
//			}
//		}
//		for(int i=0;i<temp.size();i++) {
//			int x = temp.get(i)[0]; int y = temp.get(i)[1];
//			if(bcheck[x][y]==false) return false;
//		}
//		return true;
//	}
//	
//	static void dfs(List<int[]> temp, int start) {
//		if(temp.size()==7) {
//			if(count_check(temp)) {
//				if(bfs_check(temp)) {
//					answer+=1;
//				}
//			}
//			return;
//		}
//		for(int i=start;i<25;i++) {
//			int x = i/5;
//			int y = i%5;
//			temp.add(new int[] {x,y});
//			dfs(temp,i+1);
//			temp.remove(temp.size()-1);
//		}
//	}
//	
//	public static void main(String[] args) throws NumberFormatException, IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		for(int i=0;i<5;i++) {
//			String temp = br.readLine();
//			for(int j=0;j<5;j++) {
//				board[i][j] = temp.charAt(j);
//			}
//		}
//		List<int[]> temp = new ArrayList<>();
//		dfs(temp,0);
//		System.out.println(sb.append(answer));
//	} 
//}
import java.io.*;
import java.util.*;

public class Main {
	
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static char[][] board = new char[5][5];
	static boolean[][] check = new boolean[5][5];
	static boolean[][] visited = new boolean[5][5];
	static int answer = 0;
	
	static boolean group_check(List<Integer> temp) {
		for(int i=0;i<5;i++) {
			for(int j=0;j<5;j++) {
				check[i][j] = false;
				visited[i][j] = false;
			}
		}
		int scnt = 0;
		Queue<int[]> q = new LinkedList<>();
		for(int i=0;i<temp.size();i++) {
			int x = temp.get(i)/5; int y = temp.get(i)%5;
			check[x][y] = true;
			if(q.isEmpty()) {
				q.offer(new int[] {x,y});
				visited[x][y] = true;
			}
			if(board[x][y]=='S') scnt+=1;
		}
		if(scnt<4) return false;
		while(!q.isEmpty()) {
			int[] now = q.poll();
			int x = now[0]; int y = now[1];
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx>=0&&nx<5&&ny>=0&&ny<5&&visited[nx][ny]==false) {
					if(check[nx][ny]==true) {
						q.offer(new int[] {nx,ny});
						visited[nx][ny] = true;
					}
				}
			}
		}
		for(int i=0;i<temp.size();i++) {
			int x = temp.get(i)/5; int y = temp.get(i)%5;
			if(visited[x][y]==false) return false;
		}
		return true;
	}
	
	static void dfs(List<Integer> temp, int start) {
		if(temp.size()==7) {
			if(group_check(temp)) {
				answer+=1;
			}
			return;
		}
		for(int i=start;i<25;i++) {
			temp.add(i);
			dfs(temp,i+1);
			temp.remove(temp.size()-1);
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		for(int i=0;i<5;i++) {
			String temp = br.readLine();
			for(int j=0;j<5;j++) {
				board[i][j] = temp.charAt(j);
			}
		}
		List<Integer> temp = new ArrayList<>();
		dfs(temp,0);
		System.out.println(sb.append(answer));
	}
}

