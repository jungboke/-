import java.io.*;
import java.util.*;

public class Main {

	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static List<int[]> a = new ArrayList<>();
	static boolean[] check = new boolean[101];
	static int N;
	
	static String bfs(int sx, int sy, int ex, int ey) {
		for(int i=0;i<N;i++) check[i] = false;
		Queue<int[]> q = new LinkedList<>();
		q.offer(new int[] {sx,sy});
		while(!q.isEmpty()) {
			int[] now = q.poll();
			int x = now[0]; int y = now[1];
			if(Math.abs(ex-x)+Math.abs(ey-y)<=1000) return "happy";
			for(int i=0;i<a.size();i++) {
				if(check[i]==true) continue;
				int nx = a.get(i)[0]; int ny = a.get(i)[1];
				if(Math.abs(nx-x)+Math.abs(ny-y)<=1000) {
					q.offer(new int[] {nx,ny});
					check[i] = true;
				}
			}
		}
		return "sad";
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		while(t-->0) {
			int n = Integer.parseInt(br.readLine());
			N=n;
			int sx=-1,sy=-1,ex=-1,ey=-1;
			st = new StringTokenizer(br.readLine());
			sx = Integer.parseInt(st.nextToken());
			sy = Integer.parseInt(st.nextToken());
			for(int i=0;i<n;i++) {
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				a.add(new int[] {x,y});
			}
			st = new StringTokenizer(br.readLine());
			ex = Integer.parseInt(st.nextToken());
			ey = Integer.parseInt(st.nextToken());
			sb.append(bfs(sx,sy,ex,ey)+"\n");
			a.clear();
		}
		System.out.println(sb);
	}
}