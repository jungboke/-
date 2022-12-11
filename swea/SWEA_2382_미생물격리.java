import java.io.*;
import java.util.*;

public class Solution {
	
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,-1,1};
	static List<int[]> gem = new ArrayList<>();
	static int N;
	
	static void move() {
		for(int i=0;i<gem.size();i++) {
			int x = gem.get(i)[0]; int y = gem.get(i)[1];
			int cnt = gem.get(i)[2]; int dir = gem.get(i)[3];
			int nx = x+dx[dir]; int ny = y+dy[dir];
			if(nx==0||ny==0||nx==N-1||ny==N-1) {
				if(cnt/2==0) {
					gem.remove(i);
					i-=1;
				} else {
					cnt/=2;
					if(dir==0) dir = 1;
					else if(dir==1) dir = 0;
					else if(dir==2) dir = 3;
					else if(dir==3) dir = 2;
					gem.set(i, new int[] {nx,ny,cnt,dir});
				}
			} else {
				gem.set(i, new int[] {nx,ny,cnt,dir});
			}
		}
	}
	
	static void union() {
		List<int[]>[][] board = new ArrayList[N][N];
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) board[i][j] = new ArrayList<>();
		}
		for(int i=0;i<gem.size();i++) {
			int x = gem.get(i)[0]; int y = gem.get(i)[1];
			board[x][y].add(gem.get(i));
		}
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(board[i][j].size()<=1) continue;
				int maxi = -1;
				int mdir = -1;
				int sum = 0;
				for(int k=0;k<board[i][j].size();k++) {
					int temp = board[i][j].get(k)[2];
					if(maxi<temp) {
						maxi = temp;
						mdir = board[i][j].get(k)[3];
					}
					sum+=temp;
				}
				for(int k=0;k<gem.size();k++) {
					if(gem.get(k)[0]==i&&gem.get(k)[1]==j) {
						gem.remove(k);
						k-=1;
					}
				}
				gem.add(new int[] {i,j,sum,mdir});
			}
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("data/2382.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			N=n;
			int m = Integer.parseInt(st.nextToken());
			int k = Integer.parseInt(st.nextToken());
			for(int i=0;i<k;i++) {
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				int cnt = Integer.parseInt(st.nextToken());
				int dir = Integer.parseInt(st.nextToken())-1;
				gem.add(new int[] {x,y,cnt,dir});
			}
			for(int i=0;i<m;i++) {
				move();
				union();
			}
			int answer = 0;
			for(int i=0;i<gem.size();i++) {
				answer+=gem.get(i)[2];
			}
			sb.append("#"+(ot-t)+" "+answer+"\n");
			gem.clear();
		}
		System.out.println(sb);
	}
}
