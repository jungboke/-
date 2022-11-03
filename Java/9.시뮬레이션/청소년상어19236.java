import java.io.*;
import java.util.*;

public class Main {
	
	static int[] dx = {-1,-1,0,1,1,1,0,-1};
	static int[] dy = {0,-1,-1,-1,0,1,1,1};
	static int[][] board = new int[4][4];
	static int[][] dir = new int[4][4];
	// 물고기가 존재하는 칸
	static int answer = -1;
	
	static void block_swap(int[][] tmp_board, int[][] tmp_dir, int sx, int sy, int ex, int ey, int nd) {
		tmp_dir[sx][sy] = nd;
		int v = tmp_board[sx][sy];
		int d = tmp_dir[sx][sy];
		tmp_board[sx][sy] = tmp_board[ex][ey];
		tmp_dir[sx][sy] = tmp_dir[ex][ey];
		tmp_board[ex][ey] = v;
		tmp_dir[ex][ey] = d;
	}
	
	static void move(int[][] tmp_board, int[][] tmp_dir, int sx, int sy) {
		outer:for(int c=1;c<=16;c++) {
			for(int i=0;i<4;i++) {
				for(int j=0;j<4;j++) {
					if(tmp_board[i][j]!=c) continue;
					int d = tmp_dir[i][j];
					for(int k=0;k<8;k++) {
						int nx = i+dx[d]; int ny = j+dy[d];
						if(nx>=0&&nx<4&&ny>=0&&ny<4) {
							if(!(nx==sx&&ny==sy)) {
								block_swap(tmp_board, tmp_dir,i,j,nx,ny,d);
								continue outer;
							}
						}
						d = (d+1)%8;
					}
				}
			}
		}
	}
	
	static void dfs(int sum, int x, int y, int[][] tmp_board, int[][] tmp_dir) {
		int temp = tmp_board[x][y];
		sum+=tmp_board[x][y];
		tmp_board[x][y] = 0;
		int d = tmp_dir[x][y];
		boolean flag = false;
		int[][] tmp2_board = new int[4][4];
		int[][] tmp2_dir = new int[4][4];
		for(int i=0;i<4;i++) {
			for(int j=0;j<4;j++) {
				tmp2_board[i][j] = tmp_board[i][j];
				tmp2_dir[i][j] = tmp_dir[i][j];
			}
		}
		move(tmp2_board, tmp2_dir,x,y);
		
		int nx = x+dx[d]; int ny = y+dy[d];
		while(nx>=0&&nx<4&&ny>=0&&ny<4) {
			if(tmp2_board[nx][ny]==0) {
				nx+=dx[d]; ny+=dy[d];
				continue;
			}
			flag = true;
			dfs(sum,nx,ny,tmp2_board, tmp2_dir);
			nx+=dx[d]; ny+=dy[d];
		}
		if(flag==false) {
			answer = Math.max(answer, sum);
		}
		tmp_board[x][y] = temp;
	}
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        for(int i=0;i<4;i++) {
        	st = new StringTokenizer(br.readLine());
        	for(int j=0;j<4;j++) {
        		int x = Integer.parseInt(st.nextToken());
        		int y = Integer.parseInt(st.nextToken())-1;
        		board[i][j] = x;
        		dir[i][j] = y;
        	}
        }
        dfs(0,0,0,board,dir);
        System.out.println(sb.append(answer));
	}
}