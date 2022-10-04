import java.io.*;
import java.util.*;

public class Main {

	static int[][] board = new int[10][10];
	static List<Integer>[] row = new ArrayList[10];
	static List<Integer>[] col = new ArrayList[10];
	static List<Integer>[][] box = new ArrayList[10][10];
	
	static boolean sdoku_check(int x, int y, int k) {
		if(row[x].contains(k)) return false;
		if(col[y].contains(k)) return false;
		if(box[x/3][y/3].contains(k)) return false;
		return true;
	}
	
	static boolean dfs() {
		boolean flag = false;
		for(int i=0;i<9;i++) {
			for(int j=0;j<9;j++) {
				if(board[i][j]!=0) continue;
				flag = true;
				for(int k=1;k<=9;k++) {
					if(!sdoku_check(i,j,k)) continue;
					board[i][j] = k;
					row[i].add(k);
					col[j].add(k);
					box[i/3][j/3].add(k);
					if(dfs()) return true;
					board[i][j]=0;
					row[i].remove(row[i].size()-1);
					col[j].remove(col[j].size()-1);
					box[i/3][j/3].remove(box[i/3][j/3].size()-1);
				}
				if(board[i][j]==0) return false;
			}
		}
		if(flag==false) {
			return true;
		}
		return false;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		for(int i=0;i<9;i++) {
			row[i] = new ArrayList<>();
			col[i] = new ArrayList<>();
			for(int j=0;j<9;j++) {
				box[i][j] = new ArrayList<>();
			}
		}
		for(int i=0;i<9;i++) {
			String temp = br.readLine();
			for(int j=0;j<9;j++) {
				board[i][j] = temp.charAt(j)-'0';
				if(board[i][j]!=0) {
					row[i].add(board[i][j]);
					col[j].add(board[i][j]);
					box[i/3][j/3].add(board[i][j]);					
				}
			}
		}
		dfs();
		for(int i=0;i<9;i++) {
			for(int j=0;j<9;j++) {
				sb.append(board[i][j]);
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
}