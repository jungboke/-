import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static List<Integer> nums = new ArrayList<>();
	static List<Character> ops = new ArrayList<>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		String str = br.readLine();
		StringBuilder num = new StringBuilder();
		for(int i=0;i<str.length();i++) {
			if(Character.isDigit(str.charAt(i))) {
				num.append(str.charAt(i));
			} else {
				nums.add(Integer.parseInt(num.toString()));
				num.setLength(0);
				ops.add(str.charAt(i));
			}
		}
		nums.add(Integer.parseInt(num.toString()));
		boolean flag = false;
		int answer = nums.get(0);
		int temp = 0;
		for(int i=0;i<ops.size();i++) {
			if(ops.get(i)=='-') {
				flag = true;
				if(flag==true) {
					answer -= temp;
					temp = nums.get(i+1);
				}
			}
			else if(ops.get(i)=='+') {
				if(flag==true) {
					temp += nums.get(i+1);
				} else answer += nums.get(i+1);
			}
		}
		answer -= temp;
		System.out.println(sb.append(answer));
	}
}
