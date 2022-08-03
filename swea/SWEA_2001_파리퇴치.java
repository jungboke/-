package com.ssafy.ws;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SWEA_2001_파리퇴치 {
	
	static int[][] board = new int[16][16];
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("data/2001.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			for(int i=0;i<n;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<n;j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			int maxi = -1;
			for(int i=0;i<n-m+1;i++) {
				for(int j=0;j<n-m+1;j++) {
					int sum = 0;
					for(int c=0;c<m;c++) {
						for(int d=0;d<m;d++) {
							sum+=board[i+c][j+d];
						}
					}
					maxi = Math.max(maxi, sum);
				}
			}
			sb.append("#"+(ot-t)+" "+maxi+"\n");
		}
		System.out.println(sb);
	}
}
