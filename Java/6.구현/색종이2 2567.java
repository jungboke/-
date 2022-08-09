import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] board = new int[101][101];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			for(int c=x;c<x+10;c++) {
				for(int d=y;d<y+10;d++) {
					board[c][d] = 1;
				}
			}
		}
		int answer = 0;
		for(int i=0;i<=100;i++) {
			for(int j=0;j<=100;j++) {
				if(board[i][j]==0) continue;
				for(int k=0;k<4;k++) {
					int nx = i+dx[k];
					int ny = j+dy[k];
					if(nx>=0&&nx<=100&&ny>=0&&ny<=100&&board[nx][ny]==0) {
						answer+=1;
					}
				}
			}
		}
		System.out.println(sb.append(answer));
	}
}