import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static List<int[]> home = new ArrayList<>();
	static List<int[]> chicken = new ArrayList<>();
	static int mini = Integer.MAX_VALUE;

	static int cal(List<int[]> temp) {
		int result = 0;
		for(int i=0;i<home.size();i++) {
			int sum = Integer.MAX_VALUE;
			for(int j=0;j<temp.size();j++) {
				int dist = Math.abs(home.get(i)[0]-temp.get(j)[0]) +
						Math.abs(home.get(i)[1]-temp.get(j)[1]);
				sum = Math.min(sum, dist);
			}
			result+=sum;
		}
		return result;
	}

	static void dfs(List<int[]> temp, int start, int limit) {
		if(temp.size()==limit) {
			mini = Math.min(mini,cal(temp));
			return;
		}
		for(int i=start;i<chicken.size();i++) {
			temp.add(chicken.get(i));
			dfs(temp,i+1,limit);
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
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<n;j++) {
				int x = Integer.parseInt(st.nextToken());
				if(x==1) home.add(new int[] {i,j});
				else if(x==2) chicken.add(new int[] {i,j});
			}
		}
		List<int[]> temp = new ArrayList<>();
		dfs(temp,0,m);
		System.out.println(sb.append(mini));
	}
}
