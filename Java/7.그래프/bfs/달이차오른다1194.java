//import java.io.*;
//import java.util.*;
//
//public class Main {
//	
//	static int[] dx = {0,-1,0,1};
//	static int[] dy = {-1,0,1,0};
//	static char[][] board = new char[51][51];
//	static int[][][] dist = new int[51][51][1<<6];
//	static List<int[]> one = new ArrayList<>();
//	static int N,M;
//	
//	static int bfs(int sx, int sy) {
//		Queue<int[]> q = new LinkedList<>();
//		q.offer(new int[] {sx,sy,0});
//		dist[sx][sy][0] = 1;
//		while(!q.isEmpty()) {
//			int[] now = q.poll();
//			int x = now[0]; int y = now[1]; int z = now[2];
//			for(int i=0;i<4;i++) {
//				int nx = x+dx[i];
//				int ny = y+dy[i];
//				if(nx>=0&&nx<N&&ny>=0&&ny<M) {
//					if(board[nx][ny]>='a'&&board[nx][ny]<='f') {
//						int nz = z|(1<<(board[nx][ny]-'a'));
//						if(dist[nx][ny][nz]==0) {
//							q.offer(new int[] {nx,ny,nz});
//							dist[nx][ny][nz] = dist[x][y][z]+1;							
//						}
//					} else if(board[nx][ny]=='.'&&dist[nx][ny][z]==0) {
//						q.offer(new int[] {nx,ny,z});
//						dist[nx][ny][z] = dist[x][y][z]+1;
//					} else if(board[nx][ny]>='A'&&board[nx][ny]<='F'&&dist[nx][ny][z]==0) {
//						if((z&(1<<(board[nx][ny]-'A')))!=0) {
//							q.offer(new int[] {nx,ny,z});
//							dist[nx][ny][z] = dist[x][y][z]+1;
//						}
//					}
//				}
//			}
//		}
//		int mini = Integer.MAX_VALUE;
//		for(int i=0;i<one.size();i++) {
//			int x = one.get(i)[0]; int y = one.get(i)[1];
//			for(int j=0;j<(1<<6);j++) {
//				if(dist[x][y][j]==0) continue;
//				mini = Math.min(mini, dist[x][y][j]);
//			}
//		}
//		if(mini==Integer.MAX_VALUE) return -1;
//		return mini-1;
//	}
//	
//	public static void main(String[] args) throws NumberFormatException, IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		st = new StringTokenizer(br.readLine());
//		int n = Integer.parseInt(st.nextToken());
//		int m = Integer.parseInt(st.nextToken());
//		N=n;M=m;
//		int sx=-1,sy=-1;
//		for(int i=0;i<n;i++) {
//			String temp = br.readLine();
//			for(int j=0;j<m;j++) {
//				board[i][j] = temp.charAt(j);
//				if(board[i][j]=='0') {
//					sx=i;sy=j;
//					board[i][j] = '.';
//				} else if(board[i][j]=='1') {
//					one.add(new int[] {i,j});
//					board[i][j] = '.';
//				}
//			}
//		}
//		System.out.println(sb.append(bfs(sx,sy)));
//	}
//}
// import java.io.*;
// import java.util.*;

// public class Main {
	
// 	static int[] dx = {0,-1,0,1};
// 	static int[] dy = {-1,0,1,0};
// 	static char[][] board = new char[51][51];
// 	static int[][][] dist = new int[51][51][(1<<6)];
// 	static int answer = Integer.MAX_VALUE;
// 	static int N,M;
	
