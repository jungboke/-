import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class SWEA_낚시터자리잡기 {

    static List<int[]> gate = new ArrayList<>();
	static boolean[] check = new boolean[61];
    static int mini = Integer.MAX_VALUE;
    static int N;
    
    static int cal1(List<int[]> temp) {
    	int[] a = new int[N];
    	for(int i=0;i<temp.size();i++) {
    		int now = temp.get(i)[0];
    		int cnt = temp.get(i)[1];
    		int dist = 0;
    		while(cnt>0) {
    			if(now-dist>=0&&a[now-dist]==0&&cnt>0) {
    				a[now-dist] = dist+1;
    				cnt-=1;
    			}
    			if(now+dist<N&&a[now+dist]==0&&cnt>0) {
    				a[now+dist] = dist+1;
    				cnt-=1;
    			}
    			dist+=1;
    		}
    	}
    	int result = 0;
    	for(int i=0;i<N;i++) result+=a[i];
    	return result;
    }
    
    static int cal2(List<int[]> temp) {
    	int[] a = new int[N];
    	for(int i=0;i<temp.size();i++) {
    		int now = temp.get(i)[0];
    		int cnt = temp.get(i)[1];
    		int dist = 0;
    		while(cnt>0) {
    			if(now+dist<N&&a[now+dist]==0&&cnt>0) {
    				a[now+dist] = dist+1;
    				cnt-=1;
    			}
    			if(now-dist>=0&&a[now-dist]==0&&cnt>0) {
    				a[now-dist] = dist+1;
    				cnt-=1;
    			}
    			dist+=1;
    		}
    	}
    	int result = 0;
    	for(int i=0;i<N;i++) result+=a[i];
    	return result;
    }
    
    static void dfs(List<int[]> temp) {
    	if(temp.size()==3) {
    		mini = Math.min(mini, cal1(temp));
    		mini = Math.min(mini, cal2(temp));
    		return;
    	}
    	for(int i=0;i<gate.size();i++) {
    		if(check[i]==true) continue;
    		check[i] = true;
    		temp.add(gate.get(i));
    		dfs(temp);
    		temp.remove(temp.size()-1);
    		check[i] = false;
    	}
    }
    
    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("data/fishing.txt"));
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int t = Integer.parseInt(br.readLine());
        int ot = t;
        while(t-->0) {
        	int n = Integer.parseInt(br.readLine());
        	N=n;
        	for(int i=0;i<3;i++) {
        		st = new StringTokenizer(br.readLine());
        		int x = Integer.parseInt(st.nextToken())-1;
        		int y = Integer.parseInt(st.nextToken());
        		gate.add(new int[] {x,y});
        	}
        	List<int[]> temp = new ArrayList<>();
        	dfs(temp);
        	sb.append("#"+(ot-t)+" "+mini+"\n");
        	gate.clear();
        	mini = Integer.MAX_VALUE;
        }
        System.out.println(sb);
    }
}