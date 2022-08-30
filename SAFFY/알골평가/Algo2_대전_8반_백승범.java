import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Algo2_대전_8반_백승범 {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		// 입력 String을 charArray로 받음. 인덱스로 쉽게 접근하기 위해
		char[] s = br.readLine().toCharArray();
		// String 제작을 위한 StringBuilder
		StringBuilder result = new StringBuilder();
		for(int i=0;i<s.length;i++) {
			// 만약 aeiou인데 뒤에 두칸이 있고, 첫칸이 p, 둘째칸이 자신과 같다면 두번 건너뜀.
			if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') {
				if(i+2<s.length&&s[i+1]=='p'&&s[i+2]==s[i]) {
					i+=2;
				}
			}
			// 올바른 char 뽑아내기
			result.append(s[i]);
		}
		System.out.println(result);
	}
}
