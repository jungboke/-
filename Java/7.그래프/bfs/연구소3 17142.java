//import java.io.*;
//import java.util.*;
//import java.util.Map.Entry;
//
//public class Main {
//	
//	static int[] dx = {0,-1,0,1};
//	static int[] dy = {-1,0,1,0};
//	static int[][] board = new int[51][51];
//	static int[][] dist = new int[51][51];
//	static List<int[]> virus = new ArrayList<>();
//	static int N,M;
//	static int mini = Integer.MAX_VALUE;
//	
//	static void cal(List<int[]> temp) {
//		for(int i=0;i<N;i++) {
//			for(int j=0;j<N;j++) dist[i][j] = 0;
//
//		}
//		Queue<int[]> q = new LinkedList<>();
//		for(int i=0;i<temp.size();i++) {
//			int x = temp.get(i)[0]; int y = temp.get(i)[1];
//			q.offer(new int[] {x,y});
//			dist[x][y] = 1;
//		}
//		while(!q.isEmpty()) {
//			int[] now = q.poll();
//			int x = now[0]; int y = now[1];
//			for(int i=0;i<4;i++) {
//				int nx = x+dx[i];
//				int ny = y+dy[i];
//				if(nx>=0&&nx<N&&ny>=0&&ny<N&&dist[nx][ny]==0) {
//					if(board[nx][ny]==0||board[nx][ny]==2) {
//						q.offer(new int[] {nx,ny});
//						dist[nx][ny] = dist[x][y]+1;
//					}
//				}
//			}
//		}
//		int result = -1;
//		for(int i=0;i<N;i++) {
//			for(int j=0;j<N;j++) {
//				if(board[i][j]==0&&dist[i][j]==0) return;
//				if(board[i][j]==0) {
//					result = Math.max(result, dist[i][j]);					
//				}
//			}
//		}
//		if(result==-1) result = 1;
//		mini = Math.min(mini, result-1);
//	}
//	
//	static void dfs(List<int[]> temp, int start) {
//		if(temp.size()==M) {
//			cal(temp);
//			return;
//		}
//		for(int i=start;i<virus.size();i++) {
//			temp.add(virus.get(i));
//			dfs(temp,i+1);
//			temp.remove(temp.size()-1);
//		}
//	}
//	
//    public static void main(String[] args) throws IOException {
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        StringBuilder sb = new StringBuilder();
//        StringTokenizer st;
//
//    	st = new StringTokenizer(br.readLine());
//    	int n = Integer.parseInt(st.nextToken());
//    	int m = Integer.parseInt(st.nextToken());
//    	N=n;M=m;
//    	for(int i=0;i<n;i++) {
//    		st = new StringTokenizer(br.readLine());
//    		for(int j=0;j<n;j++) {
//    			board[i][j] = Integer.parseInt(st.nextToken());
//    			if(board[i][j]==2) virus.add(new int[] {i,j});
//    		}
//    	}
//    	List<int[]> temp = new ArrayList<>();
//    	dfs(temp,0);
//    	if(mini==Integer.MAX_VALUE) mini = -1;
//    	System.out.println(sb.append(mini));
//	}
//}
import java.io.*;
import java.util.*;

public class Main {
	
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] board = new int[51][51];
	static int[][] dist = new int[51][51];
	static List<int[]> virus = new ArrayList<>();
	static int answer = Integer.MAX_VALUE;
	static int N,M;
	
	static int bfs(List<int[]> temp) {
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) dist[i][j] = 0;
		}
		Queue<int[]> q = new LinkedList<>();
		for(int i=0;i<temp.size();i++) {
			int x = temp.get(i)[0]; int y = temp.get(i)[1];
			q.offer(new int[] {x,y});
			dist[x][y] = 1;
		}
		while(!q.isEmpty()) {
			int[] now = q.poll();
			int x = now[0]; int y = now[1];
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx>=0&&nx<N&&ny>=0&&ny<N&&dist[nx][ny]==0) {
					if(board[nx][ny]==0||board[nx][ny]==2) {
						q.offer(new int[] {nx,ny});
						dist[nx][ny] = dist[x][y]+1;
					}
				}
			}
		}
		int result = Integer.MIN_VALUE;
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(board[i][j]==0) {
					if(dist[i][j]==0) return Integer.MAX_VALUE;
					result = Math.max(result, dist[i][j]);
				}
			}
		}
		return result-1;
	}
	
	static void dfs(List<int[]> temp, int start) {
		if(temp.size()==M) {
			int cnt = bfs(temp);
			answer = Math.min(answer, cnt);
			return;
		}
		for(int i=start;i<virus.size();i++) {
			int x = virus.get(i)[0]; int y = virus.get(i)[1];
			temp.add(new int[] {x,y});
			dfs(temp,i+1);
			temp.remove(temp.size()-1);
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		N=n;M=m;
		int z_cnt = 0;
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<n;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				if(board[i][j]==0) z_cnt+=1;
				if(board[i][j]==2) {
					virus.add(new int[] {i,j});
				}
			}
		}
		if(z_cnt==0) {
			System.out.println(sb.append(0));
			return;
		}
		List<int[]> temp = new ArrayList<>();
		dfs(temp,0);
		if(answer==Integer.MAX_VALUE) answer = -1;
		System.out.println(sb.append(answer));
	}
}
