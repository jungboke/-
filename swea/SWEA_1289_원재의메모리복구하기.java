//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.StringTokenizer;
//
//public class Solution {
//	public static void main(String[] args) throws NumberFormatException, IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		int t = Integer.parseInt(br.readLine());
//		int ot = t;
//		while(t-->0) {
//			String x = br.readLine();
//			int answer = move(x);
//			sb.append("#"+(ot-t)+" "+answer+"\n");
//		}
//		System.out.println(sb);
//	}
//	static int move(String x) {
//		StringBuilder sb = new StringBuilder();
//		char[] ary_x = x.toCharArray();
//		sb.append(ary_x[0]);
//		for(int i=1;i<ary_x.length;i++) {
//			if(ary_x[i-1]!=ary_x[i]) sb.append(ary_x[1]);
//		}
//		int result = sb.length();
//		if(ary_x[0]=='0') result-=1;
//		return result;
//	}
//}
import java.io.*;
import java.util.*;

public class Solution {
	
	
    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("data/1289.txt"));
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int t = Integer.parseInt(br.readLine());
        int ot = t;
        while(t-->0) {
        	char[] a = br.readLine().toCharArray();
        	int answer = 0;
        	for(int i=1;i<a.length;i++) {
        		if(a[i]!=a[i-1]) answer+=1;
        	}
        	if(a[0]=='1') answer+=1;
        	sb.append("#"+(ot-t)+" "+answer+"\n");
        }
        System.out.println(sb);
     }
}