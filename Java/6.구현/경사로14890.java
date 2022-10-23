import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class Main {
	
	static int[][] board = new int[101][101];
	static int answer = 0;
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

    	st = new StringTokenizer(br.readLine());
    	int n = Integer.parseInt(st.nextToken());
    	int m = Integer.parseInt(st.nextToken());
    	for(int i=0;i<n;i++) {
    		st = new StringTokenizer(br.readLine());
    		for(int j=0;j<n;j++) {
    			board[i][j] = Integer.parseInt(st.nextToken());
    		}
    	}
    	outer:for(int i=0;i<n;i++) {
    		List<int[]> temp = new ArrayList<>();
    		int cnt = 1;
    		for(int j=1;j<n;j++) {
    			if(board[i][j]!=board[i][j-1]) {
    				temp.add(new int[] {board[i][j-1],cnt});
    				cnt = 1;
    			} else cnt+=1;
    		}
    		temp.add(new int[] {board[i][n-1],cnt});
    		int[] check = new int[temp.size()];
    		if(temp.size()==1) answer+=1;
    		else {
    			for(int j=1;j<temp.size();j++) {
    				int[] prev = temp.get(j-1); int[] now = temp.get(j);
    				if(Math.abs(prev[0]-now[0])>1) continue outer;
    				if(prev[0]>now[0]) {
    					if(check[j]+m>now[1]||now[1]<m) continue outer;
    					else check[j] += m;
    				} else if(prev[0]<now[0]) {
    					if(check[j-1]+m>prev[1]||prev[1]<m) continue outer;
    					else check[j-1] += m;
    				}
    			}
    			answer+=1;
    		}
    	}
    	outer:for(int j=0;j<n;j++) {
    		List<int[]> temp = new ArrayList<>();
    		int cnt = 1;
    		for(int i=1;i<n;i++) {
    			if(board[i][j]!=board[i-1][j]) {
    				temp.add(new int[] {board[i-1][j],cnt});
    				cnt = 1;
    			} else cnt+=1;
    		}
    		temp.add(new int[] {board[n-1][j],cnt});
    		int[] check = new int[temp.size()];
    		if(temp.size()==1) answer+=1;
    		else {
    			for(int i=1;i<temp.size();i++) {
    				int[] prev = temp.get(i-1); int[] now = temp.get(i);
    				if(Math.abs(prev[0]-now[0])>1) continue outer;
    				if(prev[0]>now[0]) {
    					if(check[i]+m>now[1]||now[1]<m) continue outer;
    					else check[i] += m;
    				} else if(prev[0]<now[0]) {
    					if(check[i-1]+m>prev[1]||prev[1]<m) continue outer;
    					else check[i-1] += m;
    				}
    			}
    			answer+=1;
    		}
    	}
    	System.out.println(sb.append(answer));
	}
}