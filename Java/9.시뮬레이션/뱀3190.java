import java.io.*;
import java.util.*;

public class Main {
	
	static class Info {
		int x;
		int c;
		Info(int x, int c) {
			this.x = x;
			this.c = c;
		}
	}
	static int[] dx = {0,-1,0,1};
	static int[] dy = {-1,0,1,0};
	static int[][] board = new int[102][102];
//	static int[][] pdir = new int[102][102];
	static List<Integer>[][] pdir = new ArrayList[102][102];
	static boolean[][] check = new boolean[102][102];
	static List<Info> a = new ArrayList<>();
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        
        int n = Integer.parseInt(br.readLine());
        for(int i=0;i<n;i++) {
        	for(int j=0;j<n;j++) pdir[i][j] = new ArrayList<>();
        }
        int k = Integer.parseInt(br.readLine());
        for(int i=0;i<k;i++) {
        	st = new StringTokenizer(br.readLine());
        	int x = Integer.parseInt(st.nextToken())-1;
        	int y = Integer.parseInt(st.nextToken())-1;
        	board[x][y] = 1;
        }
        int l = Integer.parseInt(br.readLine());
        for(int i=0;i<l;i++) {
        	st = new StringTokenizer(br.readLine());
        	int x = Integer.parseInt(st.nextToken());
        	char y = st.nextToken().charAt(0);
        	a.add(new Info(x,y));
        }
        int t = 0;
        int dir = 2;
        int nx = 0; int ny = 0;
        int px = 0; int py = 0;
//        pdir[nx][ny] = dir;
        pdir[nx][ny].add(dir);
        check[nx][ny] = true;
        while(true) {
        	t+=1;
        	nx+=dx[dir];
        	ny+=dy[dir];
        	if(!(nx>=0&&nx<n&&ny>=0&&ny<n)) break;
        	if(check[nx][ny]==true) break;
//        	pdir[nx][ny] = dir;
        	pdir[nx][ny].add(dir);
        	if(board[nx][ny]==1) {
        		check[nx][ny] = true;
        		board[nx][ny] = 0;
        	} else {
        		check[nx][ny] = true;
        		check[px][py] = false;
        		int ppdir = pdir[px][py].get(0);
        		pdir[px][py].remove(0);
        		px+=dx[ppdir];
        		py+=dy[ppdir];
        	}
        	if(!a.isEmpty()&&t==a.get(0).x) {
        		if(a.get(0).c=='D') {
        			dir+=1;
        			if(dir==4) dir = 0;
//        			pdir[nx][ny] = dir;
        			pdir[nx][ny].remove(pdir[nx][ny].size()-1);
        			pdir[nx][ny].add(dir);
        		} else {
        			dir-=1;
        			if(dir==-1) dir = 3;
//        			pdir[nx][ny] = dir;
        			pdir[nx][ny].remove(pdir[nx][ny].size()-1);
        			pdir[nx][ny].add(dir);
        		}
        		a.remove(0);
        	}
        }
        System.out.println(sb.append(t));
	} 
}