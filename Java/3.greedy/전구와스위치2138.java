//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Arrays;
//import java.util.Collections;
//import java.util.List;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	static int mini = Integer.MAX_VALUE;
//
//	static void click(char[] a, int x) {
//		if(x==0) {
//			a[x] = (char)('1'-a[x]+'0');
//			a[x+1] = (char)('1'-a[x+1]+'0');
//		} else if(x==a.length-1) {
//			a[x-1] = (char)('1'-a[x-1]+'0');
//			a[x] = (char)('1'-a[x]+'0');
//		} else {
//			a[x-1] = (char)('1'-a[x-1]+'0');
//			a[x] = (char)('1'-a[x]+'0');
//			a[x+1] = (char)('1'-a[x+1]+'0');
//		}
//	}
//
//	static int change(char[] a, char[] b) {
//		char[] temp = Arrays.copyOf(a, a.length);
//		int cnt = 0;
//		for(int i=0;i<temp.length-1;i++) {
//			if(temp[i]!=b[i]) {
//				click(temp,i+1);
//				cnt+=1;
//			}
//		}
//		if(Arrays.equals(temp, b)) return cnt;
//		else return -1;
//	}
//
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//
//		int n = Integer.parseInt(br.readLine());
//		char[] a = br.readLine().toCharArray();
//		char[] b = br.readLine().toCharArray();
//		int temp = change(a,b);
//		if(temp!=-1) mini = Math.min(mini, temp);
//		click(a,0);
//		temp = change(a,b)+1;
//		if(temp!=0) mini = Math.min(mini, temp);
//		if(mini==Integer.MAX_VALUE) System.out.println(sb.append(-1));
//		else System.out.println(sb.append(mini));
//	}
//}
import java.io.*;
import java.util.*;

public class Main {

	static int answer = -1;
	static int N;
	
	static void click(StringBuilder temp, int x) {
		if(x==0) {
			temp.setCharAt(x, (char)('0'+('1'-temp.charAt(x))));
			temp.setCharAt(x+1, (char)('0'+('1'-temp.charAt(x+1))));
		} else if(x==N-1) {			
			temp.setCharAt(x-1, (char)('0'+('1'-temp.charAt(x-1))));
			temp.setCharAt(x, (char)('0'+('1'-temp.charAt(x))));
		} else {
			temp.setCharAt(x-1, (char)('0'+('1'-temp.charAt(x-1))));
			temp.setCharAt(x, (char)('0'+('1'-temp.charAt(x))));
			temp.setCharAt(x+1, (char)('0'+('1'-temp.charAt(x+1))));
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		N=n;
		String a = br.readLine();
		String b = br.readLine();
		StringBuilder temp = new StringBuilder(a);
		int cnt = 1;
		click(temp,0);
		for(int i=0;i<n-1;i++) {
			if(temp.charAt(i)!=b.charAt(i)) {
				click(temp,i+1);
				cnt+=1;
			}
		}
		if(temp.charAt(n-1)==b.charAt(n-1)) answer = cnt;
		temp = new StringBuilder(a);
		cnt = 0;
		for(int i=0;i<n-1;i++) {
			if(temp.charAt(i)!=b.charAt(i)) {
				click(temp,i+1);
				cnt+=1;
			}
		}
		if(temp.charAt(n-1)==b.charAt(n-1)) answer = cnt;
		System.out.println(sb.append(answer));
	}
}
