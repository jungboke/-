//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Collections;
//import java.util.List;
//import java.util.StringTokenizer;
//
//public class Main {
//	
//	static List<Integer> a = new ArrayList<>();
//	static List<Integer> b = new ArrayList<>();
//	static List<Integer> zero = new ArrayList<>();
//	
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		int n = Integer.parseInt(br.readLine());
//		for(int i=0;i<n;i++) {
//			int x = Integer.parseInt(br.readLine());
//			if(x<0) b.add(x);
//			else if(x>0) a.add(x);
//			else zero.add(x);
//		}
//		Collections.sort(a,Collections.reverseOrder());
//		Collections.sort(b);
//		int answer = 0;
//		int now = 0;
//		for(int i=0;i<a.size();i++) {
//			if(now==0) now+=a.get(i);
//			else {
//				if(now==1||a.get(i)==1) {
//					now+=a.get(i);
//				} else now*=a.get(i);
//				answer+=now;
//				now=0;
//			}
//		}
//		answer+=now;
//		now = 0;
//		for(int i=0;i<b.size();i++) {
//			if(now==0) now+=b.get(i);
//			else {
//				now*=b.get(i);
//				answer+=now;
//				now=0;
//			}
//		}
//		if(now!=0&&zero.size()>0) answer+=0;
//		else answer+=now;
//		System.out.println(sb.append(answer));
//	}
//}
import java.io.*;
import java.util.*;

public class Main {

	static List<Integer> a = new ArrayList<>();
	static List<Integer> minus = new ArrayList<>();
	static int zero = 0;
  	static int answer = 0;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		for(int i=0;i<n;i++) {
			int x = Integer.parseInt(br.readLine());
			if(x==0) zero+=1;
			else if(x<0) minus.add(x);
			else if(x==1) answer+=1;
			else a.add(x);
		}
		Collections.sort(a,Collections.reverseOrder());
		Collections.sort(minus);
		for(int i=0;i<minus.size();i+=2) {
			if(i+1<minus.size()) {
				answer+=minus.get(i)*minus.get(i+1);				
			} else {
				if(zero==0) answer+=minus.get(i);
			}
		}
		for(int i=0;i<a.size();i+=2) {
			if(i+1<a.size()) {
				answer += a.get(i)*a.get(i+1);
			} else answer += a.get(i);
		}
		System.out.println(sb.append(answer));
	}
}