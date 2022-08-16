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
	
	static class Pair {
		long x;
		String y;
		Pair(long x, String y) {
			this.x = x;
			this.y = y;
		}
	}
	
	static List<Long> check = new ArrayList<>();
	static final int INF = 1000000000;
	static int answer = 0;
	
	static String bfs(long sx, long ex) {
		if(sx==ex) return Integer.toString(0);
		Queue<Pair> q = new LinkedList<>();
		q.offer(new Pair(sx,""));
		check.add(sx);
		while(!q.isEmpty()) {
			Pair now = q.poll();
			long x = now.x; String y = now.y;
			if(x==ex) {
				return y; 
			}
			if(x*x<=INF&&check.contains(x*x)==false) {
				q.offer(new Pair(x*x,y+"*"));
				check.add(x*x);
			}
			if(x+x<=INF&&check.contains(x+x)==false) {
				q.offer(new Pair(x+x,y+"+"));
				check.add(x+x);
			}
			if(x-x>=1&&check.contains(x-x)==false) {
				q.offer(new Pair(x-x,y+"-"));
				check.add(x-x);
			}
			if(x!=0&&x/x>=1&&check.contains(x/x)==false) {
				q.offer(new Pair(x/x,y+"/"));
				check.add(x/x);
			}
		}
		return Integer.toString(-1);
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int s = Integer.parseInt(st.nextToken());
		int t = Integer.parseInt(st.nextToken());
		System.out.println(sb.append(bfs(s,t)));
	}
}