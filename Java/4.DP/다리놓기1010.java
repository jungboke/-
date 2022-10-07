//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.LinkedList;
//import java.util.Queue;
//import java.util.StringTokenizer;
//
//public class Main {
//	
//	static int[][] d = new int[31][31];
//	
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		int t = Integer.parseInt(br.readLine());
//		for(int i=1;i<=30;i++) {
//			d[i][i] = 1;
//			d[i][1] = i;
//		}
//		for(int i=2;i<=30;i++) {
//			for(int j=i+1;j<=30;j++) {
//				d[j][i] = d[j-1][i-1]+d[j-1][i];
//			}
//		}
//		while(t-->0) {
//			st = new StringTokenizer(br.readLine());
//			int n = Integer.parseInt(st.nextToken());
//			int m = Integer.parseInt(st.nextToken());
//			sb.append(d[m][n]+"\n");
//		}
//		System.out.println(sb);
//	}
//}
import java.io.*;
import java.util.*;

public class Main {
	
	static int[][] d = new int[31][31];
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		for(int i=1;i<=30;i++) {
			d[i][i] = 1;
			d[i][1] = i;
		}
		
		for(int i=2;i<=30;i++) {
			for(int j=i+1;j<=30;j++) {
				d[j][i] = d[j-1][i] + d[j-1][i-1];
			}
		}
		int t = Integer.parseInt(br.readLine());
		while(t-->0) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			sb.append(d[y][x]+"\n");
		}
		System.out.println(sb);
	}
}