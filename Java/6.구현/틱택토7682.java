import java.util.*;
import java.io.*;

public class Main {
	/*
	 * 흰색과 검은색의 차이는 항상 1
	 * 흰색과 검은색 중 하나가 성공했다면 나머지 하나는 성공못함
	 * 둘다 성공못했다면 9칸은 다 채운 상태여야함
	 * 성공상태에서 그룹은 무조건 1개
	 */
	static char[][] board = new char[3][3];
	static boolean[][] check = new boolean[3][3];
	
	static int[] tictakCheck() {
		int xcnt = 0; int ocnt = 0;
		// ROW
		for(int i=0;i<3;i++) {
			int cnt = 1;
			outer:for(int j=1;j<3;j++) {
				if(board[i][j]==board[i][j-1]&&board[i][j]!='.') cnt+=1;
				else cnt = 1;
				if(cnt==3) {
					for(int k=0;k<3;k++) {
						if(check[i][j-k]==true) continue outer;
					}
					if(board[i][j]=='X') xcnt+=1;
					else ocnt+=1;
					for(int k=0;k<3;k++) {
						check[i][j-k] = true;
					}
				}
			}
		}
		// COL
		for(int j=0;j<3;j++) {
			int cnt = 1;
			outer:for(int i=1;i<3;i++) {
				if(board[i][j]==board[i-1][j]&&board[i][j]!='.') cnt+=1;
				else cnt = 1;
				if(cnt==3) {
					for(int k=0;k<3;k++) {
						if(check[i-k][j]==true) continue outer;
					}
					if(board[i][j]=='X') xcnt+=1;
					else ocnt+=1;
					for(int k=0;k<3;k++) {
						check[i-k][j] = true;
					}
				}
			}
		}
		// RIGHT DOWN DIG
		int cnt = 0;
		char now = ' ';
		outer:for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				if(i-j==0) {
					if((board[i][j]==now||now==' ')&&board[i][j]!='.') {
						cnt+=1;
						now = board[i][j];
					} else cnt = 0;
				}
				if(cnt==3) {
					for(int k=0;k<3;k++) {
						if(check[i-k][j-k]==true) break outer;
					}
					if(board[i][j]=='X') xcnt+=1;
					else ocnt+=1;
					for(int k=0;k<3;k++) {
						check[i-k][j-k] = true;
					}
					break outer;
				}
			}
		}
		// RIGHT UP DIG
		cnt = 0;
		now = ' ';
		outer:for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				if(i+j==2) {
					if((board[i][j]==now||now==' ')&&board[i][j]!='.') {
						cnt+=1;
						now = board[i][j];
					} else cnt = 0;
				}
				if(cnt==3) {
					for(int k=0;k<3;k++) {
						if(check[i-k][j+k]==true) break outer;
					}
					if(board[i][j]=='X') xcnt+=1;
					else ocnt+=1;
					for(int k=0;k<3;k++) {
						check[i-k][j+k] = true;
					}
					break outer;
				}
			}
		}
		return new int[] {xcnt,ocnt};
	}
	
	static boolean boardCheck() {
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) check[i][j] = false;
		}
		int black = 0; int white = 0; int blank = 0;
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				if(board[i][j]=='O') white+=1;
				else if(board[i][j]=='X') black+=1;
				else blank+=1;
			}
		}
		int[] now = tictakCheck();
		if(!(black-white==0||black-white==1)) return false;
		if(now[0]!=0&&now[1]!=0) return false;
		if(now[0]==0&&now[1]==0) {
			if(blank!=0) return false;
		}
		if(now[0]>1||now[1]>1) return false;
		if(now[0]==1&&black-white!=1) return false;
		if(now[1]==1&&black-white!=0) return false;
		return true;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		while(true) {
			String temp = br.readLine();
			if(temp.equals("end")) break;
			for(int i=0;i<9;i++) {
				int x = i/3; int y = i%3;
				board[x][y] = temp.charAt(i);
			}
			if(boardCheck()) sb.append("valid"+"\n");
			else sb.append("invalid"+"\n");
		}
		System.out.println(sb);
	}
}
