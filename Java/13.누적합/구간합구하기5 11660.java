import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

 	static int[][] board = new int[1025][1025];
 	static int[][] d = new int[1025][1025];
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		for(int i=1;i<=n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=1;j<=n;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				d[i][j] = d[i-1][j]+d[i][j-1]-d[i-1][j-1]+board[i][j];
			}
		}
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int x1 = Integer.parseInt(st.nextToken());
			int y1 = Integer.parseInt(st.nextToken());
			int x2 = Integer.parseInt(st.nextToken());
			int y2 = Integer.parseInt(st.nextToken());
			int sum = d[x2][y2]-d[x1-1][y2]-d[x2][y1-1]+d[x1-1][y1-1];
			sb.append(sum+"\n");
		}
		System.out.println(sb);
	}
}