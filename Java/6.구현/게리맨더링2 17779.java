import java.io.*;
import java.util.*;

public class Main {

	static int[][] board = new int[21][21];
	static int mini = Integer.MAX_VALUE;
	static int total = 0;
	static int N;
	
	static void cal(int x, int y, int left, int right) {
		boolean[][] bound = new boolean[N][N];
		for(int i=0;i<=left;i++) {
			bound[x+i][y-i] = true;
			bound[x+right+i][y+right-i] = true;
		}
		for(int i=0;i<=right;i++) {
			bound[x+i][y+i] = true;
			bound[x+left+i][y-left+i] = true;
		}
		List<Integer> temp = new ArrayList<>();
		int sum = 0;
		for(int i=0;i<x+left;i++) {
			for(int j=0;j<=y;j++) {
				if(bound[i][j]==true) break;
				sum+=board[i][j];
			}
		}
		temp.add(sum);
		sum = 0;
		for(int i=0;i<=x+right;i++) {
			for(int j=N-1;j>y;j--) {
				if(bound[i][j]==true) break;
				sum+=board[i][j];
			}
		}
		temp.add(sum);
		sum = 0;
		for(int i=x+left;i<N;i++) {
			for(int j=0;j<y-left+right;j++) {
				if(bound[i][j]==true) break;
				sum+=board[i][j];
			}
		}
		temp.add(sum);
		sum = 0;
		for(int i=x+right+1;i<N;i++) {
			for(int j=N-1;j>=y-left+right;j--) {
				if(bound[i][j]==true) break;
				sum+=board[i][j];
			}
		}
		temp.add(sum);
		int sum_sum = 0;
		for(int i=0;i<temp.size();i++) {
			sum_sum+=temp.get(i);
		}
		temp.add(total-sum_sum);
		mini = Math.min(mini, Collections.max(temp)-Collections.min(temp));
	} 
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		N=n;
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<n;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				total+=board[i][j];
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				for(int k=1;k<n;k++) {
					for(int l=1;l<n;l++) {
						if(i+k+l>=n) continue;
						if(j-k<0||j+l>=n) continue;
						cal(i,j,k,l);
					}
				}
			}
		}
		System.out.println(sb.append(mini));
	}
}
