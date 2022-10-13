//import java.io.BufferedReader;
//import java.io.FileInputStream;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Arrays;
//import java.util.List;
//import java.util.StringTokenizer;
//
//public class SWEA_6485_삼성시의 {
//	
//	static int[] a = new int[5001];
//	
//	public static void main(String[] args) throws NumberFormatException, IOException {
//		System.setIn(new FileInputStream("data/6485.txt"));
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		int t = Integer.parseInt(br.readLine());
//		int ot = t;
//		while(t-->0) {
//			int n = Integer.parseInt(br.readLine());
//			for(int i=0;i<n;i++) {
//				st = new StringTokenizer(br.readLine());
//				int x = Integer.parseInt(st.nextToken());
//				int y = Integer.parseInt(st.nextToken());
//				for(int j=x;j<=y;j++) {
//					a[j]+=1;
//				}
//			}
//			int p = Integer.parseInt(br.readLine());
//			sb.append("#"+(ot-t)+" ");
//			for(int i=0;i<p;i++) {
//				int x = Integer.parseInt(br.readLine());
//				sb.append(a[x]+" ");
//			}
//			sb.append("\n");
//			Arrays.fill(a, 0);
//		}
//		System.out.println(sb);
//	}
//}
import java.io.*;
import java.util.*;

public class Solution {
	
	static int[] a = new int[5001];
	
    public static void main(String[] args) throws IOException {
    	System.setIn(new FileInputStream("data/6485.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int t = Integer.parseInt(br.readLine());
        int ot = t;
        while(t-->0) {
        	int n = Integer.parseInt(br.readLine());
        	for(int i=0;i<n;i++) {
        		st = new StringTokenizer(br.readLine());
        		int x = Integer.parseInt(st.nextToken());
        		int y = Integer.parseInt(st.nextToken());
        		for(int j=x;j<=y;j++) a[j]+=1;
        	}
        	sb.append("#"+(ot-t)+" ");
        	int m = Integer.parseInt(br.readLine());
        	for(int i=0;i<m;i++) {
        		int x = Integer.parseInt(br.readLine());
        		sb.append(a[x]+" ");
        	}
        	sb.append("\n");
        	Arrays.fill(a, 0);
        }
        System.out.println(sb);
	}
}
