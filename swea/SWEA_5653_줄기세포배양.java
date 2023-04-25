import java.util.*;
import java.io.*;

public class Solution {
	
	
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] board = new int[901][901];
	static boolean[][] check = new boolean[901][901];
	// x, y, life ,cnt
	static List<int[]> sleep = new ArrayList<>();
	static List<int[]> awake = new ArrayList<>();
	static int answer = 0;
	static int N,M;
	
	static void spread() {
		List<int[]> temp = new ArrayList<>();
		for(int i=0;i<awake.size();i++) {
			int x = awake.get(i)[0]; int y = awake.get(i)[1];
			int life = awake.get(i)[2]; int cnt = awake.get(i)[3];
			for(int j=0;j<4;j++) {
				int nx = x+dx[j];
				int ny = y+dy[j];
				if(check[nx][ny]==true) continue;
				boolean flag = false;
				for(int k=0;k<temp.size();k++) {
					if(temp.get(k)[0]==nx&&temp.get(k)[1]==ny) {
						int c = temp.get(k)[2]; 
						temp.set(k, new int[] {nx,ny,Math.max(c, life)});
						flag = true;
						break;
					}
				}
				if(flag==false) temp.add(new int[] {nx,ny,life});
			}
		}
		for(int i=0;i<temp.size();i++) {
			int x = temp.get(i)[0]; int y = temp.get(i)[1];
			int cnt = temp.get(i)[2];
			sleep.add(new int[] {x,y,cnt,cnt+1});
			check[x][y] = true;
		}
	}
	
	static void aging() {
		for(int i=0;i<awake.size();i++) {
			int x = awake.get(i)[0]; int y = awake.get(i)[1];
			int life = awake.get(i)[2]; int cnt = awake.get(i)[3];
			if(cnt-1==0) {
				awake.remove(i);
				i-=1;
			} else {
				awake.set(i, new int[] {x,y,life,cnt-1});
			}
		}
		for(int i=0;i<sleep.size();i++) {
			int x = sleep.get(i)[0]; int y = sleep.get(i)[1];
			int life = sleep.get(i)[2]; int cnt = sleep.get(i)[3]; 
			if(cnt-1==0) {
				awake.add(new int[] {x,y,life,life});
				sleep.remove(i);
				i-=1;
			} else {
				sleep.set(i, new int[] {x,y,life,cnt-1});
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("data/5653.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			int k = Integer.parseInt(st.nextToken());
			N=n;M=m;
			for(int i=300;i<300+n;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=300;j<300+m;j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
					if(board[i][j]!=0) {
						check[i][j] = true;
						sleep.add(new int[] {i,j,board[i][j],board[i][j]});
					}
				}
			}
			for(int i=0;i<k;i++) {
				spread();
				aging();
			}
			answer = sleep.size()+awake.size();
			sb.append("#"+(ot-t)+" "+answer+"\n");
			sleep.clear();
			awake.clear();
			for(int i=0;i<900;i++) {
				for(int j=0;j<900;j++) {
					check[i][j] = false;
				}
			}
		}
		System.out.println(sb);
	}
}
