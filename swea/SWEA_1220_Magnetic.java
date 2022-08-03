package com.ssafy.ws;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SWEA_1220_Magnetic {
	
	static int[][] board = new int[100][100];
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("data/12001.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = 10;
		int ot = t;
		while(t-->0) {
			int n = Integer.parseInt(br.readLine());
			for(int i=0;i<n;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<n;j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			int answer = 0;
			for(int j=0;j<100;j++) {
				boolean blue = false;
				for(int i=0;i<100;i++) {
					if(board[i][j]==1) blue=true;
					else if(board[i][j]==2) {
						if(blue==true) {
							answer+=1;
							blue=false;
						}
					}
				}
			}
			sb.append("#"+(ot-t)+" "+answer+"\n");
		}
		System.out.println(sb);
	}
}
