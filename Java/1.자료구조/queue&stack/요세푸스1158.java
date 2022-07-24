import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		Queue<Integer> q = new LinkedList<>();

		st = new StringTokenizer(br.readLine()," ");
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		for(int i=1;i<=n;i++) {
			q.offer(i);
		}
		int cnt = 1;
		while(!q.isEmpty()) {
			if(cnt%m==0) {
				sb.append(q.poll()).append(", ");
			} else {
				q.offer(q.poll());
			}
			cnt+=1;
		}
		sb.setLength(sb.length()-2);
		System.out.println("<" + sb + ">");
	}
}
