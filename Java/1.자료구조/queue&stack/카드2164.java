//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.LinkedList;
//import java.util.Queue;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	public static void main(String[] args) throws NumberFormatException, IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		Queue<Integer> q = new LinkedList<>();
//
//		int n = Integer.parseInt(br.readLine());
//		for(int i=1;i<=n;i++) {
//			q.offer(i);
//		}
//		while(q.size()!=1) {
//			q.poll();
//			q.offer(q.poll());
//		}
//		sb.append(q.peek()).append("\n");
//		System.out.println(sb);
//	}
//}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static Queue<Integer> q = new LinkedList<>();
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		for(int i=1;i<=n;i++) {
			q.offer(i);
		}
		while(q.size()!=1) {
			q.poll();
			int x = q.poll();
			q.offer(x);
		}
		System.out.println(sb.append(q.peek()+"\n"));
	}
}