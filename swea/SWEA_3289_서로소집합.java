import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.StringTokenizer;

public class SWEA_3289_서로소집합 {

	static int[] parent = new int[1000001];
	static int[] rank = new int[1000001];
	
	static int Find(int x) {
		if(x==parent[x]) return x;
		else return parent[x] = Find(parent[x]);
	}
	
	static void Union(int x, int y) {
		x = Find(x);
		y = Find(y);
		if(x==y) return;
		if(rank[x]<rank[y]) {
			int temp = x; x = y; y = temp;
		}
		parent[y] = x;
		if(rank[x]==rank[y]) rank[x]+=1;
	} 
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			for(int i=1;i<=n;i++) {
				parent[i] = i;
				rank[i] = 0;
			}
			StringBuilder answer = new StringBuilder();
			for(int i=0;i<m;i++) {
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				int z = Integer.parseInt(st.nextToken());
				if(x==0) Union(y,z);
				else {
					if(Find(y)==Find(z)) answer.append(1);
					else answer.append(0);
				}
			}
			sb.append("#"+(ot-t)+" "+answer.toString()+"\n");
		}
		System.out.println(sb);
	}
}
