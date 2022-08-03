import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int INF = 1000000000;
	static int[][] board = new int[16][16];
	static List<int[]> enemy = new ArrayList<>();
	static int maxi = -1;
	static int N,M,D;

	static int kill(List<Integer> temp, List<int[]> tmp_enemy) {
		int result = 0;
		HashSet<Integer> s = new HashSet<>();
		for(int c=0;c<temp.size();c++) {
			int mini = INF;
			int min_idx = -1;
			for(int i=0;i<tmp_enemy.size();i++) {
				int x = tmp_enemy.get(i)[0];
				int y = tmp_enemy.get(i)[1];
				int dist = Math.abs(x-N)+Math.abs(y-temp.get(c));
				if(mini>=dist&&dist<=D) {
					if(mini==dist&&y>=tmp_enemy.get(min_idx)[1]) {
						continue;
					}
					mini = dist;
					min_idx = i;
				}
			}
			if(min_idx!=-1) s.add(min_idx);
		}
		for(int k:s) {
			tmp_enemy.set(k, new int[] {-1,-1});
			result+=1;
		}
		for(int i=0;i<tmp_enemy.size();i++) {
			if(tmp_enemy.get(i)[0]==-1&&tmp_enemy.get(i)[1]==-1) {
				tmp_enemy.remove(i);
				i-=1;
			}
		}
		return result;
	}

	static void move(List<int[]> tmp_enemy) {
		for(int i=0;i<tmp_enemy.size();i++) {
			int[] temp = tmp_enemy.get(i);
			tmp_enemy.set(i, new int[] {temp[0]+1,temp[1]});
			if(temp[0]+1>=N) {
				tmp_enemy.remove(i);
				i-=1;
			}
		}
	}

	static void dfs(List<Integer> temp, int start) {
		if(temp.size()==3) {
			int result = 0;
			List<int[]> tmp_enemy = new ArrayList<>(enemy);
			while(!tmp_enemy.isEmpty()) {
				result+=kill(temp,tmp_enemy);
				move(tmp_enemy);
			}
			maxi = Math.max(maxi, result);
		}
		for(int i=start;i<M;i++) {
			temp.add(i);
			dfs(temp,i+1);
			temp.remove(temp.size()-1);
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		N=n;M=m;
		int d = Integer.parseInt(st.nextToken());
		D=d;
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<m;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				if(board[i][j]==1) {
					enemy.add(new int[] {i,j});
				}
			}
		}
		List<Integer> temp = new ArrayList<>();
		dfs(temp,0);
		System.out.println(sb.append(maxi+"\n"));
	}
}


