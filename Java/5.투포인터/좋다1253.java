// import java.io.*;
// import java.util.*;

// public class Main {
	
// 	static List<Long> a = new ArrayList<>();
// 	static int answer = 0;
	
//     public static void main(String[] args) throws IOException {
//         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//         StringBuilder sb = new StringBuilder();
//         StringTokenizer st;

//         int n = Integer.parseInt(br.readLine());
//         st = new StringTokenizer(br.readLine());
//         for(int i=0;i<n;i++) {
//         	long x = Integer.parseInt(st.nextToken());
//         	a.add(x);
//         }
//         Collections.sort(a);
//         for(int i=0;i<n;i++) {
//         	long x = a.get(i);
//         	int start = 0;
//         	int end = n-1;
//         	while(start<end) {
//         		long sum = a.get(start)+a.get(end);
//         		if(sum<x) {
//         			start+=1;
//         		} else if(sum>x) {
//         			end-=1;
//         		} else {
//         			if(start==i) {
//         				start+=1;
//         				continue;
//         			} else if(end==i) {
//         				end-=1;
//         				continue;
//         			}
//         			answer+=1;
//         			break;
//         		}
//         	}
//         }
//         System.out.println(sb.append(answer));
// 	}
// }
import java.io.*;
import java.util.*;

public class Main {
	
	static List<Integer> a = new ArrayList<>();
	static int answer = 0;
	
	public static void main(String[] args) throws Exception {
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
		outer:for(int i=0;i<n;i++) {
			int x = a.get(i);
			int start = 0;
			int end = n-1;
			while(start<end) {
				if(a.get(start)+a.get(end)<x) {
					start+=1;
				} else if(a.get(start)+a.get(end)>x) {
					end-=1;
				} else if(a.get(start)+a.get(end)==x) {
					if(start==i) {
						start+=1;
						continue;
					} else if(end==i) {
						end-=1;
						continue;
					}
					answer+=1;
					continue outer;
				}
			}
		}
		System.out.println(sb.append(answer));
	}
}
