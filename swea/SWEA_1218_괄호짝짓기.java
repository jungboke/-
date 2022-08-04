import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class SWEA_1218_괄호짝짓기 {

	static Stack<Character> stk = new Stack<>();
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("data/1218.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = 10;
		int ot = t;
		while(t-->0) {
			int n = Integer.parseInt(br.readLine());
			char[] x = br.readLine().toCharArray();
			boolean flag = true;
			for(int i=0;i<n;i++) {
				if(stk.isEmpty()||x[i]=='('||x[i]=='['||x[i]=='{'||x[i]=='<') {
					stk.add(x[i]);
				} else {
					if(stk.peek()=='('&&x[i]==')') stk.pop();
					else if(stk.peek()=='['&&x[i]==']') stk.pop();
					else if(stk.peek()=='{'&&x[i]=='}') stk.pop();
					else if(stk.peek()=='<'&&x[i]=='>') stk.pop();
					else {
						flag = false;
						break;
					}
				}
				if(!stk.isEmpty()) {
					if(stk.peek()==')'||stk.peek()==']'||stk.peek()=='}'||stk.peek()=='>') {
						flag = false;
						break;
					}
				}
			}
			if(!stk.isEmpty()) flag = false;
			if(flag==true) sb.append("#"+(ot-t)+" "+1+"\n");
			else sb.append("#"+(ot-t)+" "+0+"\n");
			stk.clear();
		}
		System.out.println(sb);
	}
}

