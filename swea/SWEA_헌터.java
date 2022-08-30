import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class SWEA_헌터 {

    static int[][] board = new int[11][11];
    static List<int[]> a = new ArrayList<>(); 
    static boolean[] check = new boolean[10];
    static int N;
    static int mini = Integer.MAX_VALUE;

    static boolean order_check(List<int[]> temp) {
        List<Integer> num = new ArrayList<>();
        for(int i=0;i<temp.size();i++) {
            int x = temp.get(i)[2];
            int nx = x;
            if(x<0) x = -x;
            if(num.contains(x)) {
            	if(nx>0) return false; 
            } else num.add(x);
        }
        return true;
    }

    static int cal(List<int[]> temp) {
        int result = 0;
        int nx = 0, ny = 0;
        for(int i=0;i<temp.size();i++) {
            int x = temp.get(i)[0]; int y = temp.get(i)[1];
            result += Math.abs(nx-x)+Math.abs(ny-y);
            nx = x; ny = y;
        }
        return result;
    }

    static void dfs(List<int[]> temp) {
        if(temp.size()==a.size()) {
            if(order_check(temp)) {
                mini = Math.min(mini, cal(temp));
            }
            return;
        }
        for(int i=0;i<a.size();i++) {
            if(check[i]==true) continue;
            check[i] = true;
            temp.add(a.get(i));
            dfs(temp);
            temp.remove(temp.size()-1);
            check[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("data/monster.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

		int t = Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
		    int n = Integer.parseInt(br.readLine());
		    N=n;
		    for(int i=0;i<n;i++) {
		        st = new StringTokenizer(br.readLine());
		        for(int j=0;j<n;j++) {
		            board[i][j] = Integer.parseInt(st.nextToken());
		            if(board[i][j]!=0) a.add(new int[] {i,j,board[i][j]});
		        }
		    }
		    List<int[]> temp = new ArrayList<>();
		    dfs(temp);
		    sb.append("#"+(ot-t)+" "+mini+"\n");
		    a.clear();
		    mini = Integer.MAX_VALUE;
		}
		System.out.println(sb);
	}
}