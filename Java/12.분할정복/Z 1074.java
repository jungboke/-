//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.StringTokenizer;
//
//public class Main {
//	
//	static int R,C;
//	static int cnt = 0;
//	
//	static void dfs(int px, int py, int n) {
//		if(n==1) {
//			System.out.println(cnt);
//			System.exit(0);
//		}
//		if(R<px+n/2&&C<py+n/2) {
//			dfs(px,py,n/2);
//		} else if(R<px+n/2&&C<py+n/2+n/2) {
//			cnt+=(n*n)/4;
//			dfs(px,py+n/2,n/2);
//		} else if(R<px+n/2+n/2&&C<py+n/2) {
//			cnt+=(n*n)/4*2;
//			dfs(px+n/2,py,n/2);
//		} else {
//			cnt+=(n*n)/4*3;
//			dfs(px+n/2,py+n/2,n/2);
//		}
//	}
//	
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		st = new StringTokenizer(br.readLine());
//		int n = Integer.parseInt(st.nextToken());
//		int r = Integer.parseInt(st.nextToken());
//		int c = Integer.parseInt(st.nextToken());
//		R=r;C=c;
//		int rn = (int)Math.pow(2, n);
//		dfs(0,0,rn);
//	}
//}
// import java.io.*;
// import java.util.*;

// public class Main {
	
// 	static int R,C;
	
// 	static void dfs(int x, int y, int r, int cnt) {
// 		if(r==1) {
// 			System.out.println(cnt);
// 			System.exit(0);
// 		}
// 		if(R>=x&&R<x+r/2&&C>=y&&C<y+r/2) {
// 			dfs(x,y,r/2,cnt+r*r/4*0);
// 		} else if(R>=x&&R<x+r/2&&C>=y+r/2&&C<y+r) {
// 			dfs(x,y+r/2,r/2,cnt+r*r/4*1);
// 		} else if(R>=x+r/2&&R<x+r&&C>=y&&C<y+r/2) {
// 			dfs(x+r/2,y,r/2,cnt+r*r/4*2);
// 		} else if(R>=x+r/2&&R<x+r&&C>=y+r/2&&C<y+r) {
// 			dfs(x+r/2,y+r/2,r/2,cnt+r*r/4*3);
// 		}
// 	}
	
// 	public static void main(String[] args) throws NumberFormatException, IOException {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;
		
// 		st = new StringTokenizer(br.readLine());
// 		int n = Integer.parseInt(st.nextToken());
// 		int r = Integer.parseInt(st.nextToken());
// 		int c = Integer.parseInt(st.nextToken());
// 		R=r;C=c;
// 		dfs(0,0,(int)Math.pow(2, n),0);
// 	}
// }
import java.io.*;
import java.util.*;

public class Main {
	
	static int R,C;
	static int answer = -1;
	
	static boolean dfs(int n, int x, int y, int num) {
		if(x==R&&y==C) {
			answer = num;
			return true;
		}
		int l = (int)Math.pow(2,n-1);
		int temp = (int)Math.pow(l,2);
		if(R<x+l&&C<y+l) {
			if(dfs(n-1,x,y,num)) return true;
		} else if(R<x+l&&C>=y+l) {
			if(dfs(n-1,x,y+l,num+temp*1)) return true;
		} else if(R>=x+l&&C<y+l) {
			if(dfs(n-1,x+l,y,num+temp*2)) return true;
		} else if(R>=x+l&&C>=y+l) {
			if(dfs(n-1,x+l,y+l,num+temp*3)) return true;
		}
		return false;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		R=r;C=c;
		dfs(n,0,0,0);
		System.out.println(sb.append(answer));
	}
}
