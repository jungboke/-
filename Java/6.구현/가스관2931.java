//import java.io.*;
//import java.util.*;
//
//public class Main {
//
//	// 이동하려는 좌표의 열려있는 방향과 현재 좌표의 열려있는 방향(dir_check)이 true일 경우에만 이동가능
//	// 브루트포스를 활용하여 모든 좌표에 대해 가능한 경우를 계산
//	// plus_stack을 통해 +인 경우만 이동할 수 있는 카운트를 2번으로 계산
//	// bfs를 통한 도착 좌표 이동 가능 여부 계산
//	static int[] dx = new int[] {0,-1,0,1};
//	static int[] dy = new int[] {-1,0,1,0};
//	static char[][] board = new char[26][26];
//	static boolean[][] check = new boolean[26][26];
//	static boolean[][][] dir_check = new boolean[26][26][4];
//	static int[][] plus_stack = new int[26][26];
//	static char[] op = new char[] {'|','-','+','1','2','3','4'};
//	static int N,M;
//	
//	static void check_clear() {
//		for(int i=0;i<N;i++) {
//			for(int j=0;j<M;j++) {
//				check[i][j] = false;
//				plus_stack[i][j] = 0;
//				for(int k=0;k<4;k++) dir_check[i][j][k] = false;
//			}
//		}
//		for(int i=0;i<N;i++) {
//			for(int j=0;j<M;j++) {
//				if(board[i][j]=='.') continue;
//				if(board[i][j]=='|') {
//					dir_check[i][j][1] = true;
//					dir_check[i][j][3] = true;
//				} else if(board[i][j]=='-') {
//					dir_check[i][j][0] = true;
//					dir_check[i][j][2] = true;
//				} else if(board[i][j]=='+') {
//					for(int k=0;k<4;k++) dir_check[i][j][k] = true;
//				} else if(board[i][j]=='1') {
//					dir_check[i][j][2] = true;
//					dir_check[i][j][3] = true;
//				} else if(board[i][j]=='2') {
//					dir_check[i][j][1] = true;
//					dir_check[i][j][2] = true;
//				} else if(board[i][j]=='3') {
//					dir_check[i][j][0] = true;
//					dir_check[i][j][1] = true;
//				} else if(board[i][j]=='4') {
//					dir_check[i][j][0] = true;
//					dir_check[i][j][3] = true;
//				} else {
//					for(int k=0;k<4;k++) dir_check[i][j][k] = true;
//				}
//			}
//		}
//	}
//	
//	static boolean bfs(int sx, int sy, int ex, int ey) {
//		check_clear();
//		Queue<int[]> q = new LinkedList<>();
//		q.offer(new int[] {sx,sy});
//		check[sx][sy] = true;
//		while(!q.isEmpty()) {
//			int[] now = q.poll();
//			int x = now[0]; int y = now[1];
//			for(int i=0;i<4;i++) {
//				int nx = x+dx[i];
//				int ny = y+dy[i];
//				if(!(nx>=0&&nx<N&&ny>=0&&ny<M)) {
//					if(board[x][y]!='M'&&board[x][y]!='Z'&&dir_check[x][y][i]==true) return false;
//				}
//				if(nx>=0&&nx<N&&ny>=0&&ny<M) {
//					if(dir_check[x][y][i]==true&&dir_check[nx][ny][(i+2)%4]==true) {
//						if(check[nx][ny]==false||(board[nx][ny]=='+'&&plus_stack[nx][ny]<2)) {
//							q.offer(new int[] {nx,ny});
//							check[nx][ny] = true;
//							if(board[nx][ny]=='+') plus_stack[nx][ny]+=1;							
//						}
//					}
//					if(dir_check[x][y][i]==true&&dir_check[nx][ny][(i+2)%4]==false) {
//						if(board[x][y]!='M'&&board[x][y]!='Z') return false;
//					}
//				}
//			}
//		}
//		for(int i=0;i<N;i++) {
//			for(int j=0;j<M;j++) {
//				if(board[i][j]!='.'&&check[i][j]==false) return false;
//			}
//		}
//		return check[ex][ey]; 
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
//		int sx=-1,sy=-1,ex=-1,ey=-1;
//		for(int i=0;i<n;i++) {
//			String temp = br.readLine();
//			for(int j=0;j<m;j++) {
//				board[i][j] = temp.charAt(j);
//				if(board[i][j]=='M') {
//					sx=i;sy=j;
//				}
//				if(board[i][j]=='Z') {
//					ex=i;ey=j;
//				}
//			}
//		}
//		outer:for(int i=0;i<n;i++) {
//			for(int j=0;j<m;j++) {
//				if(board[i][j]!='.') continue;
//				for(int k=0;k<7;k++) {
//					board[i][j] = op[k];
//					if(bfs(sx,sy,ex,ey)) {
//						sb.append((i+1)+" "+(j+1)+" "+op[k]+"\n");
//						break outer;
//					}
//				}
//				board[i][j] = '.';
//			}
//		}
//		System.out.println(sb);
//	}
//}
import java.io.*;
import java.util.*;

