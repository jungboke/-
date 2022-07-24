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

		int n = Integer.parseInt(br.readLine());
		outer : for(int i=0;i<n;i++) {
			Stack<Character> stack = new Stack<Character>();
			String temp = br.readLine();
			for(int j=0;j<temp.length();j++) {
				if(stack.empty()||temp.charAt(j)=='(') {
					stack.push(temp.charAt(j));
				} else stack.pop();
				if(!stack.empty()&&stack.peek()==')') {
					sb.append("NO").append("\n");
					continue outer;
				}
			}
			if(!stack.empty()) {
				sb.append("NO").append("\n");
				continue outer;
			}
			sb.append("YES").append("\n");
		}
		System.out.println(sb);
	}
}
