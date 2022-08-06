import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int[][] board = new int[1025][1025];

	static void dfs(int n, int px, int py) {
		if(n==2) {
			List<Integer> temp = new ArrayList<>();
			temp.add(board[px][py]);
			temp.add(board[px+1][py]);
			temp.add(board[px+1][py+1]);
			temp.add(board[px][py+1]);
			Collections.sort(temp);
			board[px/2][py/2] = temp.get(2);
			return;
		}
		dfs(n/2,px,py);
		dfs(n/2,px+n/2,py);
		dfs(n/2,px,py+n/2);
		dfs(n/2,px+n/2,py+n/2);
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
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
		while(n!=1) {
			dfs(n,0,0);
			n/=2;
		}
		System.out.println(sb.append(board[0][0]));
	}
}
