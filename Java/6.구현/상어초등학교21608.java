//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.List;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	static int[] dx = {0,-1,0,1};
//	static int[] dy = {-1,0,1,0};
//	static List<Integer>[] man = new ArrayList[500];
//	static int[][] desk = new int[21][21];
//	static int N;
//
//	static int[] desk_check(int x, int y, int v) {
//		int f_cnt = 0;
//		int z_cnt = 0;
//		for(int i=0;i<4;i++) {
//			int nx = x+dx[i];
//			int ny = y+dy[i];
//			if(nx>=0&&nx<N&&ny>=0&&ny<N) {
//				if(man[v].contains(desk[nx][ny])) f_cnt+=1;
//				if(desk[nx][ny]==0) z_cnt+=1;
//			}
//		}
//		return new int[] {f_cnt,z_cnt};
//	}
//
//	public static void main(String[] args) throws Exception, IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//
//
//		int n = Integer.parseInt(br.readLine());
//		N=n;
//		for(int i=0;i<Math.pow(n, 2)+1;i++) {
//			man[i] = new ArrayList<>();
//		}
//		List<Integer> a = new ArrayList<>();
//		for(int i=0;i<Math.pow(n, 2);i++) {
//			st = new StringTokenizer(br.readLine());
//			int x = Integer.parseInt(st.nextToken());
//			a.add(x);
//			for(int j=0;j<4;j++) {
//				int y = Integer.parseInt(st.nextToken());
//				man[x].add(y);
//			}
//		}
//		// temp[0] : friend cnt / temp[1] : zero cnt
//		for(int c=0;c<a.size();c++) {
//			int f_max = -1;
//			int z_max = -1;
//			int mx=0,my=0;
//			for(int i=0;i<n;i++) {
//				for(int j=0;j<n;j++) {
//					if(desk[i][j]!=0) continue;
//					int[] temp = desk_check(i,j,a.get(c));
//					if(temp[0]>f_max) {
//						f_max = temp[0];
//						z_max = temp[1];
//						mx = i;
//						my = j;
//					} else if(temp[0]==f_max) {
//						if(temp[1]>z_max) {
//							z_max = temp[1];
//							mx = i;
//							my = j;
//						}
//					}
//				}
//			}
//			desk[mx][my] = a.get(c);
//		}
//		int answer = 0;
//		for(int i=0;i<n;i++) {
//			for(int j=0;j<n;j++) {
//				int[] temp = desk_check(i,j,desk[i][j]);
//				if(temp[0]==0) answer+=0;
//				else if(temp[0]==1) answer+=1;
//				else if(temp[0]==2) answer+=10;
//				else if(temp[0]==3) answer+=100;
//				else if(temp[0]==4) answer+=1000;
//			}
//		}
//		System.out.println(sb.append(answer+"\n"));
//	}
//}
//
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] board = new int[21][21];
	static List<Integer>[][] friend = new ArrayList[21][21];
	static int N;
	
	static void sit(int x, List<Integer> temp) {
		int maxi = -1;
		int maxi_zero = -1;
		int[] maxi_idx = new int[] {-1,-1};
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(board[i][j]!=0) continue;
				int zero = 0;
				int cnt = 0;
				for(int k=0;k<4;k++) {
					int nx = i+dx[k];
					int ny = j+dy[k];
					if(nx>=0&&nx<N&&ny>=0&&ny<N) {
						if(temp.contains(board[nx][ny])) cnt+=1;
						if(board[nx][ny]==0) zero+=1;
					}
				}
				if(maxi<cnt||(maxi==cnt&&maxi_zero<zero)) {
					maxi = cnt;
					maxi_zero = zero;
					maxi_idx = new int[] {i,j};
				}
			}
		}
		board[maxi_idx[0]][maxi_idx[1]] = x;
		friend[maxi_idx[0]][maxi_idx[1]] = temp;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		N=n;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				friend[i][j] = new ArrayList<>();
			}
		}
		for(int i=0;i<Math.pow(n,2);i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			List<Integer> temp = new ArrayList<>();
			for(int j=0;j<4;j++) {
				int y = Integer.parseInt(st.nextToken());
				temp.add(y);
			}
			sit(x,temp);
		}
		int answer = 0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				int cnt = 0;
				for(int k=0;k<4;k++) {
					int nx = i+dx[k];
					int ny = j+dy[k];
					if(nx>=0&&nx<n&&ny>=0&&ny<n) {
						if(friend[i][j].contains(board[nx][ny])) cnt+=1;
					}
				}
				if(cnt==0) {
					answer+=0;
				} else if(cnt==1) {
					answer+=1;
				} else if(cnt==2) {
					answer+=10;
				} else if(cnt==3) {
					answer+=100;
				} else if(cnt==4) {
					answer+=1000;
				}
			}
		}
		System.out.println(sb.append(answer));
	}
}