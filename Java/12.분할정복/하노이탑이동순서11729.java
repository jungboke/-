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
	
	static List<int[]> a = new ArrayList<>();
	static int answer = 0;
	
	static void dfs(int n, int now, int next) {
		if(n==0) return;
		dfs(n-1,now,6-(now+next));
		a.add(new int[] {now,next});
		answer+=1;
		dfs(n-1,6-(now+next),next);
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
	
		int n = Integer.parseInt(br.readLine());
		dfs(n,1,3);
		sb.append(answer+"\n");
		for(int i=0;i<a.size();i++) {
			int now = a.get(i)[0]; int next = a.get(i)[1];
			sb.append(now+" "+next+"\n");
		}
		System.out.println(sb);
	} 
}
