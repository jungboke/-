//import java.io.BufferedReader;
//import java.io.FileInputStream;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Arrays;
//import java.util.Collections;
//import java.util.Comparator;
//import java.util.LinkedList;
//import java.util.List;
//import java.util.Queue;
//import java.util.StringTokenizer;
//
//public class Solution {
//	
//	public static void main(String[] args) throws NumberFormatException, IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		int t = Integer.parseInt(br.readLine());
//		int ot = t;
//		while(t-->0) {
//			st = new StringTokenizer(br.readLine());
//			int x1 = Integer.parseInt(st.nextToken());
//			int y1 = Integer.parseInt(st.nextToken());
//			int x2 = Integer.parseInt(st.nextToken());
//			int y2 = Integer.parseInt(st.nextToken());
//			int col = Math.abs(x1-x2);
//			int row = Math.abs(y1-y2);
//			int answer = 0;
//			if(row>col) {
//				int temp = row; row = col; col = temp;
//			}
//			if(row==col) answer = row+col;
//			else if(row==0) {
//				if(col%2==0) answer = col+col;
//				else answer = col+col-1;
//			}
//			else {
//				if(row%2==0) {
//					if(col%2==0) answer = col+col;
//					else answer = col+col-1;
//				} else {
//					if(col%2==0) answer = col+col-1;
//					else answer = col+col;
//				}
//			}
//			sb.append("#"+(ot-t)+" "+answer+"\n");
//		}
//		System.out.println(sb);
//	}
//}
import java.io.*;
import java.util.*;

public class Solution {
	
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][][] dist = new int[201][201][2];
	static final int N = 200;
	static final int INF = 10000000;
	
	// 0 세로 , 1 가로
	static int bfs(int sx, int sy, int ex, int ey) {
		for(int i=0;i<=N;i++) {
			for(int j=0;j<=N;j++) {
				for(int k=0;k<=1;k++) dist[i][j][k] = INF;
			}
		}
		Queue<int[]> q = new LinkedList<>();
		q.offer(new int[] {sx,sy,0});
		q.offer(new int[] {sx,sy,1});
		dist[sx][sy][0] = 1;
		dist[sx][sy][1] = 1;
		while(!q.isEmpty()) {
			int[] now = q.poll();
			int x = now[0]; int y = now[1]; int z = now[2];
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx>=0&&nx<=N&&ny>=0&&ny<=N) {
					if(i%2==0&&z==0&&dist[nx][ny][1]==INF) {
						q.offer(new int[] {nx,ny,1});
						dist[nx][ny][1] = dist[x][y][z]+1;
					} else if(i%2==1&&z==1&&dist[nx][ny][0]==INF) {
						q.offer(new int[] {nx,ny,0});
						dist[nx][ny][0] = dist[x][y][z]+1;
					}
				}
			}
		}
		return Math.min(dist[ex][ey][0],dist[ex][ey][1])-1;
	}
	
    public static void main(String[] args) throws IOException {
    	System.setIn(new FileInputStream("data/8382.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int t = Integer.parseInt(br.readLine());
        int ot = t;
        while(t-->0) {
        	st = new StringTokenizer(br.readLine());
        	int sx = Integer.parseInt(st.nextToken())+100;
        	int sy = Integer.parseInt(st.nextToken())+100;
        	int ex = Integer.parseInt(st.nextToken())+100;
        	int ey = Integer.parseInt(st.nextToken())+100;
        	sb.append("#"+(ot-t)+" "+bfs(sx,sy,ex,ey)+"\n");
        }
        System.out.println(sb);
	}
}