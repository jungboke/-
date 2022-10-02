//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.lang.reflect.Array;
//import java.util.Arrays;
//import java.util.LinkedList;
//import java.util.Queue;
//import java.util.StringTokenizer;
//
//public class Main {
//	
//	static boolean[][] check = new boolean[1503][1503]; 
//	
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		Queue<int[]> q = new LinkedList<>();
//		
//		st = new StringTokenizer(br.readLine()," ");
//		int a = Integer.parseInt(st.nextToken());
//		int b = Integer.parseInt(st.nextToken());
//		int c = Integer.parseInt(st.nextToken());
//		int sum = a+b+c;
//		q.offer(new int[] {a,b});
//		check[a][b] = true;
//		while(!q.isEmpty()) {
//			int[] now = q.poll();
//			int x = now[0], y = now[1];
//			int z = sum-x-y;
//			if((x==y)&&(y==z)&&(x==z)) {
//				System.out.println(sb.append(1).append("\n"));
//				return;
//			}
//			if(x>y) {
//				if(x-y>=1&&y*2>=1&&check[x-y][y*2]==false) {
//					q.offer(new int[] {x-y,y*2});
//					check[x-y][y*2] = true;
//				}
//			} else {
//				if(x*2>=1&&y-x>=1&&check[x*2][y-x]==false) {
//					q.offer(new int[] {x*2,y-x});
//					check[x*2][y-x] = true;
//				}
//			}
//			if(y>z) {
//				if(x>=1&&y-z>=1&&check[x][y-z]==false) {
//					q.offer(new int[] {x,y-z});
//					check[x][y-z] = true;
//				}
//			} else {
//				if(x>=1&&y*2>=1&&check[x][y*2]==false) {
//					q.offer(new int[] {x,y*2});
//					check[x][y*2] = true;
//				}
//			}
//			if(x>z) {
//				if(x-z>=1&&y>=1&&check[x-z][y]==false) {
//					q.offer(new int[] {x-z,y});
//					check[x-z][y] = true;
//				}
//			} else {
//				if(2*x>=1&&y>=1&&check[2*x][y]==false) {
//					q.offer(new int[] {2*x,y});
//					check[2*x][y] = true;
//				}
//			}
//		}
//		System.out.println(sb.append(0).append("\n"));
//	}
//}
import java.io.*;
import java.util.*;

public class Main {
		
	static boolean[][] check = new boolean[1501][1501];
	
	static int bfs(int a, int b, int c) {
		int sum = a+b+c;
		Queue<int[]> q = new LinkedList<>();
		q.offer(new int[] {a,b});
		check[a][b] = true;
		while(!q.isEmpty()) {
			int[] now = q.poll();
			int x=now[0],y=now[1],z=sum-x-y;
			if(x==y&&y==z) return 1;
			if(x>y&&check[x-y][y+y]==false) {
				q.offer(new int[] {x-y,y+y});
				check[x-y][y+y] = true;
			} 
			if(x<y&&check[x+x][y-x]==false) {
				q.offer(new int[] {x+x,y-x});
				check[x+x][y-x] = true;
			} 
			if(x>z&&check[x-z][y]==false) {
				q.offer(new int[] {x-z,y});
				check[x-z][y] = true;
			} 
			if(x<z&&check[x+x][y]==false) {
				q.offer(new int[] {x+x,y});
				check[x+x][y] = true;
			} 
			if(y>z&&check[x][y-z]==false) {
				q.offer(new int[] {x,y-z});
				check[x][y-z] = true;
			} 
			if(y<z&&check[x][y+y]==false) {
				q.offer(new int[] {x,y+y});
				check[x][y+y] = true;
			}
		}
		return 0;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		System.out.println(sb.append(bfs(a,b,c)));
	}
}