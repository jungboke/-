//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.List;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	public static void main(String[] args) throws Exception, IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//
//		st = new StringTokenizer(br.readLine());
//		int n = Integer.parseInt(st.nextToken());
//		int k = Integer.parseInt(st.nextToken());
//		List<Integer> a = new ArrayList<>();
//		st = new StringTokenizer(br.readLine());
//		for(int i=0;i<n;i++) {
//			int x = Integer.parseInt(st.nextToken());
//			a.add(x);
//		}
//		int odd = 0;
//		int start = 0;
//		int end = 0;
//		for(int i=0;i<n;i++) {
//			if(a.get(i)%2==1&&odd+1>k) break;
//			else {
//				if(a.get(i)%2==1) odd+=1;
//				end=i;
//			}
//		}
//		int maxi = end-start+1-odd;
//		while(start<=end&&end<n) {
//			if(a.get(start++)%2==1) odd-=1;
//			end++;
//			while(start<=end&&end<n) {
//				if(a.get(end)%2==1&&odd>=k) {
//					end-=1;
//					break;
//				}
//				if(a.get(end)%2==1) odd+=1;
//				end+=1;
//			}
//			if(end==n) {
//				maxi = Math.max(maxi, end-start-odd);
//				break;
//			}
//			else maxi = Math.max(maxi, end-start+1-odd);
//		}
//		System.out.println(sb.append(maxi+"\n"));
//	}
//}
import java.io.*;
import java.util.*;

public class Main {
	
	static List<Integer> a = new ArrayList<>();
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			int x = Integer.parseInt(st.nextToken());
			a.add(x);
		}
		int start = 0;
		int end = 0;
		int odd_cnt = 0;
		for(int i=0;i<n;i++) {
			int x = a.get(i);
			if(x%2==1&&odd_cnt==k) break;
			if(x%2==1) odd_cnt+=1;
			end = i;
		}
		int maxi = end-start+1-odd_cnt;
		while(start<=end&&end<n) {
			if(a.get(start++)%2==1) odd_cnt-=1;
			end++;
			while(end<n) {
				if(a.get(end)%2==1&&odd_cnt==k) {
					end-=1;
					break;
				} else {
					if(a.get(end)%2==1) odd_cnt+=1;
					maxi = Math.max(maxi, end-start+1-odd_cnt);
					end+=1;
				}
			}
		}
		System.out.println(sb.append(maxi));
	}
}
