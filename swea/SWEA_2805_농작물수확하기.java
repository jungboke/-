package com.ssafy.ws;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SWEA_2805_농작물수확하기 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("data/2805.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
			int n = Integer.parseInt(br.readLine());
			int[][] board = new int[n][n];
			for(int i=0;i<n;i++) {
				String temp = br.readLine();
				for(int j=0;j<n;j++) {
					board[i][j] = temp.charAt(j)-'0';
				}
			}
			int x = 0;
			int y = n/2;
			int how = 1;
			int sum = 0;
			while(x<=n/2) {
				for(int i=0;i<how;i++) {
					sum += board[x][y+i];
				}
				x+=1;
				y-=1;
				how+=2;
			}
			how-=4;
			y+=2;
			while(x<n) {
				for(int i=0;i<how;i++) {
					sum += board[x][y+i];
				}
				x+=1;
				y+=1;
				how-=2;
			}
			sb.append("#"+(ot-t)+" "+sum+"\n");
		}
		System.out.println(sb);
	}
}
