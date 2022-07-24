import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		Deque<Integer> q = new LinkedList<>();

		int n = Integer.parseInt(br.readLine());
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine()," ");
			String x = st.nextToken();
			if(x.equals("push")) {
				int y = Integer.parseInt(st.nextToken());
				q.offer(y);
			} else if(x.equals("pop")) {
				if(q.isEmpty()) sb.append(-1).append("\n");
				else {
					sb.append(q.peekFirst()).append("\n");
					q.pollFirst();
				}
			} else if(x.equals("size")) {
				sb.append(q.size()).append("\n");
			} else if(x.equals("empty")) {
				if(q.isEmpty()) sb.append(1).append("\n");
				else sb.append(0).append("\n");
			} else if(x.equals("front")) {
				if(q.isEmpty()) sb.append(-1).append("\n");
				else sb.append(q.peekFirst()).append("\n");
			} else if(x.equals("back")) {
				if(q.isEmpty()) sb.append(-1).append("\n");
				else sb.append(q.peekLast()).append("\n");
			}
		}
		System.out.println(sb);
	}
}
