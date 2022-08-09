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
	
	static boolean[][] board = new boolean[100][100];
	
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
					board[c][d] = true;
				}
			}
		}
		int answer = 0;
		for(int i=0;i<100;i++) {
			for(int j=0;j<100;j++) {
				if(board[i][j]==true) answer+=1;
			}
		}
		System.out.println(sb.append(answer));
	}
}