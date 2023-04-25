import java.util.*;
import java.io.*;

public class Solution {
	
	static int[][] board = new int[11][11];
	static int N,M,C;
	static int answer = Integer.MIN_VALUE;
	
	static int cal(int sx, int sy) {
		int result = 0;
		List<Integer> temp = new ArrayList<>();
		for(int i=0;i<M;i++) {
			temp.add(board[sx][sy+i]);
		}
		for(int i=0;i<(1<<M);i++) {
			int resultMulSum = 0;
			int resultSum = 0;
			for(int j=0;j<M;j++) {
				if((i&(1<<j))!=0) {
					resultMulSum+=Math.pow(temp.get(j), 2);
					resultSum+=temp.get(j);
				}
			}
			if(resultSum<=C) {
				result = Math.max(result, resultMulSum);
			}
		}
		return result;
	}
	
	static void select() {
		for(int i=0;i<N*N;i++) {
			if(i+M-1>=N*N) continue;
			int sx = i/N; int sy = i%N;
			int sx2 = (i+M-1)/N;
			if(sx!=sx2) continue;
			int firstSum = cal(sx,sy);
			for(int j=i+M;j<N*N;j++) {
				if(j+M-1>=N*N) continue;
				int ex = j/N; int ey = j%N;
				int ex2 = (j+M-1)/N;
				if(ex!=ex2) continue;
				int secondSum = cal(ex,ey);
				answer = Math.max(answer, firstSum+secondSum);
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("data/2115.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			N=n;M=m;C=c;
			for(int i=0;i<n;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<n;j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			select();
			sb.append("#"+(ot-t)+" "+answer+"\n");
			answer = Integer.MIN_VALUE;
		}
		System.out.println(sb);
	}
}
