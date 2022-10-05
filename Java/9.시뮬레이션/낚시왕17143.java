import java.io.*;
import java.util.*;

public class Main {
	
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,1,-1};
	static List<int[]> shark = new ArrayList<>();
	static int N,M;
	static int answer = 0;
	
	
	static void catch_shark(int idx) {
		int sx = -1; int sy = idx;
		int mini = Integer.MAX_VALUE;
		int mx=-1,my=-1;
		for(int i=0;i<shark.size();i++) {
			int ex = shark.get(i)[0]; int ey = shark.get(i)[1];
			if(ey!=idx) continue;
			if(ex<mini) {
				mini = ex;
				mx=ex;my=ey;
			}
		}
		for(int i=0;i<shark.size();i++) {
			int x = shark.get(i)[0]; int y = shark.get(i)[1];
			if(x==mx&&y==my) {
				answer+=shark.get(i)[4];
				shark.remove(i);
				break;
			}
		}
	}
	
	static void move() {
		PriorityQueue<int[]>[][] temp = new PriorityQueue[N][M];
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) temp[i][j] = new PriorityQueue<>(new Comparator<int[]>() {
				public int compare(int[] o1, int[] o2) {
					return (o1[4]-o2[4])*-1;
				}
			});
		}
		for(int i=0;i<shark.size();i++) {
			int x = shark.get(i)[0]; int y = shark.get(i)[1];
			int s = shark.get(i)[2]; int d = shark.get(i)[3];
			int z = shark.get(i)[4];
			for(int j=0;j<s;j++) {
				x+=dx[d-1]; y+=dy[d-1];
				if(x==-1||x==N) {
					if(d==1) d=2;
					else if(d==2) d=1;
					x+=2*dx[d-1]; y+=2*dy[d-1];
				} else if(y==-1||y==M) {
					if(d==3) d=4;
					else if(d==4) d=3;
					x+=2*dx[d-1]; y+=2*dy[d-1];
				}
			}
			
			temp[x][y].add(new int[] {x,y,s,d,z});
		}
		shark.clear();
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(temp[i][j].isEmpty()) continue;
				shark.add(temp[i][j].peek());
			}
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		N=n;M=m;
		int k = Integer.parseInt(st.nextToken());
		for(int i=0;i<k;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken())-1;
			int y = Integer.parseInt(st.nextToken())-1;
			int s = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			int z = Integer.parseInt(st.nextToken());
			if(d<=2) s%=(n-1)*2;
			else s%=(m-1)*2;
			shark.add(new int[] {x,y,s,d,z});
		}
		int idx = 0;
		while(idx<m) {
			catch_shark(idx);
			move();
			idx+=1;
		}
		System.out.println(sb.append(answer));
	}
}