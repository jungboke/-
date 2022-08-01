import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {

	static List<int[]> a = new ArrayList<>();
	static TreeSet<String> s = new TreeSet<>();

	static void go(List<Integer> temp, String str) {
		if(temp.size()==a.size()) {
			char[] str_ary = str.toCharArray();
			for(int i=0;i<temp.size();i++) {
				if(temp.get(i)==1) continue;
				str_ary[a.get(i)[0]] = ' ';
				str_ary[a.get(i)[1]] = ' ';
			}
			StringBuilder sb = new StringBuilder();
			for(int i=0;i<str_ary.length;i++) {
				if(str_ary[i]!=' ') sb.append(str_ary[i]);
			}
			s.add(sb.toString());
			return;
		}
		temp.add(0);
		go(temp,str);
		temp.remove(temp.size()-1);
		temp.add(1);
		go(temp,str);
		temp.remove(temp.size()-1);
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		Stack<Integer> stk = new Stack<>();

		String x = br.readLine();
		for(int i=0;i<x.length();i++) {
			if(!(x.charAt(i)=='('||x.charAt(i)==')')) continue;
			if(stk.isEmpty()||x.charAt(i)=='(') stk.push(i);
			else {
				a.add(new int[] {stk.peek(),i});
				stk.pop();
			}
		}
		List<Integer> temp = new ArrayList<>();
		go(temp,x);
		s.remove(x);
		for(String k : s) {
			sb.append(k).append("\n");
		}
		System.out.println(sb);
	}
}
