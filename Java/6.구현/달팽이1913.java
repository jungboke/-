// import java.io.BufferedReader;
// import java.io.IOException;
// import java.io.InputStreamReader;
// import java.util.StringTokenizer;

// public class Main {

// 	public static int[][] a = new int[1000][1000];

// 	public static void main(String[] args) throws NumberFormatException, IOException {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;

// 		int n = Integer.parseInt(br.readLine());
// 		int m = Integer.parseInt(br.readLine());
// 		int x = n/2;
// 		int y=  n/2;
// 		int cnt = 1;
// 		int move_cnt = 2;
// 		a[x][y] = cnt++;
// 		while(!(x==0&&y==0)) {
// 			x-=1;
// 			y-=1;
// 			for(int i=0;i<move_cnt;i++) {
// 				y+=1;
// 				a[x][y] = cnt++;
// 			}
// 			for(int i=0;i<move_cnt;i++) {
// 				x+=1;
// 				a[x][y] = cnt++;
// 			}
// 			for(int i=0;i<move_cnt;i++) {
// 				y-=1;
// 				a[x][y] = cnt++;
// 			}
// 			for(int i=0;i<move_cnt;i++) {
// 				x-=1;
// 				a[x][y] = cnt++;
// 			}
// 			move_cnt+=2;
// 		}
// 		int ans_x = 0, ans_y = 0;
// 		for(int i=0;i<n;i++) {
// 			for(int j=0;j<n;j++) {
// 				if(a[i][j]==m) {
// 					ans_x = i+1;
// 					ans_y = j+1;
// 				}
// 				sb.append(a[i][j]).append(" ");
// 			}
// 			sb.append("\n");
// 		}
// 		sb.append(ans_x).append(" ").append(ans_y).append("\n");
// 		System.out.println(sb);
// 	}
// }
import java.io.*;
import java.util.*;

public class Main {

    static int[][] board = new int[1000][1000];
    static int key = 1;

    static void func(int sx, int sy, int cnt) {
        sx-=1;
        for(int i=0;i<=cnt;i++) {
            board[sx][sy++] = key++;
        }
        sy-=1;
        sx+=1;
        for(int i=0;i<=cnt;i++) {
            board[sx++][sy] = key++;
        }
        sx-=1;
        sy-=1;
        for(int i=0;i<=cnt;i++) {
            board[sx][sy--] = key++;
        }
        sy+=1;
        sx-=1;
        for(int i=0;i<=cnt;i++) {
            board[sx--][sy] = key++;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        int sx = n/2;
        int sy = n/2;
        int cnt = 1;

        board[sx][sy] = key++;
        while(!(sx==0&&sy==0)) {
            func(sx,sy,cnt);
            sx-=1;
            sy-=1;
            cnt+=2;
        }

        int ax = 0;
        int ay = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                sb.append(board[i][j]).append(" ");
                if(board[i][j]==m) {
                    ax = i+1;
                    ay = j+1;
                }
            }
            sb.append("\n");
        }
        sb.append(ax).append(" ").append(ay);
        System.out.println(sb.toString());
    }
}


