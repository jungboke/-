package com.ssafy.ws;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class SWEA_1873_상호의배틀필드 {
	
	static char[][] board = new char[21][21];
	static char[] cmd = new char[101];
	static int x,y;
	static int N,M;
	
	static void shot(int px, int py, char v) {
		int ex=-1,ey=-1;
		if(v=='<') {
			for(int j=0;j<py;j++) {
				if(board[px][j]=='*') {
					ex = px;
					ey = j;
				} else if(board[px][j]=='#') {
					ex = -1;
					ey = -1;
				}
			}
		} else if(v=='>') {
			for(int j=M-1;j>=py+1;j--) {
				if(board[px][j]=='*') {
					ex = px;
					ey = j;
				} else if(board[px][j]=='#') {
					ex = -1;
					ey = -1;
				}
			}
		} else if(v=='^') {
			for(int i=0;i<px;i++) {
				if(board[i][py]=='*') {
					ex = i;
					ey = py;
				} else if(board[i][py]=='#') {
					ex = -1;
					ey = -1;
				}
			}
		} else if(v=='v') {
			for(int i=N-1;i>=px+1;i--) {
				if(board[i][py]=='*') {
					ex = i;
					ey = py;
				} else if(board[i][py]=='#') {
					ex = -1;
					ey = -1;
				}
			}
		}
		if(!(ex==-1&&ey==-1)) board[ex][ey]='.';
	}
	
	static void move(char px) {
		if(px=='U') {
			board[x][y] = '^';
			if(x-1>=0&&x-1<N&&y>=0&&y<M&&board[x-1][y]=='.') {
				char temp = board[x][y];
				board[x][y] = board[x-1][y];
				board[x-1][y] = temp;
				x-=1;
			}
		} else if(px=='D') {
			board[x][y] = 'v';
			if(x+1>=0&&x+1<N&&y>=0&&y<M&&board[x+1][y]=='.') {
				char temp = board[x][y];
				board[x][y] = board[x+1][y];
				board[x+1][y] = temp;
				x+=1;
			}
		} else if(px=='L') {
			board[x][y] = '<';
			if(x>=0&&x<N&&y-1>=0&&y-1<M&&board[x][y-1]=='.') {
				char temp = board[x][y];
				board[x][y] = board[x][y-1];
				board[x][y-1] = temp;
				y-=1;
			}
		} else if(px=='R') {
			board[x][y] = '>';
			if(x>=0&&x<N&&y+1>=0&&y+1<M&&board[x][y+1]=='.') {
				char temp = board[x][y];
				board[x][y] = board[x][y+1];
				board[x][y+1] = temp;
				y+=1;
			}
		} else if(px=='S') {
			shot(x,y,board[x][y]);
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("data/1873.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			N=n;M=m;
			for(int i=0;i<n;i++) {
				String temp = br.readLine();
				for(int j=0;j<m;j++) {
					board[i][j] = temp.charAt(j);
					if(board[i][j]=='^'||board[i][j]=='<'||board[i][j]=='>'||board[i][j]=='v') {
						x = i;
						y = j;
					}
				}
			}
			int k = Integer.parseInt(br.readLine());
			String k_str = br.readLine();
			for(int i=0;i<k;i++) {
				cmd[i] = k_str.charAt(i);
			}
			int idx = 0;
			while(idx<k) {
				move(cmd[idx++]);
			}
			sb.append("#"+(ot-t)+" ");
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					sb.append(board[i][j]);
				}
				sb.append("\n");
			}
		}
		System.out.println(sb);	
	}
}
