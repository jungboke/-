//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.Arrays;
//import java.util.Collections;
//import java.util.LinkedList;
//import java.util.Queue;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	static int[] dx = {0,-1,-1,-1,0,1,1,1};
//	static int[] dy = {-1,-1,0,1,1,1,0,-1};
//	static int[][] board = new int[51][51];
//	static int[][] color = new int[51][51];
//	static int N,M;
//
//	static void bfs(int px, int py, int cnt) {
//		Queue<int[]> q = new LinkedList<>();
//		q.offer(new int[] {px,py});
//		color[px][py] = cnt;
//		while(!q.isEmpty()) {
//			int[] now = q.poll();
//			int x = now[0]; int y = now[1];
//			for(int i=0;i<8;i++) {
//				int nx = x+dx[i];
//				int ny  =y+dy[i];
//				if(nx>=0&&nx<N&&ny>=0&&ny<M&&color[nx][ny]==0) {
//					if(board[nx][ny]==1) {
//						q.offer(new int[] {nx,ny});
//						color[nx][ny] = cnt;
//					}
//				}
//			}
//		}
//	}
n//
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//
//		while(true) {
//			st = new StringTokenizer(br.readLine());
//			int m = Integer.parseInt(st.nextToken());
//			int n = Integer.parseInt(st.nextToken());
//			N=n;M=m;
//			if(n==0&&m==0) break;
//			for(int i=0;i<n;i++) {
//				st = new StringTokenizer(br.readLine());
//				for(int j=0;j<m;j++) {
//					board[i][j] = Integer.parseInt(st.nextToken());
//				}
//			}
//			int cnt = 1;
//			for(int i=0;i<n;i++) {
//				for(int j=0;j<m;j++) {
//					if(color[i][j]==0&&board[i][j]==1) {
//						bfs(i,j,cnt++);
//					}
//				}
//			}
//			sb.append((cnt-1)+"\n");
//			for(int i=0;i<n;i++) Arrays.fill(color[i], 0);
//		}
//		System.out.println(sb);
//	}
//}
// import java.io.*;
// import java.util.*;

// public class Main {
		
// 	static int[] dx = {0,-1,-1,-1,0,1,1,1};
// 	static int[] dy = {-1,-1,0,1,1,1,0,-1};
// 	static int[][] board = new int[51][51];
// 	static boolean[][] check = new boolean[51][51];
	
// 	static int bfs(int n, int m) {
// 		for(int i=0;i<n;i++) {
// 			for(int j=0;j<m;j++) check[i][j] = false;
// 		}
// 		int result = 0;
// 		for(int i=0;i<n;i++) {
// 			for(int j=0;j<m;j++) {
// 				if(!(board[i][j]==1&&check[i][j]==false)) continue;
// 				result+=1;
// 				Queue<int[]> q = new LinkedList<>();
// 				q.offer(new int[] {i,j});
// 				check[i][j] = true;
// 				while(!q.isEmpty()) {
// 					int[] now = q.poll();
// 					int x = now[0]; int y = now[1];
// 					for(int k=0;k<8;k++) {
// 						int nx = x+dx[k];
// 						int ny = y+dy[k];
// 						if(nx>=0&&nx<n&&ny>=0&&ny<m&&check[nx][ny]==false) {
// 							if(board[nx][ny]==1) {
// 								q.offer(new int[] {nx,ny});
// 								check[nx][ny] = true;
// 							}
// 						}
// 					}
// 				}
// 			}
// 		}
// 		return result;
// 	}
	
// 	public static void main(String[] args) throws IOException {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;
		
// 		while(true) {
// 			st = new StringTokenizer(br.readLine());
// 			int m = Integer.parseInt(st.nextToken());
// 			int n = Integer.parseInt(st.nextToken());
// 			if(n==0&&m==0) break;
// 			for(int i=0;i<n;i++) {
// 				st = new StringTokenizer(br.readLine());
// 				for(int j=0;j<m;j++) {
// 					board[i][j] = Integer.parseInt(st.nextToken());
// 				}
// 			}
// 			sb.append(bfs(n,m)+"\n");
// 		}
// 		System.out.println(sb);
// 	}
// }
import java.io.*;
import java.util.*;

public class Main {

    static int[] dx = {0,-1,-1,-1,0,1,1,1};
    static int[] dy = {-1,-1,0,1,1,1,0,-1};
    static int[][] board = new int[51][51];
    static boolean[][] visit = new boolean[51][51];
    static int answer = 0;

    static void bfs(int x, int y, int n, int m) {
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{x,y});
        visit[x][y] = true;
        while(!q.isEmpty()) {
            int[] now = q.poll();
            int px = now[0];
            int py = now[1];
            for(int i=0;i<8;i++) {
                int nx = px+dx[i];
                int ny = py+dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&board[nx][ny]==1&&visit[nx][ny]==false) {
                    q.offer(new int[]{nx,ny});
                    visit[nx][ny] = true;
                }
            }
        }
        answer+=1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        while(true) {
            st = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            if(n==0&&m==0) break;
            answer = 0;
            for(int i=0;i<n;i++) {
                Arrays.fill(visit[i], false);
            }
            for(int i=0;i<n;i++) {
                st = new StringTokenizer(br.readLine());
                for(int j=0;j<m;j++) {
                    board[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    if(board[i][j]==1&&visit[i][j]==false) bfs(i,j,n,m);
                }
            }
            sb.append(answer).append("\n");
        }
        System.out.println(sb.toString());
    }
}

