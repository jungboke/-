import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

		int n = Integer.parseInt(br.readLine());
		for(int i=0;i<n;i++) {
			int x = Integer.parseInt(br.readLine());
			if(x==0) {
				if(pq.isEmpty()) sb.append(0).append("\n");
				else sb.append(pq.poll()).append("\n");
			} else {
				pq.offer(x);
			}
		}
		System.out.println(sb);
	}
}
