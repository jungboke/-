import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] board = new int[51][51];
	static int N,M;

	static void spread() {
		int[][] tmp_board = new int[N][M];
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(board[i][j]!=-1&&board[i][j]!=0) {
					for(int k=0;k<4;k++) {
						int nx = i+dx[k];
						int ny = j+dy[k];
						if(nx>=0&&nx<N&&ny>=0&&ny<M&&board[nx][ny]!=-1) {
							tmp_board[nx][ny]+=board[i][j]/5;
							tmp_board[i][j]-=board[i][j]/5;
						}
					}
				}
			}
		}
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				board[i][j]+=tmp_board[i][j];
			}
		}
	}

	static void cycle1(int x, int y) {
		int[][] tmp_board = board.clone();
		for(int i=x;i>0;i--) {
			tmp_board[i][y] = board[i-1][y];
		}
		for(int j=0;j<M-1;j++) {
			tmp_board[0][j] = board[0][j+1];
		}
		for(int i=0;i<x;i++) {
			tmp_board[i][M-1] = board[i+1][M-1];
		}
		for(int j=M-1;j>0;j--) {
			tmp_board[x][j] = board[x][j-1];
		}
		tmp_board[x][y] = -1;
		tmp_board[x][y+1] = 0;
		board = tmp_board.clone();
	}

	static void cycle2(int x, int y) {
		int[][] tmp_board = board.clone();
		for(int i=x;i<N-1;i++) {
			tmp_board[i][y] = board[i+1][y];
		}
		for(int j=0;j<M-1;j++) {
			tmp_board[N-1][j] = board[N-1][j+1];
		}
		for(int i=N-1;i>x;i--) {
			tmp_board[i][M-1] = board[i-1][M-1];
		}
		for(int j=M-1;j>0;j--) {
			tmp_board[x][j] = board[x][j-1];
		}
		tmp_board[x][y] = -1;
		tmp_board[x][y+1] = 0;
		board = tmp_board.clone();
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		N=n;M=m;
		int t = Integer.parseInt(st.nextToken());
		int x1=-1,y1=-1,x2=-1,y2=-1;
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<m;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				if(board[i][j]==-1) {
					if(x1==-1&&y1==-1) {
						x1 = i; y1 = j;
					} else x2 = i; y2 = j;
				}
			}
		}
		while(t-->0) {
			spread();
			cycle1(x1,y1);
			cycle2(x2,y2);
		}
		int answer = 0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				answer += board[i][j];
			}
		}
		System.out.println(sb.append(answer+2));
	}
}
