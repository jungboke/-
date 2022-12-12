//import java.io.*;
//import java.util.*;
//
//public class Main {
//	
//	static int[] a = new int[101];
//	static boolean[] check = new boolean[101];
//	static int ans_cnt = -1;
//	static List<Integer> answer = new ArrayList<>(); 
//	
//	static void dfs(int start, int num, List<Integer> temp) {
//		if(num==start) {
//			for(int i=0;i<temp.size();i++) {
//				answer.add(temp.get(i));
//			}
//			return;
//		}
//		if(check[num]==false) {
//			temp.add(num);
//			check[num] = true;
//			dfs(start,a[num],temp);
//			check[num] = false;
//			temp.remove(temp.size()-1);
//		}
//	}
//	
//    public static void main(String[] args) throws IOException {
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        StringBuilder sb = new StringBuilder();
//        StringTokenizer st;
//
//        int n = Integer.parseInt(br.readLine());
//        for(int i=1;i<=n;i++) {
//        	int x = Integer.parseInt(br.readLine());
//        	a[i] = x;
//        }
//        List<Integer> temp = new ArrayList<>();
//        for(int i=1;i<=n;i++) {
//        	if(answer.contains(i)) continue;
//        	temp.add(i);
//        	check[i] = true;
//        	dfs(i,a[i],temp);
//        	check[i] = false;
//        	temp.remove(temp.size()-1);
//        }
//        sb.append(answer.size()+"\n");
//        Collections.sort(answer);
//        for(int i=0;i<answer.size();i++) sb.append(answer.get(i)+"\n");
//        System.out.println(sb);
//	} 
//}
import java.io.*;
import java.util.*;

public class Main {
	
	static int[] a = new int[101];
	static boolean[] check = new boolean[101];
	static int answer = 0;
	
	static boolean dfs(int now, int target, int cnt) {
		if(check[now]==true) {
			if(now==target) {
				answer+=cnt;
				return true;
			}
			else return false;
		}
		check[now] = true;
		if(dfs(a[now],target,cnt+1)) return true;
		check[now] = false;
		return false;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		for(int i=1;i<=n;i++) {
			int x = Integer.parseInt(br.readLine());
			a[i] = x;
		}
		for(int i=1;i<=n;i++) {
			if(check[i]==true) continue;
			dfs(i,i,0);
		}
		sb.append(answer+"\n");
		for(int i=1;i<=n;i++) {
			if(check[i]==true) sb.append(i+"\n");
		}
		System.out.println(sb);
	}
}