// 	static void bfs(int sx, int sy) {
// 		for(int i=0;i<N;i++) {
// 			for(int j=0;j<M;j++) {
// 				for(int k=0;k<(1<<6);k++) dist[i][j][k] = Integer.MAX_VALUE;
// 			}
// 		}
// 		Queue<int[]> q = new LinkedList<>();
// 		q.offer(new int[] {sx,sy,0});
// 		dist[sx][sy][0] = 0;
// 		while(!q.isEmpty()) {
// 			int[] now = q.poll();
// 			int x = now[0]; int y = now[1]; int stat = now[2];
// 			for(int i=0;i<4;i++) {
// 				int nx = x+dx[i];
// 				int ny = y+dy[i];
// 				if(nx>=0&&nx<N&&ny>=0&&ny<M&&board[nx][ny]!='#') {
// 					if(board[nx][ny]>='a'&&board[nx][ny]<='f') {
// 						int num = board[nx][ny]-'a';
// 						int next = (stat|(1<<num));
// 						if(dist[nx][ny][next]>dist[x][y][stat]+1) {
// 							dist[nx][ny][next] = dist[x][y][stat]+1;
// 							q.offer(new int[] {nx,ny,next});
// 						}
// 					} else if(board[nx][ny]>='A'&&board[nx][ny]<='F') {
// 						int num = board[nx][ny]-'A';
// 						if((stat&(1<<num))!=0) {
// 							if(dist[nx][ny][stat]>dist[x][y][stat]+1) {
// 								dist[nx][ny][stat] = dist[x][y][stat]+1;
// 								q.offer(new int[] {nx,ny,stat});
// 							}
// 						}
// 					} else {
// 						if(dist[nx][ny][stat]>dist[x][y][stat]+1) {
// 							dist[nx][ny][stat] = dist[x][y][stat]+1;
// 							q.offer(new int[] {nx,ny,stat});
// 						}
// 					}
// 				}
// 			}
// 		}
// 		for(int i=0;i<N;i++) {
// 			for(int j=0;j<M;j++) {
// 				if(board[i][j]!='1') continue;
// 				for(int k=0;k<(1<<6);k++) {
// 					answer = Math.min(answer, dist[i][j][k]);
// 				}
// 			}
// 		}
// 	}
	
// 	public static void main(String[] args) throws Exception {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;
		
// 		st = new StringTokenizer(br.readLine());
// 		int n = Integer.parseInt(st.nextToken());
// 		int m = Integer.parseInt(st.nextToken());
// 		N=n;M=m;
// 		int sx=-1,sy=-1,ex=-1,ey=-1;
// 		for(int i=0;i<n;i++) {
// 			String temp = br.readLine();
// 			for(int j=0;j<m;j++) {
// 				board[i][j] = temp.charAt(j);
// 				if(board[i][j]=='0') {
// 					sx = i; sy = j;
// 				}
// 			}
// 		}
// 		bfs(sx,sy);
// 		if(answer==Integer.MAX_VALUE) answer = -1;
// 		System.out.println(sb.append(answer));
// 	}
// }
import java.util.*;
import java.io.*;

public class Main {
	
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static char[][] board = new char[51][51];
	static int[][][] dist = new int[51][51][(1<<6)];
	static int answer = Integer.MAX_VALUE;
	static int N,M;
	
	static void bfs(int sx, int sy) {
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				for(int k=0;k<(1<<6);k++) {
					dist[i][j][k] = Integer.MAX_VALUE;
				}
			}
		}
		Queue<int[]> q = new LinkedList<>();
		q.offer(new int[] {sx,sy,0});
		dist[sx][sy][0] = 0;
		while(!q.isEmpty()) {
			int[] now = q.poll();
			int x = now[0]; int y = now[1]; int cost = now[2];
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx>=0&&nx<N&&ny>=0&&ny<M&&board[nx][ny]!='#') {
					if(board[nx][ny]>='A'&&board[nx][ny]<='F') {
						int idx = board[nx][ny]-'A';
						if((cost&(1<<idx))!=0) {
							if(dist[nx][ny][cost]>dist[x][y][cost]+1) {
								dist[nx][ny][cost] = dist[x][y][cost]+1;
								q.offer(new int[] {nx,ny,cost});
							}
						}
					} else if(board[nx][ny]>='a'&&board[nx][ny]<='f') {
						int idx = board[nx][ny]-'a';
						int temp = (cost|(1<<idx));
						if(dist[nx][ny][temp]>dist[x][y][cost]+1) {
							dist[nx][ny][temp] = dist[x][y][cost]+1;
							q.offer(new int[] {nx,ny,temp});
						}
					} else {
						if(dist[nx][ny][cost]>dist[x][y][cost]+1) {
							dist[nx][ny][cost] = dist[x][y][cost]+1;
							q.offer(new int[] {nx,ny,cost});
						}
					}
				}
			}
			for(int i=0;i<N;i++) {
				for(int j=0;j<M;j++) {
					if(board[i][j]!='1') continue;
					for(int k=0;k<(1<<6);k++) {
						answer = Math.min(answer, dist[i][j][k]);
					}
				}
			}
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
		int sx=-1,sy=-1;
		for(int i=0;i<n;i++) {
			String temp = br.readLine();
			for(int j=0;j<m;j++) {
				board[i][j] = temp.charAt(j);
				if(board[i][j]=='0') {
					sx = i; sy = j;
				}
			}
		}
		bfs(sx,sy);
		if(answer==Integer.MAX_VALUE) answer = -1;
		System.out.println(sb.append(answer));
	}
}

