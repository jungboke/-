import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		Stack<Integer> stack = new Stack<Integer>();


		int n = Integer.parseInt(br.readLine());
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine()," ");
			String x = st.nextToken();
			if(x.equals("push")) {
				int y = Integer.parseInt(st.nextToken());
				stack.push(y);
			} else if(x.equals("pop")) {
				if(stack.empty()) sb.append(-1).append("\n");
				else {
					sb.append(stack.peek()).append("\n");
					stack.pop();
				}
			} else if(x.equals("size")) {
				sb.append(stack.size()).append("\n");
			} else if(x.equals("empty")) {
				if(stack.empty()) sb.append(1).append("\n");
				else sb.append(0).append("\n");
			} else if(x.equals("top")) {
				if(stack.empty()) sb.append(-1).append("\n");
				else sb.append(stack.peek()).append("\n");
			}
		}
		System.out.println(sb);
	}
}
