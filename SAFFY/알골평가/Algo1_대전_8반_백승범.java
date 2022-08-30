import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Algo1_대전_8반_백승범 {
	
	static List<Integer> a = new ArrayList<>();
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		// testcase의 인덱스를 뽑아내기 위한 ot
		int ot = t;
		while(t-->0) {
			st = new StringTokenizer(br.readLine());
			// n,m(x),k의 값을 입력받음.
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken())-1;
			int k = Integer.parseInt(st.nextToken());
			// n크기만큼 List에 0을 집어넣음.
			for(int i=0;i<n;i++) {
				a.add(0);
			}
			// m인덱스의 0을 1로 교체함.
			a.set(m, 1);
			for(int i=0;i<k;i++) {
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken())-1;
				int y = Integer.parseInt(st.nextToken())-1;
				// 입력된 두 인덱스간 스왑을 진행
				int temp = a.get(x);
				a.set(x, a.get(y));
				a.set(y, temp);
			}
			// 1이 있는 곳의 인덱스를 answer로 뽑아냄.
			int answer = 0;
			for(int i=0;i<a.size();i++) {
				if(a.get(i)==1) answer = i;
			}
			// 출력
			sb.append("#"+(ot-t)+" "+(answer+1)+"\n");
			// 다음case에서 List 사용을 위해 clear
			a.clear();
		}
		System.out.println(sb);
	}
}
