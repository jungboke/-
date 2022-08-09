import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class SWEA_1861_정사각형방 {
	
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] a = new int[1001][1001];
	static int N;
	static int maxi;
	static int max_idx;
	
	static void move(int x, int y, int cnt, int target) {
		for(int i=0;i<4;i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx>=0&&nx<N&&ny>=0&&ny<N) {
				if(a[nx][ny]==a[x][y]+1) {
					move(nx,ny,cnt+1,target);
				}
			}
		}
		if(maxi<=cnt) {
			if(maxi==cnt&&max_idx>target) {
				max_idx = target;
			}
			else if(maxi<cnt) {
				maxi = cnt;
				max_idx = target;
			}
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("data/1861.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t= Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
			int n = Integer.parseInt(br.readLine());
			N=n;
			for(int i=0;i<n;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<n;j++) {
					a[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					move(i,j,1,a[i][j]);
				}
			}
			sb.append("#"+(ot-t)+" "+max_idx+" "+maxi+"\n");
			maxi = -1;
			max_idx = -1;
		}
		System.out.println(sb);
	}
}
