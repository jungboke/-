//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	static int[][] board = new int[301][301];
//	static int N,M;
//
//	static void rotate() {
//		int[][] temp = new int[N][M];
//		int col = N;
//		int row = M;
//		int x = 0; int y = 0;
//		while(row!=0&&col!=0) {
//			for(int i=x+col-1;i>x;i--) {
//				temp[i][y] = board[i-1][y];
//			}
//			for(int j=y+1;j<y+row;j++) {
//				temp[x][j-1] = board[x][j];
//			}
//			for(int i=x+1;i<x+col;i++) {
//				temp[i-1][y+row-1] = board[i][y+row-1];
//			}
//			for(int j=y+row-1;j>y;j--) {
//				temp[x+col-1][j] = board[x+col-1][j-1];
//			}
//			row-=2;
//			col-=2;
//			x+=1;
//			y+=1;
//		}
//		for(int i=0;i<N;i++) {
//			for(int j=0;j<M;j++) {
//				board[i][j] = temp[i][j];
//			}
//		}
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
//		int r = Integer.parseInt(st.nextToken());
//		for(int i=0;i<n;i++) {
//			st = new StringTokenizer(br.readLine());
//			for(int j=0;j<m;j++) {
//				board[i][j] = Integer.parseInt(st.nextToken());
//			}
//		}
//		while(r-->0) {
//			rotate();
//		}
//		for(int i=0;i<n;i++) {
//			for(int j=0;j<m;j++) {
//				sb.append(board[i][j]+" ");
//			}
//			sb.append("\n");
//		}
//		System.out.println(sb);
//	}
//}
//
// import java.io.BufferedReader;
// import java.io.IOException;
// import java.io.InputStreamReader;
// import java.util.LinkedList;
// import java.util.Queue;
// import java.util.Stack;
// import java.util.StringTokenizer;

// public class Main {
	
// 	static int[][] board = new int[301][301];
// 	static int N,M;
	
// 	static void rotate() {
// 		int[][] tmp_board = new int[N][M];
// 		int x=0,y=0;
// 		int row = N;
// 		int col = M;
// 		while(!(row==0||col==0)) {
// 			for(int i=x+row-1;i>x;i--) {
// 				tmp_board[i][y] = board[i-1][y];
// 			}
// 			for(int j=y;j<y+col-1;j++) {
// 				tmp_board[x][j] = board[x][j+1];
// 			}
// 			for(int i=x;i<x+row-1;i++) {
// 				tmp_board[i][y+col-1] = board[i+1][y+col-1];
// 			}
// 			for(int j=y+col-1;j>y;j--) {
// 				tmp_board[x+row-1][j] = board[x+row-1][j-1];
// 			}
// 			x+=1;y+=1;
// 			row-=2;
// 			col-=2;
// 		}
// 		board = tmp_board.clone();
// 	}
	
// 	public static void main(String[] args) throws IOException {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;
		
// 		st = new StringTokenizer(br.readLine());
// 		int n = Integer.parseInt(st.nextToken());
// 		int m = Integer.parseInt(st.nextToken());
// 		N=n;M=m;
// 		int r = Integer.parseInt(st.nextToken());
// 		for(int i=0;i<n;i++) {
// 			st = new StringTokenizer(br.readLine());
// 			for(int j=0;j<m;j++) {
// 				board[i][j] = Integer.parseInt(st.nextToken());
// 			}
// 		}
// 		for(int i=0;i<r;i++) {
// 			rotate();
// 		}
// 		for(int i=0;i<n;i++) {
// 			for(int j=0;j<m;j++) {
// 				sb.append(board[i][j]+" ");
// 			}
// 			sb.append("\n");
// 		}
// 		System.out.println(sb);
// 	}
// }
import java.io.*;
import java.util.*;

public class Main {

    static int[][] board = new int[301][301];

    static void rotate(int n, int m) {
        int[][] tmp_board = new int[n][m];
        int sx = 0;
        int sy = 0;
        int ex = n > m ? (m-1)/2 : (n-1)/2;
        int ey = ex;
        int tmp_n = n;
        int tmp_m = m;
        while(sx<=ex) {
            int begin = board[sx][sy];
            for(int j=sy;j<sy+tmp_m-1;j++) {
                tmp_board[sx][j] = board[sx][j+1];
            }
            for(int i=sx;i<sx+tmp_n-1;i++) {
                tmp_board[i][sy+tmp_m-1] = board[i+1][sy+tmp_m-1];
            }
            for(int j=sy+tmp_m-1;j>sy;j--) {
                tmp_board[sx+tmp_n-1][j] = board[sx+tmp_n-1][j-1];
            }
            for(int i=sx+tmp_n-1;i>sx;i--) {
                tmp_board[i][sy] = board[i-1][sy];
            }
            tmp_board[sx+1][sy] = begin;
            sx+=1;
            sy+=1;
            tmp_n-=2;
            tmp_m-=2;
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                board[i][j] = tmp_board[i][j];
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());

        for(int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<m;j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        while(r-->0) rotate(n,m);

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                sb.append(board[i][j]).append(" ");
            }
            sb.append("\n");
        }
        System.out.println(sb.toString());
    }
}

