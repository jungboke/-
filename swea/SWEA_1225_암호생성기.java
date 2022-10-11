//import java.io.BufferedReader;
//import java.io.FileInputStream;
//import java.io.FileNotFoundException;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.LinkedList;
//import java.util.List;
//import java.util.Queue;
//import java.util.StringTokenizer;
//
//public class SWEA_1225_암호생성기 {
//	
//	static Queue<Integer> q = new LinkedList<>();
//	
//	public static void main(String[] args) throws IOException {
//		System.setIn(new FileInputStream("data/1225.txt"));
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		int t = 10;
//		int ot = t;
//		while(t-->0) {
//			br.readLine();
//			st = new StringTokenizer(br.readLine());
//			for(int i=0;i<8;i++) {
//				q.offer(Integer.parseInt(st.nextToken()));
//			}
//			int cnt = 1;
//			while(true) {
//				int x = q.poll();
//				if(x-cnt<=0) {
//					q.offer(0);
//					break;
//				} else q.offer(x-cnt);
//				if(cnt==5) cnt = 0;
//				cnt+=1;
//			}
//			sb.append("#"+(ot-t)+" ");
//			for(int k:q) {
//				sb.append(k+" ");
//			}
//			sb.append("\n");
//			q.clear();
//		}
//		System.out.println(sb);
//	}
//}
import java.io.*;
import java.util.*;

public class Solution {

	static Queue<Integer> q = new LinkedList<>();
	
    public static void main(String[] args) throws IOException {
    	System.setIn(new FileInputStream("data/1225.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int t = 10;
        int ot = t;
        while(t-->0) {
        	int n = Integer.parseInt(br.readLine());
        	st = new StringTokenizer(br.readLine());
        	for(int i=0;i<8;i++) {
        		int x = Integer.parseInt(st.nextToken());
        		q.offer(x);
        	}
        	outer:while(true) {
        		for(int i=1;i<=5;i++) {
        			int x = q.poll();
        			if(x-i<=0) {
        				q.offer(0);
        				break outer;
        			}
        			q.offer(x-i);
        		}
        	}
        	StringBuilder answer = new StringBuilder();
        	for(int k:q) {
        		answer.append(k+" ");
        	}
        	sb.append("#"+(ot-t)+" "+answer.toString()+"\n");
        	q.clear();
        }
        System.out.println(sb);
	}
}
