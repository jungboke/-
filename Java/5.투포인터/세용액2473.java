// import java.io.*;
// import java.util.*;

// public class Main {

// 	static List<Integer> a = new ArrayList<>();
// 	static int[] answer = new int[3];
// 	static long mini = Long.MAX_VALUE;

// 	public static void main(String[] args) throws NumberFormatException, IOException {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;

// 		int n = Integer.parseInt(br.readLine());
// 		st = new StringTokenizer(br.readLine());
// 		for(int i=0;i<n;i++) {
// 			int x = Integer.parseInt(st.nextToken());
// 			a.add(x);
// 		}
// 		Collections.sort(a);
// 		outer:for(int i=0;i<n-2;i++) {
// 			int start = i+1;
// 			int end = n-1;
// 			while(start<end) {
// 				long sum = (long)a.get(i)+a.get(start)+a.get(end);
// 				if(mini>(long)Math.abs(sum)) {
// 					mini = (long)Math.abs(sum);
// 					answer[0] = a.get(i); answer[1] = a.get(start); answer[2] = a.get(end);
// 				}
// 				if(sum<0) start+=1;
// 				else if(sum>0) end-=1;
// 				else break outer;
// 			}

// 		}
// 		sb.append(answer[0]+" "+answer[1]+" "+answer[2]);
// 		System.out.println(sb);
// 	}
// }
import java.util.*;
import java.io.*;

public class Main {
	
	static List<Integer> a = new ArrayList<>();
	static long mini = Long.MAX_VALUE;
	static int[] answer = new int[3];
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			int x = Integer.parseInt(st.nextToken());
			a.add(x);
		}
		Collections.sort(a);
		outer:for(int i=0;i<n-2;i++) {
			int start = i+1;
			int end = n-1;
			while(start<end) {
				long sum = (long)a.get(start) + a.get(end) + a.get(i);
				if(mini>(long)Math.abs(sum)) {
					mini = (long)Math.abs(sum);
					answer[0] = a.get(i); answer[1] = a.get(start); answer[2] = a.get(end);
				}
				if(sum<0) {
					start+=1;
				} else if(sum>0) {
					end-=1;
				} else {
					answer[0] = a.get(i); answer[1] = a.get(start); answer[2] = a.get(end);
					break outer;
				} 
			}
		}
		System.out.println(sb.append(answer[0]+" "+answer[1]+" "+answer[2]));
	}
}
