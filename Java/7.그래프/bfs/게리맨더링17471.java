import java.io.*;
import java.util.*;

public class Main {
	
	
	static List<Integer> cost = new ArrayList<>();
	static List<Integer>[] a = new ArrayList[11];
	static boolean[] check = new boolean[11];
	static int mini = Integer.MAX_VALUE;
	static int N;

	static int bfs(List<Integer> temp) {
		int sum = 0;
		for(int i=0;i<temp.size();i++) {
			int x = temp.get(i);
			sum+=cost.get(x-1);
		}
		Queue<Integer> q = new LinkedList<>();
		q.offer(temp.get(0));
		check[temp.get(0)] = true;
		while(!q.isEmpty()) {
			int x = q.poll();
			for(int k:a[x]) {
				if(check[k]==false&&temp.contains(k)) {
					q.offer(k);
					check[k] = true;
				}
			}
		}
		for(int i=0;i<temp.size();i++) {
			if(check[temp.get(i)]==false) return -1;
		}
		return sum;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		N=n;
		for(int i=1;i<=n;i++) a[i] = new ArrayList<>();
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			int x = Integer.parseInt(st.nextToken());
			cost.add(x);
		}
		for(int i=1;i<=n;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			for(int j=0;j<x;j++) {
				int y = Integer.parseInt(st.nextToken());
				a[i].add(y);
			}
		}
		for(int i=1;i<(1<<n)-1;i++) {
			List<Integer> g1 = new ArrayList<>();
			List<Integer> g2 = new ArrayList<>();
			for(int j=0;j<n;j++) {
				if((i&(1<<j))==0) g1.add(j+1);
				else g2.add(j+1);
			}
			Arrays.fill(check, false);
			int g1_sum = bfs(g1);
			int g2_sum = bfs(g2);
			if(g1_sum==-1||g2_sum==-1) continue;
			else mini = Math.min(mini, Math.abs(g1_sum-g2_sum));
		}
		if(mini==Integer.MAX_VALUE) mini = -1;
		System.out.println(sb.append(mini));
	}
}