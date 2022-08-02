import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static List<Integer>[] man = new ArrayList[500];
	static int[][] desk = new int[21][21];
	static int[][] how = new int[21][21];
	static int N;

	static int[] desk_check(int x, int y, int v) {
		int f_cnt = 0;
		int z_cnt = 0;
		for(int i=0;i<4;i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx>=0&&nx<N&&ny>=0&&ny<N) {
				if(man[v].contains(desk[nx][ny])) f_cnt+=1;
				if(desk[nx][ny]==0) z_cnt+=1;
			}
		}
		return new int[] {f_cnt,z_cnt};
	}

	static int cal() {

	}

	public static void main(String[] args) throws Exception, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;


		int n = Integer.parseInt(br.readLine());
		N=n;
		for(int i=0;i<Math.pow(n, 2)+1;i++) {
			man[i] = new ArrayList<>();
		}
		List<Integer> a = new ArrayList<>();
		for(int i=0;i<Math.pow(n, 2);i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			a.add(x);
			for(int j=0;j<4;j++) {
				int y = Integer.parseInt(st.nextToken());
				man[x].add(y);
			}
		}
		// temp[0] : friend cnt / temp[1] : zero cnt
		for(int c=0;c<a.size();c++) {
			int f_max = 0;
			int z_max = 0;
			int mx=0,my=0;
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					if(desk[i][j]!=0) continue;
					int[] temp = desk_check(i,j,a.get(c));
					if(temp[0]>f_max) {
						f_max = temp[0];
						z_max = temp[1];
						mx = i;
						my = j;
					} else if(temp[0]==f_max) {
						if(temp[1]>z_max) {
							z_max = temp[1];
							mx = i;
							my = j;
						}
					}
				}
			}
			desk[mx][my] = a.get(c);
			how[mx][my] = f_max;
		}
		answer = cal();
		System.out.println(sb.append(answer+"\n"));
	}
}
