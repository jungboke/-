import java.util.*;
import java.io.*;

public class Solution {
	
	static int[][] board = new int[21][21]; 
	static int answer = -1;
	static int N;
	
	static int cal(int x, int y, int l, int r) {
		Set<Integer> s = new HashSet<>();
		int cnt = 0;
		for(int i=0;i<=l;i++) {
			int nx1 = x+i;
			int ny1 = y-i;
			int nx2 = x+r+i;
			int ny2 = y+r-i;
			if(!(nx1>=0&&nx1<N&&ny1>=0&&ny1<N)) return -1;
			if(!(nx2>=0&&nx2<N&&ny2>=0&&ny2<N)) return -1;
			s.add(board[nx1][ny1]);
			s.add(board[nx2][ny2]);
			cnt+=2;
		}
		for(int i=1;i<r;i++) {
			int nx1 = x+i;
			int ny1 = y+i;
			int nx2 = x+l+i;
			int ny2 = y-l+i;
			if(!(nx1>=0&&nx1<N&&ny1>=0&&ny1<N)) return -1;
			if(!(nx2>=0&&nx2<N&&ny2>=0&&ny2<N)) return -1;
			s.add(board[nx1][ny1]);
			s.add(board[nx2][ny2]);
			cnt+=2;
		}
		if(s.size()!=cnt) return -1;
		else return cnt;
	}
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("data/2105.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
			int n = Integer.parseInt(br.readLine());
			N=n;
			for(int i=0;i<n;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<n;j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			for(int c=1;c<=n-1;c++) {
				for(int d=1;d<=n-1;d++) {
					for(int i=0;i<n;i++) {
						for(int j=0;j<n;j++) {
							int result = cal(i,j,c,d);
							answer = Math.max(answer, result);
						}
					}
				}
			}
			sb.append("#"+(ot-t)+" "+answer+"\n");
			answer = -1;
		}
		System.out.println(sb);
	}
}
