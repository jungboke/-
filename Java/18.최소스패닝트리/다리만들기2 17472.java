import java.io.*;
import java.util.*;

public class Main {
	
	static class Edge {
		int from;
		int to;
		int cost;
		Edge(int from, int to, int cost) {
			this.from = from;
			this.to = to;
			this.cost = cost;
		}
	}
	static PriorityQueue<Edge> pq = new PriorityQueue<>(new Comparator<Edge>() {
		public int compare(Edge o1, Edge o2) {
			return (o1.cost-o2.cost);
		}
	});
	
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] board = new int[101][101];
	static boolean[][] check = new boolean[101][101];
	static List<List<int[]>> island = new ArrayList<>();
	static List<Edge>[] a = new ArrayList[10];
	static int[] parent = new int[10];
	static boolean[] island_check = new boolean[10];
	static int N,M;
	static int answer = 0;
	
	static void bfs2(List<int[]> si, List<int[]> ei, int xidx, int yidx) {
		int result = Integer.MAX_VALUE;
		for(int i=0;i<si.size();i++) {
			int sx = si.get(i)[0]; int sy = si.get(i)[1];
			for(int j=0;j<ei.size();j++) {
				int ex = ei.get(j)[0]; int ey = ei.get(j)[1];
				if(!(Math.abs(ex-sx)==0||Math.abs(ey-sy)==0)) continue;
				int dist = Math.abs(ex-sx) + Math.abs(ey-sy);
				result = Math.min(result, dist);
			}
		}
		pq.add(new Edge(xidx,yidx,result-1));
	}

	static void bfs(int sx, int sy) {
		List<int[]> temp = new ArrayList<>();
		Queue<int[]> q = new LinkedList<>();
		q.offer(new int[] {sx,sy});
		check[sx][sy] = true;
		temp.add(new int[] {sx,sy});
		while(!q.isEmpty()) {
			int[] now = q.poll();
			int x = now[0]; int y = now[1];
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx>=0&&nx<N&&ny>=0&&ny<M&&check[nx][ny]==false) {
					if(board[nx][ny]==1) {
						q.offer(new int[] {nx,ny});
						check[nx][ny] = true;
						temp.add(new int[] {nx,ny});
					}
				}
			}
		}
		island.add(temp);
	}
	
	static int Find(int x) {
		if(parent[x]==x) return x;
		else return parent[x] = Find(parent[x]);
	}
	
	static void Union(int x, int y) {
		x = Find(x);
		y = Find(y);
		if(x==y) return;
		parent[y] = x;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		for(int i=1;i<10;i++) {
			a[i] = new ArrayList<>();
			parent[i] = i;
		}
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		N=n;M=m;
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<m;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(board[i][j]==1&&check[i][j]==false) {
					bfs(i,j);
				}
			}
		}
		for(int i=0;i<island.size();i++) {
			for(int j=i+1;j<island.size();j++) {
				bfs2(island.get(i),island.get(j),i+1,j+1);
			}
		}
		int pq_size = pq.size();
		for(int i=0;i<pq_size;i++) {
			Edge e = pq.poll();
			if(e.cost<2) continue;
			int from = e.from;
			int to = e.to;
			if(Find(from)!=Find(to)) {
				island_check[from] = true;
				island_check[to] = true;
				answer += e.cost;
				Union(from,to);
			}
		}
		int cnt = 0;
		for(int i=0;i<10;i++) {
			if(island_check[i]==true) cnt+=1;
		}
		if(cnt!=island.size()) answer = -1; 
		System.out.println(sb.append(answer));
	}
}