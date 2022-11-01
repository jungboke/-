import java.io.*;
import java.util.*;

public class Main {
	
	static int[] board = {-1,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,0,
						   10,13,16,19,25,30,35,40,0,
						   20,22,24,25,30,35,40,0,
						   30,28,27,26,25,30,35,40,0};
	static List<Integer> a = new ArrayList<>();
	static int[] horse = new int[4];
	static boolean[] check = new boolean[50];
	static int answer = -1;
	
	static void check_control(boolean flag, int idx) {
		if(idx == 20 || idx == 29 || idx == 37 || idx == 46) {
	        check[20] = flag;
	        check[29] = flag;
	        check[37] = flag;
	        check[46] = flag;
	    } else if(idx == 26 || idx == 34 || idx == 43) {
	        check[26] = flag;
	        check[34] = flag;
	        check[43] = flag;
	    } else if(idx == 27 || idx == 35 || idx == 44) {
	        check[27] = flag;
	        check[35] = flag;
	        check[44] = flag;
	    }else if(idx == 28 || idx == 36 || idx == 45) {
	        check[28] = flag;
	        check[36] = flag;
	        check[45] = flag;
	    }else {
	        check[idx] = flag;
	    }
	}
	
	static int next(int now, int cnt) {
		int nextIdx = now+cnt;
		if(now < 21) {
	        if(nextIdx >= 21) nextIdx = 21;
	    } else if(now < 30) {
	        if(nextIdx >= 30) nextIdx = 30;
	    } else if(now < 38) {
	        if(nextIdx >= 38) nextIdx = 38;
	    } else if(now < 47) {
	        if(nextIdx >= 47) nextIdx = 47;
	    }
		if(nextIdx==5) return 22;
		else if(nextIdx==10) return 31;
		else if(nextIdx==15) return 39;
		return nextIdx;
	}
	
	static int cal(List<Integer> temp) {
		Arrays.fill(horse, 0);
		Arrays.fill(check, false);
		int sum = 0;
		for(int i=0;i<temp.size();i++) {
			int idx = temp.get(i);
			if(horse[idx]==21||horse[idx]==30||horse[idx]==38||horse[idx]==47) return -1;		
			int next = next(horse[idx],a.get(i));
			if(next==21||next==30||next==38||next==47) {
				check_control(false,horse[idx]);
				horse[idx] = next; 
				continue;
			}
			if(check[next]==true) return -1;
			else {
				check_control(false,horse[idx]);
				check_control(true,next);
			}
			horse[idx] = next;
			sum+=board[horse[idx]];
		}
		return sum;
	}
	
	static void dfs(List<Integer> temp) {
		if(temp.size()==10) {
			answer = Math.max(answer, cal(temp));
			return;
		}
		for(int i=0;i<4;i++) {
			temp.add(i);
			dfs(temp);
			temp.remove(temp.size()-1);
		}
	}
	
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        for(int i=0;i<10;i++) {
        	int x = Integer.parseInt(st.nextToken());
        	a.add(x);
        }
        List<Integer> temp = new ArrayList<>();
        dfs(temp);
        System.out.println(sb.append(answer));
	}
}