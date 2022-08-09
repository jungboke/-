// import java.io.BufferedReader;
// import java.io.FileInputStream;
// import java.io.IOException;
// import java.io.InputStreamReader;
// import java.util.ArrayList;
// import java.util.Arrays;
// import java.util.List;
// import java.util.StringTokenizer;

// public class SWEA_6808_규영이와 {
	
// 	static List<Integer> a = new ArrayList<>();
// 	static List<Integer> b = new ArrayList<>();
// 	static boolean[] check = new boolean[9];
// 	static int win = 0;
// 	static int lose = 0;
	
// 	static void comp(List<Integer> temp) {
// 		int a_score = 0;
// 		int b_score = 0;
// 		for(int i=0;i<a.size();i++) {
// 			if(a.get(i)>temp.get(i)) a_score+=a.get(i)+temp.get(i);
// 			else b_score+=a.get(i)+temp.get(i);
// 		}
// 		if(a_score>b_score) win+=1;
// 		else if(a_score<b_score) lose+=1;
// 	}
	
// 	static void dfs(List<Integer> temp) {
// 		if(temp.size()==9) {
// 			comp(temp);
// 			return;
// 		}
// 		for(int i=0;i<b.size();i++) {
// 			if(check[i]==true) continue;
// 			check[i] = true;
// 			temp.add(b.get(i));
// 			dfs(temp);
// 			temp.remove(temp.size()-1);
// 			check[i] = false;
// 		}
// 	}
	
// 	public static void main(String[] args) throws NumberFormatException, IOException {
// 		System.setIn(new FileInputStream("data/6808.txt"));
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;
		
// 		int t = Integer.parseInt(br.readLine());
// 		int ot = t;
// 		while(t-->0) {
// 			st = new StringTokenizer(br.readLine());
// 			for(int i=0;i<9;i++) {
// 				a.add(Integer.parseInt(st.nextToken()));
// 			}
// 			for(int i=1;i<=18;i++) {
// 				if(!(a.contains(i))) {
// 					b.add(i);
// 				}
// 			}
// 			List<Integer> temp = new ArrayList<>();
// 			dfs(temp);
// 			sb.append("#"+(ot-t)+" "+win+" "+lose+"\n");
// 			a.clear();
// 			b.clear();
// 			Arrays.fill(check, false);
// 			win = 0;
// 			lose = 0;
// 		}
// 		System.out.println(sb);
// 	}
// }
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Solution {
	
	static int[] a = new int[9];
	static int[] b = new int[9];
	static boolean[] check = new boolean[9];
	static boolean[] card = new boolean[19];
	static int win = 0;
	static int lose = 0;
	
	static void comp(List<Integer> temp) {
		int a_score = 0;
		int b_score = 0;
		for(int i=0;i<a.length;i++) {
			if(a[i]>temp.get(i)) a_score+=a[i]+temp.get(i);
			else b_score+=a[i]+temp.get(i);
		}
		if(a_score>b_score) win+=1;
		else if(a_score<b_score) lose+=1;
	}
	
	static void dfs(List<Integer> temp) {
		if(temp.size()==9) {
			comp(temp);
			return;
		}
		for(int i=0;i<b.length;i++) {
			if(check[i]==true) continue;
			check[i] = true;
			temp.add(b[i]);
			dfs(temp);
			temp.remove(temp.size()-1);
			check[i] = false;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("data/6808.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<9;i++) {
				a[i] = Integer.parseInt(st.nextToken());
				card[a[i]] = true;
			}
			int idx = 0;
			for(int i=1;i<=18;i++) {
				if(card[i]==false) {
					b[idx++] = i;
				}
			}
			List<Integer> temp = new ArrayList<>();
			dfs(temp);
			sb.append("#"+(ot-t)+" "+win+" "+lose+"\n");
			Arrays.fill(card, false);
			win = 0;
			lose = 0;
		}
		System.out.println(sb);
	}
}