import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
	
	static List<Character> a = new ArrayList<>();
	
	static boolean order_check(List<Character> temp) {
		int mo = 0;
		int za = 0;
		for(int i=0;i<temp.size()-1;i++) {
			if(temp.get(i)>temp.get(i+1)) return false;
		}
		for(int i=0;i<temp.size();i++) {
			if(temp.get(i)=='a'||temp.get(i)=='e'||temp.get(i)=='i'||temp.get(i)=='o'||temp.get(i)=='u') {
				mo+=1;
			} else za+=1;
		}
		if(mo>=1&&za>=2) return true;
		else return false;
	}
	
	static void dfs(List<Character> temp, int n, int start) {
		if(temp.size()==n) {
			if(order_check(temp)) {
				for(int i=0;i<temp.size();i++) {
					System.out.print(temp.get(i));
				}
				System.out.println();
			}
			return;
		}
		for(int i=start;i<a.size();i++) {
			temp.add(a.get(i));
			dfs(temp,n,i+1);
			temp.remove(temp.size()-1);
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<m;i++) {
			char x = st.nextToken().charAt(0);
			a.add(x);
		}
		Collections.sort(a);
		List<Character> temp = new ArrayList<>();
		dfs(temp,n,0);
	}
}