//package com.ssafy.ws;
//
//
//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.PriorityQueue;
//import java.util.StringTokenizer;
//import java.util.TreeMap;
//
//public class SWEA_1208_Flatten {
//	public static void main(String[] args) throws NumberFormatException, IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		int t = 10;
//		int ot = t;
//		while(t-->0) {
//			int n = Integer.parseInt(br.readLine());
//			TreeMap<Integer,Integer> map1 = new TreeMap<>();
//			st = new StringTokenizer(br.readLine());
//			for(int i=0;i<100;i++) {
//				int x = Integer.parseInt(st.nextToken());
//				map1.put(x,map1.getOrDefault(x, 0)+1);
//			}
//			while(n-->0) {
//				int start = map1.firstKey();
//				int end = map1.lastKey();
//				if(map1.put(start, map1.get(start)-1)==1) {
//					map1.remove(start);
//				}
//				if(map1.put(end, map1.get(end)-1)==1) {
//					map1.remove(end);
//				}
//				map1.put(start+1, map1.getOrDefault(start+1, 0)+1);
//				map1.put(end-1, map1.getOrDefault(end-1, 0)+1);
//			}
//			sb.append("#"+(ot-t)+" "+(map1.lastKey()-map1.firstKey())+"\n");
//		}
//		System.out.println(sb);
//	}
//}
import java.io.*;
import java.util.*;

public class Solution {

	static TreeMap<Integer,Integer> map1 = new TreeMap<>();
	
    public static void main(String[] args) throws IOException {
    	System.setIn(new FileInputStream("data/1208.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int t = 10;
		int ot = t;
		while(t-->0) {
			int k = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<100;i++) {
				int x = Integer.parseInt(st.nextToken());
				map1.put(x,map1.getOrDefault(x, 0)+1);
			}
			for(int i=0;i<k;i++) {
				int start = map1.firstKey();
				int end = map1.lastKey();
				if(map1.put(start, map1.get(start)-1)==1) {
					map1.remove(start);
				}
				if(map1.put(end, map1.get(end)-1)==1) {
					map1.remove(end);
				}
				map1.put(start+1, map1.getOrDefault(start+1,0)+1);
				map1.put(end-1,map1.getOrDefault(end-1, 0)+1);
			}
			int answer = map1.lastKey() - map1.firstKey();
			sb.append("#"+(ot-t)+" "+answer+"\n");
			map1.clear();
		}
		System.out.println(sb);
	}
}
