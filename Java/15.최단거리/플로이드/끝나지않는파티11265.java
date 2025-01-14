//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Collections;
//import java.util.List;
//import java.util.PriorityQueue;
//import java.util.Stack;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	static int[][] a = new int[501][501];
//
//	public static void main(String[] args) throws NumberFormatException, IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//
//		st = new StringTokenizer(br.readLine());
//		int n = Integer.parseInt(st.nextToken());
//		int m = Integer.parseInt(st.nextToken());
//		for(int i=1;i<=n;i++) {
//			st = new StringTokenizer(br.readLine());
//			for(int j=1;j<=n;j++) {
//				a[i][j] = Integer.parseInt(st.nextToken());
//			}
//		}
//		for(int c=1;c<=n;c++) {
//			for(int i=1;i<=n;i++) {
//				for(int j=1;j<=n;j++) {
//					if(a[i][j]>a[i][c]+a[c][j]) {
//						a[i][j] = a[i][c]+a[c][j];
//					}
//				}
//			}
//		}
//		for(int i=0;i<m;i++) {
//			st = new StringTokenizer(br.readLine());
//			int x = Integer.parseInt(st.nextToken());
//			int y = Integer.parseInt(st.nextToken());
//			int z = Integer.parseInt(st.nextToken());
//			if(a[x][y]>z) sb.append("Stay here"+"\n");
//			else sb.append("Enjoy other party"+"\n");
//		}
//		System.out.println(sb);
//	}
//}
//
// import java.io.*;
// import java.util.*;

// public class Main {
	
// 	static int[][] a = new int[501][501];
	
// 	public static void main(String[] args) throws NumberFormatException, IOException {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;
		
// 		st = new StringTokenizer(br.readLine());
// 		int n = Integer.parseInt(st.nextToken());
// 		int m = Integer.parseInt(st.nextToken());
// 		for(int i=1;i<=n;i++) {
// 			st = new StringTokenizer(br.readLine());
// 			for(int j=1;j<=n;j++) {
// 				a[i][j] = Integer.parseInt(st.nextToken());
// 			}
// 		}
// 		for(int c=1;c<=n;c++) {
// 			for(int i=1;i<=n;i++) {
// 				for(int j=1;j<=n;j++) {
// 					if(i==j) continue;
// 					if(a[i][j]>a[i][c]+a[c][j]) {
// 						a[i][j] = a[i][c]+a[c][j];
// 					}
// 				}
// 			}
// 		}
// 		for(int i=0;i<m;i++) {
// 			st = new StringTokenizer(br.readLine());
// 			int x = Integer.parseInt(st.nextToken());
// 			int y = Integer.parseInt(st.nextToken());
// 			int z = Integer.parseInt(st.nextToken());
// 			if(a[x][y]<=z) sb.append("Enjoy other party"+"\n");
// 			else sb.append("Stay here"+"\n");
// 		}
// 		System.out.println(sb);
// 	}
// }
// import java.util.*;
// import java.io.*;

// public class Main {
	
// 	static int[][] board = new int[501][501];
	
// 	public static void main(String[] args) throws NumberFormatException, IOException {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;
		
// 		st = new StringTokenizer(br.readLine());
// 		int n = Integer.parseInt(st.nextToken());
// 		int m = Integer.parseInt(st.nextToken());
// 		for(int i=1;i<=n;i++) {
// 			st = new StringTokenizer(br.readLine());
// 			for(int j=1;j<=n;j++) {
// 				board[i][j] = Integer.parseInt(st.nextToken());
// 			}
// 		}
// 		for(int c=1;c<=n;c++) {
// 			for(int i=1;i<=n;i++) {
// 				for(int j=1;j<=n;j++) {
// 					if(i==j) continue;
// 					board[i][j] = Math.min(board[i][j], board[i][c]+board[c][j]);
// 				}
// 			}
// 		}
// 		for(int i=1;i<=m;i++) {
// 			st = new StringTokenizer(br.readLine());
// 			int x = Integer.parseInt(st.nextToken());
// 			int y = Integer.parseInt(st.nextToken());
// 			int z = Integer.parseInt(st.nextToken());
// 			if(board[x][y]<=z) sb.append("Enjoy other party"+"\n");
// 			else sb.append("Stay here"+"\n");
// 		}
// 		System.out.println(sb);
// 	}
// }
import java.io.*;
import java.util.*;

public class Main {

    static int[][] board = new int[501][501];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        for(int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<n;j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for(int c=0;c<n;c++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(board[i][j]>board[i][c]+board[c][j]) {
                        board[i][j] = board[i][c]+board[c][j];
                    }
                }
            }
        }
        for(int i=0;i<m;i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken())-1;
            int y = Integer.parseInt(st.nextToken())-1;
            int z = Integer.parseInt(st.nextToken());
            if(board[x][y]>z) {
                sb.append("Stay here").append("\n");
            } else {
                sb.append("Enjoy other party").append("\n");
            }
        }

        System.out.println(sb.toString());
    }
}

