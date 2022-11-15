import java.io.*;
import java.util.*;

public class Main {
	
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,-1,1};
	static int[][] board = new int[21][21];
	// 상어 방향 0 1 2 3
	static int[] dir = new int[402];
	// 1차원 상어번호 0 1 2 3
	// 2차원 상어방향  0 1 2 3 위 아래 왼 오
	// 3차원 1 2 3 4 위 아래 왼 오
	static int[][][] order = new int[402][5][5];
	// x좌표,y좌표,상어번호
	// 상어번호 1 2 3 4
	static List<int[]> shark = new ArrayList<>();
	// [0] 냄새카운트 [1] 상어번호
	static List<int[]>[][] smell = new ArrayList[21][21];
	static int N,M;
	static int MK;
	
	
	// no -> x,y,방향
	static void find(List<int[]> no, int num ,int ndir, List<int[]> temp) {
		outer:for(int i=0;i<4;i++) {
			int x = order[num-1][ndir][i]-1;
			for(int j=0;j<no.size();j++) {
				if(no.get(j)[2]==x) {
					int nx = no.get(j)[0]; int ny = no.get(j)[1];
					for(int k=0;k<shark.size();k++) {
						if(shark.get(k)[2]==num) {
							shark.set(k, new int[] {nx,ny,num});
							dir[num-1] = no.get(j)[2];
							temp.add(new int[] {nx,ny,MK,num});
//							smell[nx][ny].add(new int[] {MK+1,num});
							break outer;
						}
					}
				}
			}
		}
	}
	
	// 4방향 중에 비어있는 거, 본인 냄새 순으로 우선순위, 가능한 칸이 복수이상이면 상어의 번호, 방향에 따른 우선순위를 따름.
	static void move() {
		List<int[]> temp = new ArrayList<>();
		for(int i=0;i<shark.size();i++) {
			int x = shark.get(i)[0]; int y = shark.get(i)[1]; int num = shark.get(i)[2];
			int ndir = dir[num-1];
			List<int[]> no = new ArrayList<>();
			List<int[]> yes = new ArrayList<>();
			for(int j=0;j<4;j++) {
				int nx = x+dx[j];
				int ny = y+dy[j];
				if(!(nx>=0&&nx<N&&ny>=0&&ny<N)) continue;
				if(smell[nx][ny].isEmpty()) no.add(new int[] {nx,ny,j});
				else {
					for(int k=0;k<smell[nx][ny].size();k++) {
						if(smell[nx][ny].get(k)[1]==num) {
							yes.add(new int[] {nx,ny,j});
							break;
						}
					}
				}
			}
			if(!no.isEmpty()) find(no,num,ndir,temp);
			else find(yes,num,ndir,temp);
		}
		for(int j=0;j<temp.size();j++) {
			int nx = temp.get(j)[0]; int ny = temp.get(j)[1];
			int cnt = temp.get(j)[2]; int snum = temp.get(j)[3];
			smell[nx][ny].add(new int[] {cnt,snum});
		}
	}
 	
	static void smellDown() {
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				for(int k=0;k<smell[i][j].size();k++) {
					int cnt = smell[i][j].get(k)[0]; int num = smell[i][j].get(k)[1];
					if(cnt==0) {
						smell[i][j].remove(k);
						k-=1;
					}
					else smell[i][j].set(k, new int[] {cnt-1,num});
				}
			}
		}
	}
	
	static void away() {
		List<Integer>[][] temp = new ArrayList[N][N];
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) temp[i][j] = new ArrayList<>();
		}
		for(int i=0;i<shark.size();i++) {
			int x = shark.get(i)[0]; int y = shark.get(i)[1]; int num = shark.get(i)[2];
			temp[x][y].add(num);
			Collections.sort(temp[x][y]);
		}
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(temp[i][j].size()>1) {
					for(int k=1;k<temp[i][j].size();k++) {
						int x = temp[i][j].get(k);
						for(int c=0;c<shark.size();c++) {
							if(shark.get(c)[2]==x) {
								shark.remove(c);
								break;
							}
						}
					}
				}
			}
		}
	}
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        
        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        N=n;
        for(int i=0;i<n;i++) {
        	for(int j=0;j<n;j++) smell[i][j] = new ArrayList<>();
        }
        int m = Integer.parseInt(st.nextToken());
        M=m;
        int k = Integer.parseInt(st.nextToken());
        MK=k;
        for(int i=0;i<n;i++) {
        	st = new StringTokenizer(br.readLine());
        	for(int j=0;j<n;j++) {
        		board[i][j] = Integer.parseInt(st.nextToken());
        		if(board[i][j]!=0) {
        			shark.add(new int[] {i,j,board[i][j]});
        			smell[i][j].add(new int[] {k,board[i][j]});
        		}
        	}
        }
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<m;i++) {
        	dir[i] = Integer.parseInt(st.nextToken())-1;
        }
        for(int i=0;i<m;i++) {
        	for(int j=0;j<4;j++) {
        		st = new StringTokenizer(br.readLine());
        		for(int c=0;c<4;c++) {
        			order[i][j][c] = Integer.parseInt(st.nextToken());
        		}
        	}
        }
        int t = 0;
        while(true) {
        	if(shark.size()==1) break;
        	if(t>=1000) {
        		t = -1;
        		break;
        	}
        	smellDown();
        	move();
        	away();
        	t+=1;
        }
        System.out.println(sb.append(t));
	} 
}