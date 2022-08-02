import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		List<Integer> a = new ArrayList<>();
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			int x = Integer.parseInt(st.nextToken());
			a.add(x);
		}
		int odd = 0;
		int start = 0;
		int end = 0;
		for(int i=0;i<n;i++) {
			if(a.get(i)%2==1&&odd+1>k) break;
			else {
				if(a.get(i)%2==1) odd+=1;
				end=i;
			}
		}
		int maxi = end-start+1-odd;
		while(start<=end&&end<n) {
			if(a.get(start++)%2==1) odd-=1;
			end++;
			while(start<=end&&end<n) {
				if(a.get(end)%2==1&&odd>=k) {
					end-=1;
					break;
				}
				if(a.get(end)%2==1) odd+=1;
				end+=1;
			}
			if(end==n) {
				maxi = Math.max(maxi, end-start-odd);
				break;
			}
			else maxi = Math.max(maxi, end-start+1-odd);
		}
		System.out.println(sb.append(maxi+"\n"));
	}
}
