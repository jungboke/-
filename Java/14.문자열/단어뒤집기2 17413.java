//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Collections;
//import java.util.List;
//import java.util.Stack;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	public static void main(String[] args) throws NumberFormatException, IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		char[] x = br.readLine().toCharArray();
//		StringBuilder temp = new StringBuilder();
//		boolean flag = false;
//		for(int i=0;i<x.length;i++) {
//			if(x[i]==' '&&flag==false) {
//				sb.append(temp.reverse()+" ");
//				temp.setLength(0);
//			} else if(x[i]=='<') {
//				sb.append(temp.reverse());
//				flag = true;
//				temp.setLength(0);
//				temp.append(x[i]);
//			} else if(x[i]=='>') {
//				sb.append(temp+">");
//				flag = false;
//				temp.setLength(0);
//			} else temp.append(x[i]);
//		}
//		if(temp.length()!=0) sb.append(temp.reverse());
//		System.out.println(sb);
//	}
//}
import java.io.*;
import java.util.*;

public class Main {

	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		char[] x = br.readLine().toCharArray();
		String answer = "";
		boolean flag = false;
		StringBuilder temp = new StringBuilder();
		for(int i=0;i<x.length;i++) {
			if(x[i]=='<') {
				answer+=temp.reverse().toString();
				temp.setLength(0);
				temp.append(x[i]);
				flag = true;
			} else if(x[i]==' ') {
				if(flag==false) {
					answer+=temp.reverse().toString()+" ";
					temp.setLength(0);
				} else temp.append(x[i]);
			} else if(x[i]=='>') {
				temp.append(x[i]);
				answer+=temp.toString();
				temp.setLength(0);
				flag = false;
			} else {
				temp.append(x[i]);
			}
		}
		answer+=temp.reverse().toString();
		System.out.println(sb.append(answer));
	}
}