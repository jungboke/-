//import java.io.BufferedReader;
//import java.io.FileInputStream;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Arrays;
//import java.util.Collections;
//import java.util.List;
//import java.util.PriorityQueue;
//import java.util.StringTokenizer;
//
//public class Solution {
//	
//	static int[][] board = new int[17][17];
//	
//	static boolean next_permutation(int[] arr) {
//		int N = arr.length;
//		int i = N-1;
//		while(i>0&&arr[i-1]>=arr[i]) --i;
//		
//		if(i==0) return false;
//		
//		int j = N-1;
//		while(arr[i-1]>=arr[j]) --j;
//		
//		int temp = arr[i-1];
//		arr[i-1] = arr[j];
//		arr[j] = temp;
//		
//		int k = N-1;
//		while(i<k) {
//			temp = arr[i];
//			arr[i] = arr[k];
//			arr[k] = temp;
//			++i; --k;
//		}
//		return true;
//	}
//	
//	static int cal(List<Integer> list1, List<Integer> list2) {
//		int cnt1 = 0;
//		int cnt2 = 0;
//		for(int i=0;i<list1.size();i++) {
//			for(int j=0;j<list1.size();j++) {
//				cnt1+=board[list1.get(i)][list1.get(j)];
//			}
//		}
//		for(int i=0;i<list2.size();i++) {
//			for(int j=0;j<list2.size();j++) {
//				cnt2+=board[list2.get(i)][list2.get(j)];
//			}
//		}
//		return Math.abs(cnt1-cnt2);
//	}
//	
//	public static void main(String[] args) throws NumberFormatException, IOException {
//		System.setIn(new FileInputStream("data/4012.txt"));
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		int t = Integer.parseInt(br.readLine());
//		int ot = t;
//		while(t-->0) {
//			int n = Integer.parseInt(br.readLine());
//			for(int i=0;i<n;i++) {
//				st = new StringTokenizer(br.readLine());
//				for(int j=0;j<n;j++) {
//					board[i][j] = Integer.parseInt(st.nextToken());
//				}
//			}
//			int[] perm = new int[n];
//			int idx = 0;
//			for(int i=0;i<n/2;i++) perm[idx++] = 0;
//			for(int i=0;i<n/2;i++) perm[idx++] = 1;
//			Arrays.sort(perm);
//			int mini = Integer.MAX_VALUE;
//			do {
//				List<Integer> list1 = new ArrayList<>();
//				List<Integer> list2 = new ArrayList<>();
//				for(int i=0;i<perm.length;i++) {
//					if(perm[i]==0) list1.add(i);
//					else list2.add(i);
//				}
//				mini = Math.min(mini, cal(list1,list2));
//			} while(next_permutation(perm));
//			sb.append("#"+(ot-t)+" "+mini+"\n");
//		}
//		System.out.println(sb);
//	}
//}
import java.io.*;
import java.util.*;

public class Solution {
	
	static int[][] board = new int[17][17];
	static int answer = Integer.MAX_VALUE;
	static int N;
	
	static int cal(List<Integer> temp) {
		int result = 0;
		for(int i=0;i<temp.size();i++) {
			for(int j=0;j<temp.size();j++) {
				if(i==j) continue;
				result += board[temp.get(i)][temp.get(j)];
			}
		}
		return result;
	}
	
	static void dfs(List<Integer> temp, int start) {
		if(temp.size()==N/2) {
			List<Integer> b = new ArrayList<>();
			for(int i=0;i<N;i++) {
				if(!temp.contains(i)) b.add(i);
			}
			int asum = cal(temp);
			int bsum = cal(b);
			answer = Math.min(answer, Math.abs(asum-bsum));
			return;
		}
		for(int i=start;i<N;i++) {
			temp.add(i);
			dfs(temp,i+1);
			temp.remove(temp.size()-1);
		}
	}
	
    public static void main(String[] args) throws IOException {
    	System.setIn(new FileInputStream("data/4012.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int t = Integer.parseInt(br.readLine());
        int ot = t;
        while(t-->0) {
        	int n = Integer.parseInt(br.readLine());
        	N=n;
        	for(int i=0;i<n;i++) {
        		st = new StringTokenizer(br.readLine());
        		for(int j=0;j<n;j++) {
        			board[i][j] = Integer.parseInt(st.nextToken());
        		}
        	}
        	List<Integer> temp = new ArrayList<>();
        	dfs(temp,0);
        	sb.append("#"+(ot-t)+" "+answer+"\n");
        	answer = Integer.MAX_VALUE;
        }
        System.out.println(sb);
	}
}
