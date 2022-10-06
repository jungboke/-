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
//	static List<Integer> nums = new ArrayList<>();
//	static List<Character> ops = new ArrayList<>();
//
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//
//		String str = br.readLine();
//		StringBuilder num = new StringBuilder();
//		for(int i=0;i<str.length();i++) {
//			if(Character.isDigit(str.charAt(i))) {
//				num.append(str.charAt(i));
//			} else {
//				nums.add(Integer.parseInt(num.toString()));
//				num.setLength(0);
//				ops.add(str.charAt(i));
//			}
//		}
//		nums.add(Integer.parseInt(num.toString()));
//		boolean flag = false;
//		int answer = nums.get(0);
//		int temp = 0;
//		for(int i=0;i<ops.size();i++) {
//			if(ops.get(i)=='-') {
//				flag = true;
//				if(flag==true) {
//					answer -= temp;
//					temp = nums.get(i+1);
//				}
//			}
//			else if(ops.get(i)=='+') {
//				if(flag==true) {
//					temp += nums.get(i+1);
//				} else answer += nums.get(i+1);
//			}
//		}
//		answer -= temp;
//		System.out.println(sb.append(answer));
//	}
//}
import java.io.*;
import java.util.*;

public class Main {

	static List<Integer> num = new ArrayList<>();
	static List<Character> op = new ArrayList<>();
	static int answer = 0;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		String a = br.readLine();
		StringBuilder temp = new StringBuilder();
		for(int i=0;i<a.length();i++) {
			if(Character.isDigit(a.charAt(i))) {
				temp.append(a.charAt(i));
			} else {
				op.add(a.charAt(i));
				num.add(Integer.parseInt(temp.toString()));
				temp.setLength(0);
			}
		}
		num.add(Integer.parseInt(temp.toString()));
		answer+=num.get(0);
		boolean flag = false;
		int sum = 0;
		for(int i=0;i<op.size();i++) {
			if(op.get(i)=='-') {
				flag = true;
				if(sum!=0) {
					answer-=sum;
				}
				sum = num.get(i+1);
			} else {
				if(flag==true) {
					sum+=num.get(i+1);
				} else answer+=num.get(i+1);
			}
		}
		answer-=sum;
		System.out.println(sb.append(answer));
	}
}
