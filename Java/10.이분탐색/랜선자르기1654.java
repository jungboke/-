// import java.io.*;
// import java.util.*;

// public class Main {

// 	static List<Long> a = new ArrayList<>();
// 	static long answer = -1;

//     public static void main(String[] args) throws IOException {
//         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//         StringBuilder sb = new StringBuilder();
//         StringTokenizer st;

//     	st = new StringTokenizer(br.readLine());
//     	int n = Integer.parseInt(st.nextToken());
//     	int m = Integer.parseInt(st.nextToken());
//     	for(int i=0;i<n;i++) {
//     		long x = Integer.parseInt(br.readLine());
//     		a.add(x);
//     	}
//     	long start = 1;
//     	long end = Collections.max(a);
//     	while(start<=end) {
//     		long mid = (start+end)/2;
//     		long cnt = 0;
//     		for(int i=0;i<a.size();i++) {
//     			cnt += a.get(i)/mid;
//     		}
//     		if(cnt>=m) {
//     			start = mid + 1;
//     			answer = Math.max(answer, mid);
//     		} else {
//     			end = mid - 1;
//     		}
//     	}
//     	System.out.println(sb.append(answer));
// 	}
// }
import java.io.*;
import java.util.*;

public class Main {
	
	static List<Long> ran = new ArrayList<>();
	static long answer = Integer.MIN_VALUE;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		for(int i=0;i<n;i++) {
			long x = Integer.parseInt(br.readLine());
			ran.add(x);
		}
		long start = 1;
		long end = Collections.max(ran);
		while(start<=end) {
			long mid = (start+end)/2;
			int cnt = 0;
			for(int i=0;i<ran.size();i++) {
				cnt += ran.get(i)/mid;
			}
			if(cnt>=k) {
				answer = Math.max(answer, mid);
				start = mid+1;
			} else {
				end = mid-1;
			}
		}
		System.out.println(sb.append(answer));
	}
}

