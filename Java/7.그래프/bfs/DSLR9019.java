import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static final int INF = 1000000000;
	static int[] dist = new int[10000];
	static int[] from = new int[10000];
	static char[] how = new char[10000];
	
	static void print(int m, int n, StringBuilder sb) {
		if(m==n) return;
		print(from[m],n,sb);
		sb.append(how[m]);
//		System.out.print(how[m]);
	}
	static int makeD(int x) {
		int temp = (x*2)%10000;
		return temp;
	}
	static int makeS(int x) {
		int temp = x-1;
		if(temp==-1) temp = 9999;
		return temp;
	}
	static int makeL(int x) {
		int temp = x/1000;
		x%=1000;
		temp = x*10 + temp;
		return temp;
	}
	static int makeR(int x) {
		int temp = x%10;
		x/=10;
		temp = temp*1000+x;
		return temp;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		while(t-->0) {
			Arrays.fill(dist, INF);
			Arrays.fill(from, 0);
			Arrays.fill(how, '0');
			Queue<Integer> q = new LinkedList<>();
			
			st = new StringTokenizer(br.readLine(), " ");
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			q.offer(n);
			dist[n] = 0;
			while(!q.isEmpty()) {
				int x = q.peek();
				q.poll();
				int temp = makeD(x);
				if(dist[temp]>dist[x]+1) {
					dist[temp] = dist[x]+1;
					from[temp] = x;
					how[temp] = 'D';
					q.offer(temp);
				}
				temp = makeS(x);
				if(dist[temp]>dist[x]+1) {
					dist[temp] = dist[x]+1;
					from[temp] = x;
					how[temp] = 'S';
					q.offer(temp);
				}
				temp = makeL(x);
				if(dist[temp]>dist[x]+1) {
					dist[temp] = dist[x]+1;
					from[temp] = x;
					how[temp] = 'L';
					q.offer(temp);
				}
				temp = makeR(x);
				if(dist[temp]>dist[x]+1) {
					dist[temp] = dist[x]+1;
					from[temp] = x;
					how[temp] = 'R';
					q.offer(temp);
				}
			}
			print(m,n,sb);
			sb.append("\n");
		}
		System.out.println(sb);
	}
}