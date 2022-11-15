import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class Main {
	
	static int[] dx = {0,0,-1,1};
	static int[] dy = {1,-1,0,0};
	static int[][] board = new int[13][13];
	static int[][] order = new int[13][13];
	static List<int[]> horse = new ArrayList<>();
	static int N,M;
	
	static void move(int idx) {
		int x = horse.get(idx)[0]; int y = horse.get(idx)[1]; int z = horse.get(idx)[2];
		int o = horse.get(idx)[3];
		List<Integer> group = new ArrayList<>();
		for(int i=0;i<M;i++) {
			if(horse.get(i)[0]==x&&horse.get(i)[1]==y&&horse.get(i)[3]>=o) group.add(i);
		}
		Collections.sort(group, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return horse.get(o1)[3]-horse.get(o2)[3];
			}
		});
		int nx = x+dx[z]; int ny = y+dy[z];
		if(!(nx>=0&&nx<N&&ny>=0&&ny<N)||board[nx][ny]==2) {
			nx = x-dx[z]; ny = y-dy[z];
			if(!(nx>=0&&nx<N&&ny>=0&&ny<N)||board[nx][ny]==2) {
				for(int i=0;i<group.size();i++) {
					int nz = horse.get(group.get(i))[2];
					int no = horse.get(group.get(i))[3];
					if(i==0) {
						if(nz%2==0) nz+=1;
						else nz-=1;
					}
					horse.set(group.get(i), new int[] {x,y,nz,no});
				}
			}
			else {
				if(board[nx][ny]==0) {
					for(int i=0;i<group.size();i++) {
						int nz = horse.get(group.get(i))[2];
						int no = order[nx][ny];
						if(i==0) {
							if(nz%2==0) nz+=1;
							else nz-=1;
						}
						horse.set(group.get(i), new int[] {nx,ny,nz,++no});
						order[nx][ny] = no;
					}
				} else if(board[nx][ny]==1) {
					for(int i=group.size()-1;i>=0;i--) {
						int nz = horse.get(group.get(i))[2];
						int no = order[nx][ny];
						if(i==0) {
							if(nz%2==0) nz+=1;
							else nz-=1;
						}
						horse.set(group.get(i), new int[] {nx,ny,nz,++no});
						order[nx][ny] = no;
					}
				}
			}
		} else if(board[nx][ny]==0) {
			for(int i=0;i<group.size();i++) {
				int nz = horse.get(group.get(i))[2];
				int no = order[nx][ny];
				horse.set(group.get(i), new int[] {nx,ny,nz,++no});
				order[nx][ny] = no;
			}
		} else if(board[nx][ny]==1) {
			for(int i=group.size()-1;i>=0;i--) {
				int nz = horse.get(group.get(i))[2];
				int no = order[nx][ny];
				horse.set(group.get(i), new int[] {nx,ny,nz,++no});
				order[nx][ny] = no;
			}
		}
	}
	
	static boolean check() {
		int[][] cnt = new int[N][N];
		for(int i=0;i<M;i++) {
			int x = horse.get(i)[0]; int y = horse.get(i)[1];
			cnt[x][y]+=1;
		}
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(cnt[i][j]>=4) return true;
			}
		}
		return false;
	}
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        N=n;M=m;
        for(int i=0;i<n;i++) {
        	st = new StringTokenizer(br.readLine());
        	for(int j=0;j<n;j++) {
        		board[i][j] = Integer.parseInt(st.nextToken());
        	}
        }
        for(int i=0;i<m;i++) {
        	st = new StringTokenizer(br.readLine());
        	int x = Integer.parseInt(st.nextToken())-1;
        	int y = Integer.parseInt(st.nextToken())-1;
        	int z = Integer.parseInt(st.nextToken())-1;
        	horse.add(new int[] {x,y,z,0});
        }
        int t = 1;
        while(true) {
        	for(int i=0;i<m;i++) {
        		move(i);
        		if(check()) break;
        	}
        	if(check()) break;
        	t+=1;
        	if(t>=1000) {
        		t = -1;
        		break;
        	}
        }
        System.out.println(sb.append(t));
	}
}