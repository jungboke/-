import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class SWEA_4013_특이한자석 {

    static int[][] board = new int[4][8];
	
    static void move(int x, int y) {
    	if(y==1) {
    		int temp = board[x][7];
        	for(int i=7;i>0;i--) {
        		board[x][i] = board[x][i-1];
        	}
        	board[x][0] = temp;
    	} else if(y==-1) {
    		int temp = board[x][0];
        	for(int i=0;i<7;i++) {
        		board[x][i] = board[x][i+1];
        	}
        	board[x][7] = temp;
    	}
    }
    
    static void cycle(int x, int y) {
    	int[] num = new int[4];
    	boolean flag = true;
    	num[x] = y;
    	if(x==0) {
    		if(board[0][2]!=board[1][6]&&flag==true) num[1] = (y=0-y);
    		else flag = false;
    		if(board[1][2]!=board[2][6]&&flag==true) num[2] = (y=0-y);
    		else flag = false;
    		if(board[2][2]!=board[3][6]&&flag==true) num[3] = (y=0-y);
    		else flag = false;
    	} else if(x==1) {
    		if(board[0][2]!=board[1][6]&&flag==true) num[0] = 0-y;
    		if(board[1][2]!=board[2][6]&&flag==true) num[2] = (y=0-y);
    		else flag = false;
    		if(board[2][2]!=board[3][6]&&flag==true) num[3] = (y=0-y);
    		else flag = false;
    	} else if(x==2) {
    		if(board[2][2]!=board[3][6]&&flag==true) num[3] = 0-y;
    		if(board[1][2]!=board[2][6]&&flag==true) num[1] = (y=0-y);
    		else flag = false;
    		if(board[0][2]!=board[1][6]&&flag==true) num[0] = (y=0-y);
    		else flag = false;
    	} else if(x==3) {
    		if(board[2][2]!=board[3][6]&&flag==true) num[2] = (y=0-y);
    		else flag = false;
    		if(board[1][2]!=board[2][6]&&flag==true) num[1] = (y=0-y);
    		else flag = false;
    		if(board[0][2]!=board[1][6]&&flag==true) num[0] = (y=0-y);
    		else flag = false;
    	}
    	for(int i=0;i<num.length;i++) {
    		move(i,num[i]);
    	}
    }
  
    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("data/4013.txt"));
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int t = Integer.parseInt(br.readLine());
        int ot = t;
        while(t-->0) {
        	int k = Integer.parseInt(br.readLine());
        	for(int i=0;i<4;i++) {
        		st = new StringTokenizer(br.readLine());
        		for(int j=0;j<8;j++) {
        			board[i][j] = Integer.parseInt(st.nextToken());
        		}
        	}
        	for(int i=0;i<k;i++) {
        		st = new StringTokenizer(br.readLine());
        		int x = Integer.parseInt(st.nextToken())-1;
        		int y = Integer.parseInt(st.nextToken());
        		cycle(x,y);
        	}
        	int answer = 0;
        	if(board[0][0]==1) answer += 1;
        	if(board[1][0]==1) answer += 2;
        	if(board[2][0]==1) answer += 4;
        	if(board[3][0]==1) answer += 8;
        	sb.append("#"+(ot-t)+" "+answer+"\n");
        }
        System.out.println(sb);
    }
}