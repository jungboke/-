//import java.io.BufferedReader;
//import java.io.FileInputStream;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Arrays;
//import java.util.LinkedList;
//import java.util.List;
//import java.util.Queue;
//import java.util.Stack;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	static class Node {
//		int to;
//		int cost;
//		Node(int to, int cost) {
//			this.to = to;
//			this.cost = cost;
//		}
//	}
//
//	static List<Node> a[] = new ArrayList[10001];
//	static boolean check[] = new boolean[10001];
//
//	static boolean bfs(int limit, int sx, int ex) {
//		Arrays.fill(check, false);
//		Queue<Integer> q = new LinkedList<>();
//		q.offer(sx);
//		check[sx] = true;
//		while(!q.isEmpty()) {
//			int x = q.poll();
//			for(Node k:a[x]) {
//				int y = k.to;
//				if(check[y]==false&&k.cost>=limit) {
//					q.offer(y);
//					check[y] = true;
//				}
//			}
//		}
//		if(check[ex]==true) return true;
//		else return false;
//	}
//
//	public static void main(String[] args) throws NumberFormatException, IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//
//		st = new StringTokenizer(br.readLine());
//		int n = Integer.parseInt(st.nextToken());
//		for(int i=1;i<=n;i++) a[i] = new ArrayList<>();
//		int m = Integer.parseInt(st.nextToken());
//		int maxi = -1;
//		for(int i=0;i<m;i++) {
//			st = new StringTokenizer(br.readLine());
//			int x = Integer.parseInt(st.nextToken());
//			int y = Integer.parseInt(st.nextToken());
//			int z = Integer.parseInt(st.nextToken());
//			a[x].add(new Node(y,z));
//			a[y].add(new Node(x,z));
//			maxi = Math.max(maxi, z);
//		}
//		st = new StringTokenizer(br.readLine());
//		int sx = Integer.parseInt(st.nextToken());
//		int ex = Integer.parseInt(st.nextToken());
//
//		int start = 0;
//		int end = maxi;
//		maxi = -1;
//		while(start<=end) {
//			int mid = (start+end)/2;
//			if(bfs(mid,sx,ex)) {
//				maxi = Math.max(maxi, mid);
//				start = mid+1;
//			} else {
//				end = mid-1;
//			}
//		}
//		System.out.println(sb.append(maxi));
//	}
//
//}
// import java.io.*;
// import java.util.*;

// public class Main {
	
// 	static class Edge {
// 		int to;
// 		int cost;
// 		Edge(int to, int cost) {
// 			this.to = to;
// 			this.cost = cost;
// 		}
// 	}
// 	static List<Edge>[] a = new ArrayList[10001];
// 	static boolean[] check = new boolean[10001];
// 	static int N;
	
// 	static boolean bfs(int target, int sx, int ex) {
// 		for(int i=1;i<=N;i++) check[i] = false;
// 		Queue<Integer> q = new LinkedList<>();
// 		q.offer(sx);
// 		check[sx] = true;
// 		while(!q.isEmpty()) {
// 			int x = q.poll();
// 			for(Edge e:a[x]) {
// 				int y = e.to;
// 				if(check[y]==false&&e.cost>=target) {
// 					q.offer(y);
// 					check[y] = true;
// 				}
// 			}
// 		}
// 		if(check[ex]==true) return true;
// 		else return false;
// 	}
	
// 	public static void main(String[] args) throws NumberFormatException, IOException {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;
		
// 		st = new StringTokenizer(br.readLine());
// 		int n = Integer.parseInt(st.nextToken());
// 		N=n;
// 		for(int i=1;i<=n;i++) a[i] = new ArrayList<>();
// 		int m = Integer.parseInt(st.nextToken());
// 		int maxi = -1;
// 		for(int i=0;i<m;i++) {
// 			st = new StringTokenizer(br.readLine());
// 			int x = Integer.parseInt(st.nextToken());
// 			int y = Integer.parseInt(st.nextToken());
// 			int z = Integer.parseInt(st.nextToken());
// 			a[x].add(new Edge(y,z));
// 			a[y].add(new Edge(x,z));
// 			maxi = Math.max(maxi, z);
// 		}
// 		st = new StringTokenizer(br.readLine());
// 		int sx = Integer.parseInt(st.nextToken());
// 		int ex = Integer.parseInt(st.nextToken());
		
// 		int start = 0;
// 		int end = maxi;
// 		int answer = -1;
// 		while(start<=end) {
// 			int mid = (start+end)/2;
// 			if(bfs(mid,sx,ex)) {
// 				start = mid+1;
// 				answer = Math.max(answer, mid);
// 			} else end = mid-1;
// 		}
// 		System.out.println(sb.append(answer));
// 	}
// }
import java.io.*;
import java.util.*;

public class Main {

    static class Edge {
        int to;
        int cost;
        Edge(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
    }

    static List<Edge>[] a = new ArrayList[10001];
    static boolean[] check = new boolean[10001];

    static int answer = 0;

//    static boolean func(int x, int start, int end, int n) {
//        if(start==end) {
//            for(int i=1;i<=n;i++) check[i] = false;
//            return true;
//        }
//        for(Edge e : a[start]) {
//            int to = e.to;
//            int cost = e.cost;
//            if(cost>=x&&check[to]==false) {
//                check[start] = true;
//                if(func(x,to,end,n)) return true;
//                check[start] = false;
//            }
//        }
//        return false;
//    }

    static boolean bfs(int x, int n, int sx, int ex) {
        for(int i=1;i<=n;i++) check[i] = false;
        Queue<Integer> q = new LinkedList<>();
        q.offer(sx);
        check[sx] = true;
        while(!q.isEmpty()) {
            int nx = q.poll();
            for(Edge e : a[nx]) {
                int y = e.to;
                int cost = e.cost;
                if(x<=cost&&check[y]==false) {
                    q.offer(y);
                    check[y] = true;
                }
            }
            if(check[ex]==true) return true;
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        // 모든 다리의 가용무게를 가준으로 이분탐색을 실시함.
        // mid 값으로 시작지점에서 끝지점까지 dfs를 적용하며 갈 수 있는지만 확인
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        for(int i=1;i<=n;i++) a[i] = new ArrayList<>();
        int m = Integer.parseInt(st.nextToken());
        int start = 1;
        int end = 0;
        for(int i=0;i<m;i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());
            a[x].add(new Edge(y,z));
            a[y].add(new Edge(x,z));
            end = Math.max(end, z);
        }
        st = new StringTokenizer(br.readLine());
        int s = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());

        while(start<=end) {
            int mid = (start+end)/2;
            if(bfs(mid,n,s,e)) {
                answer = Math.max(answer,mid);
                start = mid+1;
            } else {
                end = mid-1;
            }
        }

        System.out.println(sb.append(answer).toString());
    }
}


