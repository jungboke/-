import java.io.*;
import java.util.*;

public class Main {
	
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,1,0,-1};
	static int[][] board = new int[51][51];
	static boolean[][] check = new boolean[51][51];
	static int answer = 0;
	static int N,M;
	
	static int[] move(int sx, int sy, int d) {
		if(check[sx][sy]==false) answer+=1;
		check[sx][sy] = true;
		for(int i=0;i<4;i++) {
			d-=1;
			if(d==-1) d = 3;
			int nx = sx+dx[d];
			int ny = sy+dy[d];
			if(nx>=0&&nx<N&&ny>=0&&ny<M&&check[nx][ny]==false) {
				if(board[nx][ny]==0) {
					return new int[] {nx,ny,d};
				}
			}
		}
		sx-=dx[d];
		sy-=dy[d];
		if(sx>=0&&sx<N&&sy>=0&&sy<M&&board[sx][sy]==0) return new int[] {sx,sy,d};
		else return new int[] {-1,-1,d};
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		N=n;M=m;
		st = new StringTokenizer(br.readLine());
		int sx = Integer.parseInt(st.nextToken());
		int sy = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<m;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		while(true) {
			int[] now = move(sx,sy,d);
			sx = now[0]; sy = now[1]; d = now[2];
			if(sx==-1&&sy==-1) break;
		}
		System.out.println(sb.append(answer));
	}
}