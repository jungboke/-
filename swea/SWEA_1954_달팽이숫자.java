//package com.ssafy.ws;
//
//
//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.PriorityQueue;
//import java.util.StringTokenizer;
//import java.util.TreeMap;
//
//public class SWEA_1954_달팽이숫자 {
//	public static void main(String[] args) throws NumberFormatException, IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		int t = Integer.parseInt(br.readLine());
//		int ot = t;
//		while(t-->0) {
//			int n = Integer.parseInt(br.readLine());
//			int[][] a = new int[n][n];
//			int nx = 0;
//			int ny = 0;
//			int cnt = n-1;
//			int num = 1;
//			a[nx][ny] = num++;
//			while(cnt>0) {
//				for(int i=0;i<cnt;i++) {
//					ny+=1;
//					a[nx][ny] = num++; 
//				}
//				for(int i=0;i<cnt;i++) {
//					nx+=1;
//					a[nx][ny] = num++; 
//				}
//				for(int i=0;i<cnt;i++) {
//					ny-=1;
//					a[nx][ny] = num++; 
//				}
//				for(int i=0;i<cnt-1;i++) {
//					nx-=1;
//					a[nx][ny] = num++; 
//				}
//				if(cnt-2>=0) {
//					ny+=1;
//					a[nx][ny] = num++;
//				}
//				cnt-=2;
//			}
//			sb.append("#"+(ot-t)+"\n");
//			for(int i=0;i<n;i++) {
//				for(int j=0;j<n;j++) {
//					sb.append(a[i][j]+" ");
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
	
	static int[][] board = new int[11][11];
	
    public static void main(String[] args) throws IOException {
    	System.setIn(new FileInputStream("data/1954.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int t = Integer.parseInt(br.readLine());
        int ot = t;
        while(t-->0) {
        	int n = Integer.parseInt(br.readLine());
        	int x=0,y=0;
        	int row = n-1;
        	int cnt = 1;
        	while(row>=1) {
        		board[x][y] = cnt++;
        		for(int i=0;i<row;i++) {
        			y+=1;
        			board[x][y] = cnt++;
        		}
        		for(int i=0;i<row;i++) {
        			x+=1;
        			board[x][y] = cnt++;
        		}
        		for(int i=0;i<row;i++) {
        			y-=1;
        			board[x][y] = cnt++;
        		}
        		for(int i=0;i<row-1;i++) {
        			x-=1;
        			board[x][y] = cnt++;
        		}
        		y+=1;
        		row-=2;
        	}
        	if(row==0) board[x][y] = cnt++;
        	sb.append("#"+(ot-t)+"\n");
        	for(int i=0;i<n;i++) {
        		for(int j=0;j<n;j++) {
        			sb.append(board[i][j]+" ");
        		}
        		sb.append("\n");
        	}
        }
        System.out.println(sb);
	}
}