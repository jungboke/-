//import java.io.BufferedReader;
//import java.io.FileInputStream;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Collections;
//import java.util.HashSet;
//import java.util.List;
//import java.util.StringTokenizer;
//
//public class SWEA_7465_창용마을 {
//
//	static int[] parent = new int[101];
//	static int[] rank = new int[101];
//	static HashSet<Integer> a = new HashSet<>();
//	
//	static int Find(int x) {
//		if(x==parent[x]) return x;
//		else return parent[x] = Find(parent[x]);
//	}
//	
//	static void Union(int x, int y) {
//		x = Find(x);
//		y = Find(y);
//		if(x==y) return;
//		if(rank[x]<rank[y]) {
//			int temp = x; x = y; y = temp;
//		}
//		parent[y] = x;
//		if(rank[x]==rank[y]) rank[x]+=1;
//	} 
//	
//	public static void main(String[] args) throws NumberFormatException, IOException {
//		System.setIn(new FileInputStream("data/7465.txt"));
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		int t = Integer.parseInt(br.readLine());
//		int ot = t;
//		while(t-->0) {
//			st = new StringTokenizer(br.readLine());
//			int n = Integer.parseInt(st.nextToken());
//			int m = Integer.parseInt(st.nextToken());
//			for(int i=1;i<=n;i++) {
//				parent[i] = i;
//				rank[i] = 0;
//			}
//			for(int i=0;i<m;i++) {
//				st = new StringTokenizer(br.readLine());
//				int x = Integer.parseInt(st.nextToken());
//				int y = Integer.parseInt(st.nextToken());
//				Union(x,y);
//			}
//			for(int i=1;i<=n;i++) {
//				a.add(Find(i));
//			}
//			sb.append("#"+(ot-t)+" "+a.size()+"\n");
//			a.clear();
//		}
//		System.out.println(sb);
//	}
//}
import java.io.*;
import java.util.*;

public class Solution {
	
	static int[] parent = new int[101];
	static HashSet<Integer> s = new HashSet<>();
	
	static int Find(int x) {
		if(x==parent[x]) return x;
		else return parent[x] = Find(parent[x]);
	}
	
	static void Union(int x, int y) {
		x = Find(x);
		y = Find(y);
		if(x==y) return;
		parent[y] = x;
	}
	
    public static void main(String[] args) throws IOException {
    	System.setIn(new FileInputStream("data/7465.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int t = Integer.parseInt(br.readLine());
        int ot = t;
        while(t-->0) {
        	st = new StringTokenizer(br.readLine());
        	int n = Integer.parseInt(st.nextToken());
        	for(int i=1;i<=n;i++) parent[i] = i;
        	int m = Integer.parseInt(st.nextToken());
        	for(int i=0;i<m;i++) {
        		st = new StringTokenizer(br.readLine());
        		int x = Integer.parseInt(st.nextToken());
        		int y = Integer.parseInt(st.nextToken());
        		Union(x,y);
        	}
        	for(int i=1;i<=n;i++) {
        		s.add(Find(i));
        	}
        	sb.append("#"+(ot-t)+" "+s.size()+"\n");
        	s.clear();
        }
        System.out.println(sb);
	}
}
