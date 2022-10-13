//import java.io.BufferedReader;
//import java.io.FileInputStream;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.List;
//import java.util.StringTokenizer;
//
//public class SWEA_5643_키순서 {
//	
//	static int[][] a = new int[501][501];
//	
//    public static void main(String[] args) throws IOException {
//        System.setIn(new FileInputStream("data/5643.txt"));
//    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        StringBuilder sb = new StringBuilder();
//        StringTokenizer st;
//
//        int t = Integer.parseInt(br.readLine());
//        int ot = t;
//        while(t-->0) {
//        	int n = Integer.parseInt(br.readLine());
//        	for(int i=1;i<=n;i++) {
//        		for(int j=1;j<=n;j++) a[i][j] = 0;
//        	}
//        	int m = Integer.parseInt(br.readLine());
//        	for(int i=0;i<m;i++) {
//        		st = new StringTokenizer(br.readLine());
//        		int x = Integer.parseInt(st.nextToken());
//        		int y = Integer.parseInt(st.nextToken());
//        		a[y][x] = 1;
//        	}
//        	for(int c=1;c<=n;c++) {
//        		for(int i=1;i<=n;i++) {
//        			for(int j=1;j<=n;j++) {
//        				if(i==j) continue;
//        				if(a[i][c]==1&&a[c][j]==1) {
//        					a[i][j] = 1;
//        				}
//        			}
//        		}
//        	}
//        	int answer = 0;
//        	for(int i=1;i<=n;i++) {
//        		int cnt = 0;
//        		for(int j=1;j<=n;j++) {
//        			if(i==j) continue;
//        			if(a[i][j]==1||a[j][i]==1) cnt+=1;
//        		}
//        		if(cnt==n-1) answer+=1; 
//        	}
//        	sb.append("#"+(ot-t)+" "+answer+"\n");
//        }
//        System.out.println(sb);
//     }
//}
import java.io.*;
import java.util.*;

public class Solution {
	
	static int[][] a = new int[501][501];
	
    public static void main(String[] args) throws IOException {
    	System.setIn(new FileInputStream("data/5643.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int t = Integer.parseInt(br.readLine());
        int ot = t;
        while(t-->0) {
        	int n = Integer.parseInt(br.readLine());
        	int m = Integer.parseInt(br.readLine());
        	for(int i=0;i<m;i++) {
        		st = new StringTokenizer(br.readLine());
        		int x = Integer.parseInt(st.nextToken());
        		int y = Integer.parseInt(st.nextToken());
        		a[x][y] = 1;
        	}
        	for(int c=1;c<=n;c++) {
        		for(int i=1;i<=n;i++) {
        			for(int j=1;j<=n;j++) {
        				if(a[i][c]==1&&a[c][j]==1) {
        					a[i][j] = 1;
        				}
        			}
        		}
        	}
        	int answer = 0;
        	for(int i=1;i<=n;i++) {
        		int cnt = 0;
        		for(int j=1;j<=n;j++) {
        			if(i==j) continue;
        			if(a[i][j]==1||a[j][i]==1) cnt+=1;
        		}
        		if(cnt==n-1) answer+=1; 
        	}
        	sb.append("#"+(ot-t)+" "+answer+"\n");
        	for(int i=1;i<=n;i++) {
        		for(int j=1;j<=n;j++) a[i][j] = 0;
        	}
        }
        System.out.println(sb);
	}
}