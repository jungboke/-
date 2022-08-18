import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static PriorityQueue<Integer> pq = new PriorityQueue<>(new Comparator<Integer>() {
		public int compare(Integer x, Integer y) {
			if(Math.abs(x)==Math.abs(y)) {
				return Integer.compare(x, y);
			}
			return Integer.compare(Math.abs(x), Math.abs(y));
		}
	});

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		int n = Integer.parseInt(br.readLine());
		for(int i=0;i<n;i++) {
			int x = Integer.parseInt(br.readLine());
			if(x!=0) {
				pq.offer(x);
			} else {
				if(pq.isEmpty()) sb.append(0+"\n");
				else sb.append(pq.poll()+"\n");
			}
		}
		System.out.println(sb);
	}
}
