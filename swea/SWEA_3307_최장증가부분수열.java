//import java.io.*;
//import java.util.*;
//
//public class Solution {
//
//	static int[] a = new int[1001];
//	static int[] d = new int[1001];
//	
//    public static void main(String[] args) throws IOException {
//    	System.setIn(new FileInputStream("data/3307.txt"));
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        StringBuilder sb = new StringBuilder();
//        StringTokenizer st;
//
//        int t = Integer.parseInt(br.readLine());
//        int ot = t;
//        while(t-->0) {
//        	int n = Integer.parseInt(br.readLine());
//        	st = new StringTokenizer(br.readLine());
//        	for(int i=1;i<=n;i++) {
//        		int x = Integer.parseInt(st.nextToken());
//        		a[i] = x;
//        		d[i] = 1;
//        	}
//        	for(int i=1;i<=n;i++) {
//        		for(int j=1;j<i;j++) {
//        			if(a[i]>=a[j]) {
//        				d[i] = Math.max(d[i], d[j]+1);
//        			}
//        		}
//        	}
//        	int answer = 0;
//        	for(int i=1;i<=n;i++) {
//        		answer = Math.max(answer, d[i]);
//        	}
//        	sb.append("#"+(ot-t)+" "+answer+"\n");
//        }
//        System.out.println(sb);
//	}
//}
import java.io.*;
import java.util.*;

public class Solution {
	
	static int[] a = new int[1001];
	static int[] d = new int[1001];
	
    public static void main(String[] args) throws IOException {
    	System.setIn(new FileInputStream("data/3307.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int t = Integer.parseInt(br.readLine());
        int ot = t;
        while(t-->0) {
        	int n = Integer.parseInt(br.readLine());
        	for(int i=1;i<=n;i++) d[i] = 1;
        	st = new StringTokenizer(br.readLine());
        	for(int i=1;i<=n;i++) {
        		int x = Integer.parseInt(st.nextToken());
        		a[i] = x;
        	}
        	for(int i=1;i<=n;i++) {
        		for(int j=1;j<i;j++) {
        			if(a[i]>=a[j]) {
        				d[i] = Math.max(d[i], d[j]+1);
        			}
        		}
        	}
        	int answer = -1;
        	for(int i=1;i<=n;i++) {
        		answer = Math.max(answer, d[i]);
        	}
        	sb.append("#"+(ot-t)+" "+answer+"\n");
        }
        System.out.println(sb);
	}
}