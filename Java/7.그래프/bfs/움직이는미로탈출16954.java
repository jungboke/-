//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Arrays;
//import java.util.Collections;
//import java.util.HashSet;
//import java.util.LinkedList;
//import java.util.List;
//import java.util.Queue;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	static int[] dx = {0,0,-1,-1,-1,0,1,1,1};
//	static int[] dy = {0,-1,-1,0,1,1,1,0,-1};
//	static List<int[]> a = new ArrayList<>();
//	static boolean[][] check = new boolean[8][8];
//	static int answer = 0;
//
//	static void move() {
//		for(int i=0;i<a.size();i++) {
//			int x = a.get(i)[0];
//			int y = a.get(i)[1];
//			if(x+1<8) a.set(i, new int[] {x+1,y});
//			else {
//				a.remove(i);
//				i-=1;
//			}
//		}
//	}
//
//	static boolean wall_check(int x, int y) {
//		for(int i=0;i<a.size();i++) {
//			if((a.get(i)[0]==x&&a.get(i)[1]==y)) return true;
//			if((a.get(i)[0]+1==x&&a.get(i)[1]==y)) return true;
//		}
//		return false;
//	}
//
//	static int bfs(int sx, int sy, int ex, int ey) {
//		Queue<int[]> q = new LinkedList<>();
//		q.offer(new int[] {sx,sy});
//		check[sx][sy] = true;
//		int t = 0;
//		while(!q.isEmpty()) {
//			if(t>7) return 1;
//			int cnt = q.size();
//			for(int c=0;c<cnt;c++) {
//				int[] now = q.poll();
//				int x = now[0]; int y = now[1];
//				for(int i=0;i<9;i++) {
//					int nx = x+dx[i];
//					int ny = y+dy[i];
//					if(nx>=0&&nx<8&&ny>=0&&ny<8) {
//						if(!(wall_check(nx,ny))) {
//							q.offer(new int[] {nx,ny});
//						}
//					}
//				}
//			}
//			move();
//			t+=1;
//		}
//		return 0;
//	}
//
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//
//		for(int i=0;i<8;i++) {
//			String temp = br.readLine();
//			for(int j=0;j<8;j++) {
//				if(temp.charAt(j)=='#') {
//					a.add(new int[] {i,j});
//				}
//			}
//		}
//		int sx = 7; int sy = 0;
//		int ex = 0; int ey = 7;
//		System.out.println(sb.append(bfs(sx,sy,ex,ey)));
//	}
//}
import java.io.*;
import java.util.*;

public class Main {
		
	static class Pair {
		int x;
		int y;
		Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
		public boolean equals(Object o) {
			Pair p = (Pair) o;
			if(p.x==this.x&&p.y==this.y) return true;
			else return false;
		}
	}
	
	static int[] dx = {0,0,-1,-1,-1,0,1,1,1};
	static int[] dy = {0,-1,-1,0,1,1,1,0,-1};
	static List<Pair> wall = new ArrayList<>();
	
	static void wall_move() {
		List<Pair> tmp_wall = new ArrayList<>();
		for(int i=0;i<wall.size();i++) {
			int x = wall.get(i).x;
			int y = wall.get(i).y;
			if(x+1<8) tmp_wall.add(new Pair(x+1,y));
		}
		wall = tmp_wall;
	}
	
	static int bfs() {
		Queue<Pair> q = new LinkedList<>();
		q.add(new Pair(7,0));
		while(!q.isEmpty()) {
			if(wall.isEmpty()) return 1;
			int cnt = q.size();
			for(int c=0;c<cnt;c++) {
				Pair p = q.poll();
				int x = p.x; int y = p.y;
				if(wall.contains(new Pair(x,y))) continue;
				if(x==0&&y==7) return 1;
				for(int i=0;i<9;i++) {
					int nx = x+dx[i];
					int ny = y+dy[i];
					if(nx>=0&&nx<8&&ny>=0&&ny<8) {
						if(wall.contains(new Pair(nx,ny))) continue;
						q.offer(new Pair(nx,ny));
					}
				}
			}
			wall_move();
		}
		return 0;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		for(int i=0;i<8;i++) {
			String temp = br.readLine();
			for(int j=0;j<8;j++) {
				if(temp.charAt(j)=='#') {
					wall.add(new Pair(i,j));
				}
			}
		}
		System.out.println(sb.append(bfs()));
	}
}
