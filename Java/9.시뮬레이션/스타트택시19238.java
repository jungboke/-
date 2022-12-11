import java.io.*;
import java.util.*;

public class Main {
	
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] board = new int[21][21];
	static int[][] dist = new int[21][21];
	// 배달한 고객을 재방문하지 않기 위한 check배열
	static boolean[][] check = new boolean[21][21];
	// [0] 시작x [1] 시작y [2] 도착x [3] 도착y
 	static List<int[]> cli = new ArrayList<>();
	static int N;
	// [0] 고객까지 가는 데 필요한 연료  [1] 고객에서 목적지까지 필요한 연료 [2] 도착위치x [3] 도착위치y
	// 손님한테 접근할 수 없을 시 x,y -1 -1 반환
	static int[] bfs(int px, int py) {
		int bef = 0;
		int after = 0;
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) dist[i][j] = -1;
		}
		Queue<int[]> q = new LinkedList<>();
		q.offer(new int[] {px,py});
		dist[px][py] = 0;
		while(!q.isEmpty()) {
			int[] now = q.poll();
			int x = now[0]; int y = now[1];
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx>=0&&nx<N&&ny>=0&&ny<N&&dist[nx][ny]==-1) {
					if(board[nx][ny]==0) {
						q.offer(new int[] {nx,ny});
						dist[nx][ny] = dist[x][y]+1;
					}
				}
			}
		}
		int mini = Integer.MAX_VALUE;
		int mx = -1; int my = -1;
		int mex = -1; int mey = -1;
		// 고객리스트 탐색하면서 최소 이동거리 계산, 모든 고객에 방문불가능시 -1 -1 반환
		for(int i=0;i<cli.size();i++) {
			int sx = cli.get(i)[0]; int sy = cli.get(i)[1];
			int ex = cli.get(i)[2]; int ey = cli.get(i)[3];
			if(dist[sx][sy]==-1) continue;
			if(check[sx][sy]==true) continue;
			if(mini>dist[sx][sy]) {
				mini = dist[sx][sy];
				mx = sx; my = sy;
				mex = ex; mey = ey;
			}
			if(mini==dist[sx][sy]&&mx>sx) {
				mini = dist[sx][sy];
				mx = sx; my = sy;
				mex = ex; mey = ey;
			}
			if(mini==dist[sx][sy]&&mx==sx&&my>sy) {
				mini = dist[sx][sy];
				mx = sx; my = sy;
				mex = ex; mey = ey;
			}
		}
		if(mx==-1&&my==-1) return new int[] {0,0,-1,-1};
		bef=mini;
		// 해당 고객에서 목적지까지 다시 최단거리 계산, 목적지 도달 불가시 -1 -1 반환
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) dist[i][j] = -1;
		}
		q.offer(new int[] {mx,my});
		dist[mx][my] = 0;
		while(!q.isEmpty()) {
			int[] now = q.poll();
			int x = now[0]; int y = now[1];
			for(int i=0;i<4;i++) {
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx>=0&&nx<N&&ny>=0&&ny<N&&dist[nx][ny]==-1) {
					if(board[nx][ny]==0) {
						q.offer(new int[] {nx,ny});
						dist[nx][ny] = dist[x][y]+1;
					}
				}
			}
		}
		if(dist[mex][mey]==-1) return new int[] {0,0,-1,-1};
		after=dist[mex][mey];
		check[mx][my] = true;
		return new int[] {bef,after,mex,mey};
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		N=n;
		int m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<n;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		st = new StringTokenizer(br.readLine());
		int sx = Integer.parseInt(st.nextToken())-1;
		int sy = Integer.parseInt(st.nextToken())-1;
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken())-1;
			int y = Integer.parseInt(st.nextToken())-1;
			int ex = Integer.parseInt(st.nextToken())-1;
			int ey = Integer.parseInt(st.nextToken())-1;
			cli.add(new int[] {x,y,ex,ey});
		}
		int answer = 0;
		// 태운 손님 카운트
		int cnt = 0;
		while(true) {
			int[] result = bfs(sx,sy);
			int sum = result[0]+result[1];
			if((result[2]==-1&&result[3]==-1)||k-sum<0) {
				answer = -1;
				break;
			}
			k-=sum;
			k+=result[1]*2;
			sx = result[2];
			sy = result[3];
			cnt+=1;
			if(cnt==cli.size()) break;
		}
		if(answer!=-1) answer = k;
		System.out.println(sb.append(answer));
	} 
}
