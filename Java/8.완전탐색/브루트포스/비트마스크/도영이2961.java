//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.List;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	static List<int[]> a = new ArrayList<>();
//
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//
//		int n = Integer.parseInt(br.readLine());
//		for(int i=0;i<n;i++) {
//			st = new StringTokenizer(br.readLine());
//			int x = Integer.parseInt(st.nextToken());
//			int y = Integer.parseInt(st.nextToken());
//			a.add(new int[] {x,y});
//		}
//		int mini = Integer.MAX_VALUE;
//		for(int i=1;i<(1<<n);i++) {
//			int sumS = 1;
//			int sumC = 0;
//			for(int j=0;j<n;j++) {
//				if((i&(1<<j))!=0) {
//					sumS*=a.get(j)[0];
//					sumC+=a.get(j)[1];
//				}
//			}
//			mini = Math.min(mini, Math.abs(sumS-sumC));
//		}
//		System.out.println(sb.append(mini));
//	}
//}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
	
	static List<int[]> a = new ArrayList<>();
	static int mini = Integer.MAX_VALUE;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			a.add(new int[] {x,y});
		}
		for(int i=1;i<(1<<n);i++) {
			int mul = 1;
			int sum = 0;
			for(int j=0;j<n;j++) {
				if((i&(1<<j))!=0) {
					mul*=a.get(j)[0];
					sum+=a.get(j)[1];
				}
			}
			mini = Math.min(mini, Math.abs(mul-sum));
		}
		System.out.println(sb.append(mini));
	}
}