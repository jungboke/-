//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Collections;
//import java.util.List;
//import java.util.Stack;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	static Stack<int[]> stk = new Stack<>();
//	static List<Integer> answer = new ArrayList<>();
//
//	public static void main(String[] args) throws NumberFormatException, IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//
//
//		int n = Integer.parseInt(br.readLine());
//		st = new StringTokenizer(br.readLine());
//		for(int i=0;i<n;i++) {
//			int x = Integer.parseInt(st.nextToken());
//			while(!stk.empty()&&stk.peek()[0]<x) stk.pop();
//			if(stk.empty()) answer.add(0);
//			else answer.add(stk.peek()[1]+1);
//			stk.add(new int[] {x,i});
//		}
//		for(int i=0;i<answer.size();i++) {
//			sb.append(answer.get(i)+" ");
//		}
//		System.out.println(sb);
//	}
//}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	
	static Stack<int[]> stk = new Stack<>();
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for(int i=1;i<=n;i++) {
			int x = Integer.parseInt(st.nextToken());
			while(!stk.isEmpty()&&stk.peek()[0]<x) stk.pop();
			if(stk.isEmpty()) sb.append(0+" ");
			else sb.append(stk.peek()[1]+" ");
			stk.push(new int[] {x,i});
		}
		System.out.println(sb);
	}
}