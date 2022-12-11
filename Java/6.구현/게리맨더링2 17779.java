//import java.io.*;
//import java.util.*;
//
//public class Main {
//
//	static int[][] board = new int[21][21];
//	static int mini = Integer.MAX_VALUE;
//	static int total = 0;
//	static int N;
//	
//	static void cal(int x, int y, int left, int right) {
//		boolean[][] bound = new boolean[N][N];
//		for(int i=0;i<=left;i++) {
//			bound[x+i][y-i] = true;
//			bound[x+right+i][y+right-i] = true;
//		}
//		for(int i=0;i<=right;i++) {
//			bound[x+i][y+i] = true;
//			bound[x+left+i][y-left+i] = true;
//		}
//		List<Integer> temp = new ArrayList<>();
//		int sum = 0;
//		for(int i=0;i<x+left;i++) {
//			for(int j=0;j<=y;j++) {
//				if(bound[i][j]==true) break;
//				sum+=board[i][j];
//			}
//		}
//		temp.add(sum);
//		sum = 0;
//		for(int i=0;i<=x+right;i++) {
//			for(int j=N-1;j>y;j--) {
//				if(bound[i][j]==true) break;
//				sum+=board[i][j];
//			}
//		}
//		temp.add(sum);
//		sum = 0;
//		for(int i=x+left;i<N;i++) {
//			for(int j=0;j<y-left+right;j++) {
//				if(bound[i][j]==true) break;
//				sum+=board[i][j];
//			}
//		}
//		temp.add(sum);
//		sum = 0;
//		for(int i=x+right+1;i<N;i++) {
//			for(int j=N-1;j>=y-left+right;j--) {
//				if(bound[i][j]==true) break;
//				sum+=board[i][j];
//			}
//		}
//		temp.add(sum);
//		int sum_sum = 0;
//		for(int i=0;i<temp.size();i++) {
//			sum_sum+=temp.get(i);
//		}
//		temp.add(total-sum_sum);
//		mini = Math.min(mini, Collections.max(temp)-Collections.min(temp));
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
//				total+=board[i][j];
//			}
//		}
//		for(int i=0;i<n;i++) {
//			for(int j=0;j<n;j++) {
//				for(int k=1;k<n;k++) {
//					for(int l=1;l<n;l++) {
//						if(i+k+l>=n) continue;
//						if(j-k<0||j+l>=n) continue;
//						cal(i,j,k,l);
//					}
//				}
//			}
//		}
//		System.out.println(sb.append(mini));
//	}
//}
import java.io.*;
import java.util.*;

public class Main {
	
	static int[][] board = new int[21][21];
	static boolean[][] check = new boolean[21][21];
	static int answer = Integer.MAX_VALUE;
	static int N;
	
	static void make_bound(int x, int y, int c, int d) {
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) check[i][j] = false;
		}
		for(int i=0;i<=c;i++) {
			check[x+i][y-i] = true;
			check[x+d+i][y+d-i] = true;
		}
		for(int i=0;i<=d;i++) {
			check[x+i][y+i] = true;
			check[x+c+i][y-c+i] = true;
		}
	}
	
	static int cal(int x, int y, int c, int d, int total) {
		make_bound(x,y,c,d);
		List<Integer> result = new ArrayList<>();
		//1
		int sum = 0;
		for(int i=0;i<x+c;i++) {
			for(int j=0;j<=y;j++) {
				if(check[i][j]==true) break;
				sum+=board[i][j];
			}
		}
		result.add(sum);
		total-=sum;
		//2
		sum = 0;
		for(int i=0;i<=x+d;i++) {
			for(int j=N-1;j>y;j--) {
				if(check[i][j]==true) break;
				sum+=board[i][j];
			}
		}
		result.add(sum);
		total-=sum;
		//3
		sum = 0;
		for(int i=x+c;i<N;i++) {
			for(int j=0;j<y-c+d;j++) {
				if(check[i][j]==true) break;
				sum+=board[i][j];
			}
		}
		result.add(sum);
		total-=sum;
		//4
		sum = 0;
		for(int i=x+d+1;i<N;i++) {
			for(int j=N-1;j>=y-c+d;j--) {
				if(check[i][j]==true) break;
				sum+=board[i][j];
			}
		}
		result.add(sum);
		total-=sum;
		//5
		result.add(total);
		return Collections.max(result)-Collections.min(result);
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		N=n;
		int total = 0;
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<n;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				total+=board[i][j];
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				for(int c=1;c<n;c++) {
					for(int d=1;d<n;d++) {
						if(i+c+d>=n) continue;
						if(j-c<0||j+d>=n) continue;
						answer = Math.min(answer, cal(i,j,c,d,total));
					}
				}
			}
		}
		System.out.println(sb.append(answer));
	}
}

