//package com.ssafy.ws;
//
//import java.io.BufferedReader;
//import java.io.FileInputStream;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.Arrays;
//import java.util.StringTokenizer;
//
//public class SWEA_1873_상호의배틀필드 {
//	
//	static char[][] board = new char[21][21];
//	static char[] cmd = new char[101];
//	static int x,y;
//	static int N,M;
//	
//	static void shot(int px, int py, char v) {
//		int ex=-1,ey=-1;
//		if(v=='<') {
//			for(int j=0;j<py;j++) {
//				if(board[px][j]=='*') {
//					ex = px;
//					ey = j;
//				} else if(board[px][j]=='#') {
//					ex = -1;
//					ey = -1;
//				}
//			}
//		} else if(v=='>') {
//			for(int j=M-1;j>=py+1;j--) {
//				if(board[px][j]=='*') {
//					ex = px;
//					ey = j;
//				} else if(board[px][j]=='#') {
//					ex = -1;
//					ey = -1;
//				}
//			}
//		} else if(v=='^') {
//			for(int i=0;i<px;i++) {
//				if(board[i][py]=='*') {
//					ex = i;
//					ey = py;
//				} else if(board[i][py]=='#') {
//					ex = -1;
//					ey = -1;
//				}
//			}
//		} else if(v=='v') {
//			for(int i=N-1;i>=px+1;i--) {
//				if(board[i][py]=='*') {
//					ex = i;
//					ey = py;
//				} else if(board[i][py]=='#') {
//					ex = -1;
//					ey = -1;
//				}
//			}
//		}
//		if(!(ex==-1&&ey==-1)) board[ex][ey]='.';
//	}
//	
//	static void move(char px) {
//		if(px=='U') {
//			board[x][y] = '^';
//			if(x-1>=0&&x-1<N&&y>=0&&y<M&&board[x-1][y]=='.') {
//				char temp = board[x][y];
//				board[x][y] = board[x-1][y];
//				board[x-1][y] = temp;
//				x-=1;
//			}
//		} else if(px=='D') {
//			board[x][y] = 'v';
//			if(x+1>=0&&x+1<N&&y>=0&&y<M&&board[x+1][y]=='.') {
//				char temp = board[x][y];
//				board[x][y] = board[x+1][y];
//				board[x+1][y] = temp;
//				x+=1;
//			}
//		} else if(px=='L') {
//			board[x][y] = '<';
//			if(x>=0&&x<N&&y-1>=0&&y-1<M&&board[x][y-1]=='.') {
//				char temp = board[x][y];
//				board[x][y] = board[x][y-1];
//				board[x][y-1] = temp;
//				y-=1;
//			}
//		} else if(px=='R') {
//			board[x][y] = '>';
//			if(x>=0&&x<N&&y+1>=0&&y+1<M&&board[x][y+1]=='.') {
//				char temp = board[x][y];
//				board[x][y] = board[x][y+1];
//				board[x][y+1] = temp;
//				y+=1;
//			}
//		} else if(px=='S') {
//			shot(x,y,board[x][y]);
//		}
//	}
//	
//	public static void main(String[] args) throws NumberFormatException, IOException {
//		System.setIn(new FileInputStream("data/1873.txt"));
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		int t = Integer.parseInt(br.readLine());
//		int ot = t;
//		while(t-->0) {
//			st = new StringTokenizer(br.readLine());
//			int n = Integer.parseInt(st.nextToken());
//			int m = Integer.parseInt(st.nextToken());
//			N=n;M=m;
//			for(int i=0;i<n;i++) {
//				String temp = br.readLine();
//				for(int j=0;j<m;j++) {
//					board[i][j] = temp.charAt(j);
//					if(board[i][j]=='^'||board[i][j]=='<'||board[i][j]=='>'||board[i][j]=='v') {
//						x = i;
//						y = j;
//					}
//				}
//			}
//			int k = Integer.parseInt(br.readLine());
//			String k_str = br.readLine();
//			for(int i=0;i<k;i++) {
//				cmd[i] = k_str.charAt(i);
//			}
//			int idx = 0;
//			while(idx<k) {
//				move(cmd[idx++]);
//			}
//			sb.append("#"+(ot-t)+" ");
//			for(int i=0;i<n;i++) {
//				for(int j=0;j<m;j++) {
//					sb.append(board[i][j]);
//				}
//				sb.append("\n");
//			}
//		}
//		System.out.println(sb);	
//	}
//}
import java.io.*;
import java.util.*;

public class Solution {
	
	static char[][] board = new char[101][101];
	static int sx=-1,sy=-1;
	static int N,M;
	
	static void play(char x) {
		if(x=='U') {
			board[sx][sy] = '^';
			if(sx-1>=0&&board[sx-1][sy]=='.') {
				char temp = board[sx-1][sy];
				board[sx-1][sy] = board[sx][sy];
				board[sx][sy] = temp;
				sx-=1;
			}
		} else if(x=='D') {
			board[sx][sy] = 'v';
			if(sx+1<N&&board[sx+1][sy]=='.') {
				char temp = board[sx+1][sy];
				board[sx+1][sy] = board[sx][sy];
				board[sx][sy] = temp;
				sx+=1;
			}
		} else if(x=='L') {
			board[sx][sy] = '<';
			if(sy-1>=0&&board[sx][sy-1]=='.') {
				char temp = board[sx][sy-1];
				board[sx][sy-1] = board[sx][sy];
				board[sx][sy] = temp;
				sy-=1;
			}
		} else if(x=='R') {
			board[sx][sy] = '>';
			if(sy+1<M&&board[sx][sy+1]=='.') {
				char temp = board[sx][sy+1];
				board[sx][sy+1] = board[sx][sy];
				board[sx][sy] = temp;
				sy+=1;
			}
		} else if(x=='S') {
			int idx = 1;
			if(board[sx][sy]=='^') {
				while(sx-idx>=0) {
					if(board[sx-idx][sy]=='#') break;
					if(board[sx-idx][sy]=='*') {
						board[sx-idx][sy] = '.';
						break;
					}
					idx+=1;
				}
			} else if(board[sx][sy]=='v') {
				while(sx+idx<N) {
					if(board[sx+idx][sy]=='#') break;
					if(board[sx+idx][sy]=='*') {
						board[sx+idx][sy] = '.';
						break;
					}
					idx+=1;
				}
			} else if(board[sx][sy]=='<') {
				while(sy-idx>=0) {
					if(board[sx][sy-idx]=='#') break;
					if(board[sx][sy-idx]=='*') {
						board[sx][sy-idx] = '.';
						break;
					}
					idx+=1;
				}
			} else if(board[sx][sy]=='>') {
				while(sy+idx<M) {
					if(board[sx][sy+idx]=='#') break;
					if(board[sx][sy+idx]=='*') {
						board[sx][sy+idx] = '.';
						break;
					}
					idx+=1;
				}
			}
		}
	}
	
    public static void main(String[] args) throws IOException {
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
        			if(board[i][j]=='<'||board[i][j]=='>'||board[i][j]=='^'||board[i][j]=='v') {
        				sx = i; sy = j;
        			}
        		}
        	}
        	int k = Integer.parseInt(br.readLine());
        	char[] cmd = br.readLine().toCharArray();
        	for(int i=0;i<k;i++) {
        		play(cmd[i]);
        	}
        	sb.append("#"+(ot-t)+" ");
        	for(int i=0;i<n;i++) {
        		for(int j=0;j<m;j++) {
        			sb.append(board[i][j]);
        		}
        		sb.append("\n");
        	}
        	sx=-1;sy=-1;
        }
        System.out.println(sb);
     }
}
