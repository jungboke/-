import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main2 {
	
	static List<int[]> a = new ArrayList<>();
	static boolean[] check = new boolean[11];
	static int mini = Integer.MAX_VALUE;
	
	static void dfs(int x, int y, int cnt, int ex, int ey) {
		for(int i=0;i<a.size();i++) {
			if(check[i]==true) continue;
			check[i] = true;
			int nx = a.get(i)[0]; int ny = a.get(i)[1];
			int dist = Math.abs(nx-x)+Math.abs(ny-y);
			dfs(nx,ny,cnt+dist,ex,ey);
			check[i] = false;
		}
		for(int i=0;i<a.size();i++) {
			if(check[i]==false) return;
		}
		mini = Math.min(mini, cnt+Math.abs(x-ex)+Math.abs(y-ey));
	}
	
	public static void main(String[] args) throws IOException {
		System.setIn(new FileInputStream("data/1247.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
			int n = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			int sx = Integer.parseInt(st.nextToken());
			int sy = Integer.parseInt(st.nextToken());
			int ex = Integer.parseInt(st.nextToken());
			int ey = Integer.parseInt(st.nextToken());
			for(int i=0;i<n;i++) {
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				a.add(new int[] {x,y});
			}
			dfs(sx,sy,0,ex,ey);
			sb.append("#"+(ot-t)+" "+mini+"\n");
			a.clear();
			Arrays.fill(check, false);
			mini = Integer.MAX_VALUE;
		}
		System.out.println(sb);
	}
}