public class Main {
	
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static char[][] board = new char[26][26];
	static boolean[][][] check = new boolean[26][26][4];
	static char[] alpha = {'|','-','+','1','2','3','4'};
	static int answerX = 0;
	static int answerY = 0;
	static int answerZ = 0;
	static int N,M;
	
	static void makeBool(int x, int y, char k, boolean flag) {
		if(k=='|') {
			check[x][y][1] = flag;
			check[x][y][3] = flag;
		} else if(k=='-') {
			check[x][y][0] = flag;
			check[x][y][2] = flag;
		} else if(k=='+') {
			check[x][y][0] = flag;
			check[x][y][1] = flag;
			check[x][y][2] = flag;
			check[x][y][3] = flag;
		} else if(k=='1') {
			check[x][y][2] = flag;
			check[x][y][3] = flag;
		} else if(k=='2') {
			check[x][y][1] = flag;
			check[x][y][2] = flag;
		} else if(k=='3') {
			check[x][y][0] = flag;
			check[x][y][1] = flag;
		} else if(k=='4') {
			check[x][y][0] = flag;
			check[x][y][3] = flag;
		}
	}
	
	static boolean cal(int sx, int sy) {
		int ex = 0; int ey = 0; int prev = 0;
		for(int i=0;i<4;i++) {
			int nx = sx+dx[i];
			int ny = sy+dy[i];
			if(nx>=0&&nx<N&&ny>=0&&ny<M) {
				int k = (i+2)%4;
				if(check[nx][ny][k]==true) {
					ex = nx; ey = ny; prev = k;
					break;
				}
			}
		}
		while(true) {
			if(board[ex][ey]=='M') return true;
			if(board[ex][ey]=='+') {
				int next = (prev+2)%4;
				ex+=dx[next];
				ey+=dy[next];
				if(!(ex>=0&&ex<N&&ey>=0&&ey<M)) return false;
				if(check[ex][ey][prev]==false) return false;
				continue;
			}
			boolean flag = false;
			for(int i=0;i<4;i++) {
				if(i==prev) continue;
				if(check[ex][ey][i]==true) {
					int nx = ex+dx[i];
					int ny = ey+dy[i];
					if(!(nx>=0&&nx<N&&ny>=0&&ny<M)) continue;
					int next = (i+2)%4;
					if(check[nx][ny][next]==true) {
						ex+=dx[i];
						ey+=dy[i];
						prev = (i+2)%4;
						flag = true;
						break;						
					}
				}
			}
			if(flag==false) return false;
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
		int sx = 0; int sy = 0;
		for(int i=0;i<n;i++) {
			String temp = br.readLine();
			for(int j=0;j<m;j++) {
				board[i][j] = temp.charAt(j);
				if(board[i][j]=='Z') {
					sx = i; sy = j;
				} else if(board[i][j]=='M') {
					for(int k=0;k<4;k++) {
						check[i][j][k] = true;
					}
				}
				makeBool(i,j,board[i][j],true);
			}
		}
		outer:for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(board[i][j]!='.') continue;
				for(int k=0;k<7;k++) {
					board[i][j] = alpha[k];
					makeBool(i,j,alpha[k],true);
					if(cal(sx,sy)) {
						answerX = i+1;
						answerY = j+1;
						answerZ = k;
						break outer;
					}
					makeBool(i,j,alpha[k],false);
					board[i][j] = '.';
				}
			}
		}
		System.out.println(sb.append(answerX+" "+answerY+" "+alpha[answerZ]));
	}
}

