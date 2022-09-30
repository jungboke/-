import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
	
	static int[][] board = new int[17][17];
	static int[][][] d = new int[17][17][3];
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		for(int i=1;i<=n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=1;j<=n;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		d[1][2][0] = 1;
		// 0 -> - / 1 -> | / 2 -> 대각
		for(int i=1;i<=n;i++) {
			for(int j=2;j<=n;j++) {
				if(i==1&&j==2) continue;
				if(board[i][j]==1) continue;
				d[i][j][0] = d[i][j-1][0] + d[i][j-1][2];
				d[i][j][1] = d[i-1][j][1] + d[i-1][j][2];
				if(board[i-1][j]==1) continue;
				if(board[i][j-1]==1) continue;
				d[i][j][2] = d[i-1][j-1][0] + d[i-1][j-1][1] + d[i-1][j-1][2];
			}
		}
		System.out.println(sb.append(d[n][n][0]+d[n][n][1]+d[n][n][2]));
	}
}