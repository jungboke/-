import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		HashMap<String, Integer> map1 = new HashMap<String,Integer>();
		
		st = new StringTokenizer(br.readLine()," ");
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		for(int i=0;i<n;i++) {
			String x = br.readLine();
			map1.put(x, 1);
		}
		int answer = 0;
		for(int i=0;i<m;i++) {
			String x = br.readLine();
			if(map1.get(x)!=null) {
				answer+=1;
			}
		}
		System.out.println(sb.append(answer));
	}
}
