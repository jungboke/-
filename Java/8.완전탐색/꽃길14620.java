//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Arrays;
//import java.util.Collections;
//import java.util.LinkedList;
//import java.util.List;
//import java.util.Queue;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	static int dx[] = {0,0,-1,0,1};
//	static int dy[] = {0,-1,0,1,0};
//	static int[][] board = new int[11][11];
//	static boolean[][] check = new boolean[11][11];
//	static List<Integer> result = new ArrayList<>();
//	static int N;
//
//	static boolean flower(int px, int py) {
//		int cnt = 0;
//		for(int i=0;i<5;i++) {
//			int nx = px+dx[i];
//			int ny = py+dy[i];
//			if(nx>=0&&nx<N&&ny>=0&&ny<N) {
//				if(check[nx][ny]==false) {
//					cnt+=1;
//				}
//			}
//		}
//		if(cnt!=5) return false;
//		else return true;
//	}
//
//	static void dfs(int sum, int cnt) {
//		if(cnt==3) {
//			result.add(sum);
//			return;
//		}
//		for(int i=0;i<N;i++) {
//			for(int j=0;j<N;j++) {
//				if(flower(i,j)) {
//					for(int k=0;k<5;k++) {
//						int nx = i+dx[k];
//						int ny = j+dy[k];
//						check[nx][ny] = true;
//						sum+=board[nx][ny];
//
//					}
//					dfs(sum,cnt+1);
//					for(int k=0;k<5;k++) {
//						int nx = i+dx[k];
//						int ny = j+dy[k];
//						check[nx][ny] = false;
//						sum-=board[nx][ny];
//					}
//				}
//			}
//		}
//	}
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
//		dfs(0,0);
//		int answer = Collections.min(result);
//		System.out.println(sb.append(answer+"\n"));
//	}
//}
// import java.io.BufferedReader;
// import java.io.IOException;
// import java.io.InputStreamReader;
// import java.util.ArrayList;
// import java.util.List;
// import java.util.Stack;
// import java.util.StringTokenizer;
// import java.util.TreeSet;

// public class Main {
	
// 	static int[] dx = {0,0,-1,0,1};
// 	static int[] dy = {0,-1,0,1,0};
// 	static int[][] board = new int[11][11];
// 	static int mini = Integer.MAX_VALUE;
// 	static boolean[][] check = new boolean[11][11];
// 	static int N;
	
// 	static boolean block_check(int x, int y) {
// 		for(int k=0;k<5;k++) {
// 			int nx = x+dx[k];
// 			int ny = y+dy[k];
// 			if(!(nx>=0&&nx<N&&ny>=0&&ny<N)) return false;
// 			if(check[nx][ny]==true) return false;
// 		}
// 		return true;
// 	}
	
// 	static void dfs(int cnt) {
// 		if(cnt==3) {
// 			int sum = 0;
// 			for(int i=0;i<N;i++) {
// 				for(int j=0;j<N;j++) {
// 					if(check[i][j]==true) sum+=board[i][j];
// 				}
// 			}
// 			mini = Math.min(mini, sum);
// 			return;
// 		}
// 		for(int i=0;i<N;i++) {
// 			for(int j=0;j<N;j++) {
// 				if(block_check(i,j)) {
// 					for(int k=0;k<5;k++) {
// 						int nx = i+dx[k];
// 						int ny = j+dy[k];
// 						check[nx][ny] = true;
// 					}
// 					dfs(cnt+1);
// 					for(int k=0;k<5;k++) {
// 						int nx = i+dx[k];
// 						int ny = j+dy[k];
// 						check[nx][ny] = false;
// 					}
// 				}
// 			}
// 		}
// 	}
	
// 	public static void main(String[] args) throws NumberFormatException, IOException {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;
		
// 		int n = Integer.parseInt(br.readLine());
// 		N=n;
// 		for(int i=0;i<n;i++) {
// 			st = new StringTokenizer(br.readLine());
// 			for(int j=0;j<n;j++) {
// 				board[i][j] = Integer.parseInt(st.nextToken());
// 			}
// 		}
// 		dfs(0);
// 		System.out.println(sb.append(mini));
// 	}
// }
import java.io.*;
import java.util.*;

public class Main {

    static int[] dx = {0,0,-1,0,1};
    static int[] dy = {0,-1,0,1,0};

    static int[][] board = new int[11][11];

    static int answer = Integer.MAX_VALUE;

    static boolean func(List<int[]> temp, int n) {
        boolean[][] visit = new boolean[n][n];
        for(int i=0;i<3;i++) {
            int x = temp.get(i)[0];
            int y = temp.get(i)[1];
            for(int j=0;j<5;j++) {
                int nx = x+dx[j];
                int ny = y+dy[j];
                if(nx>=0&&nx<n&&ny>=0&&ny<n) {
                    if(visit[nx][ny]==false) visit[nx][ny] = true;
                    else return false;
                } else return false;
            }
        }
        return true;
    }

    static int cal(List<int[]> temp, int n) {
        int result = 0;
        for(int i=0;i<temp.size();i++) {
            int x = temp.get(i)[0];
            int y = temp.get(i)[1];
            for(int j=0;j<5;j++) {
                int nx = x+dx[j];
                int ny = y+dy[j];
                result+=board[nx][ny];
            }
        }
        return result;
    }

    static void dfs(int n, int ex, List<int[]> temp) {
        if(temp.size()==3) {
            if(func(temp,n)) {
                answer = Math.min(answer, cal(temp,n));
            }
            return;
        }
        for(int i=ex;i<n*n;i++) {
            int x = i/n;
            int y = i%n;
            temp.add(new int[]{x,y});
            dfs(n,i,temp);
            temp.remove(temp.size()-1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        for(int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<n;j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        List<int[]> temp = new ArrayList<>();
        dfs(n,0,temp);

        System.out.println(sb.append(answer));
    }
}

