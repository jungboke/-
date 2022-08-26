import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static List<Integer> a = new ArrayList<>();
	static List<Integer> b = new ArrayList<>();
	static int[] position = new int[100001];
	
	static void dfs(int is, int ie, int ps, int pe) {
		if(is>ie) return;
		int target = b.get(pe);
		int idx = position[target];
		System.out.print(target+" ");
		dfs(is,idx-1,ps,ps+idx-is-1);
		dfs(idx+1,ie,ps+idx-is,pe-1);
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			int x = Integer.parseInt(st.nextToken());
			a.add(x);
			position[x] = i;
		}
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			int x = Integer.parseInt(st.nextToken());
			b.add(x);
		}
		dfs(0,n-1,0,n-1);
	} 
}
