//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.Arrays;
//import java.util.LinkedList;
//import java.util.List;
//import java.util.Queue;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	static List<int[]> home = new ArrayList<>();
//	static List<int[]> chicken = new ArrayList<>();
//	static int mini = Integer.MAX_VALUE;
//
//	static int cal(List<int[]> temp) {
//		int result = 0;
//		for(int i=0;i<home.size();i++) {
//			int sum = Integer.MAX_VALUE;
//			for(int j=0;j<temp.size();j++) {
//				int dist = Math.abs(home.get(i)[0]-temp.get(j)[0]) +
//						Math.abs(home.get(i)[1]-temp.get(j)[1]);
//				sum = Math.min(sum, dist);
//			}
//			result+=sum;
//		}
//		return result;
//	}
//
//	static void dfs(List<int[]> temp, int start, int limit) {
//		if(temp.size()==limit) {
//			mini = Math.min(mini,cal(temp));
//			return;
//		}
//		for(int i=start;i<chicken.size();i++) {
//			temp.add(chicken.get(i));
//			dfs(temp,i+1,limit);
//			temp.remove(temp.size()-1);
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
//		int m = Integer.parseInt(st.nextToken());
//		for(int i=0;i<n;i++) {
//			st = new StringTokenizer(br.readLine());
//			for(int j=0;j<n;j++) {
//				int x = Integer.parseInt(st.nextToken());
//				if(x==1) home.add(new int[] {i,j});
//				else if(x==2) chicken.add(new int[] {i,j});
//			}
//		}
//		List<int[]> temp = new ArrayList<>();
//		dfs(temp,0,m);
//		System.out.println(sb.append(mini));
//	}
//}
// import java.io.BufferedReader;
// import java.io.IOException;
// import java.io.InputStreamReader;
// import java.util.ArrayList;
// import java.util.Collections;
// import java.util.List;
// import java.util.Stack;
// import java.util.StringTokenizer;
// import java.util.TreeSet;

// public class Main {
	
// 	static int[][] board = new int[51][51];
// 	static List<int[]> home = new ArrayList<>();
// 	static List<int[]> chicken = new ArrayList<>();
// 	static int mini = Integer.MAX_VALUE;
	
// 	static int cal(List<int[]> temp) {
// 		int sum = 0;
// 		for(int i=0;i<home.size();i++) {
// 			int dist = Integer.MAX_VALUE;
// 			int sx = home.get(i)[0];
// 			int sy = home.get(i)[1];
// 			for(int j=0;j<temp.size();j++) {
// 				int ex = temp.get(j)[0];
// 				int ey = temp.get(j)[1];
// 				dist = Math.min(dist, Math.abs(sx-ex) + Math.abs(sy-ey));
// 			}
// 			sum += dist;
// 		}
// 		return sum;
// 	}
	
// 	static void dfs(List<int[]> temp, int limit, int start) {
// 		if(temp.size()==limit) {
// 			mini = Math.min(mini, cal(temp));
// 			return;
// 		}
// 		for(int i=start;i<chicken.size();i++) {
// 			temp.add(chicken.get(i));
// 			dfs(temp,limit,i+1);
// 			temp.remove(temp.size()-1);
// 		}
// 	}
	
// 	public static void main(String[] args) throws NumberFormatException, IOException {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;
		
// 		st = new StringTokenizer(br.readLine());
// 		int n = Integer.parseInt(st.nextToken());
// 		int m = Integer.parseInt(st.nextToken());
// 		for(int i=0;i<n;i++) {
// 			st = new StringTokenizer(br.readLine());
// 			for(int j=0;j<n;j++) {
// 				board[i][j] = Integer.parseInt(st.nextToken());
// 				if(board[i][j]==1) {
// 					home.add(new int[] {i,j});
// 				} else if(board[i][j]==2) {
// 					chicken.add(new int[] {i,j});
// 				}
// 			}
// 		}
// 		List<int[]> temp = new ArrayList<>();
// 		dfs(temp,m,0);
// 		System.out.println(sb.append(mini));
// 	}
// }
import java.io.*;
import java.util.*;

public class Main {

    static List<int[]> house = new ArrayList<>();
    static List<int[]> chicken = new ArrayList<>();

    static int answer = Integer.MAX_VALUE;

    static void cal(List<int[]> temp) {
        int result = 0;
        for(int i=0;i<house.size();i++) {
            int sx = house.get(i)[0];
            int sy = house.get(i)[1];
            int min_diff = Integer.MAX_VALUE;
            for(int j=0;j<temp.size();j++) {
                int ex = temp.get(j)[0];
                int ey = temp.get(j)[1];
                int diff = Math.abs(sx-ex) + Math.abs(sy-ey);
                min_diff = Math.min(min_diff,diff);
            }
            result+=min_diff;
        }
        answer = Math.min(answer,result);
    }

    static void dfs(int n, int m, int start, List<int[]> temp) {
        if(temp.size()==m) {
            cal(temp);
            return;
        }
        for(int i=start;i<chicken.size();i++) {
            temp.add(chicken.get(i));
            dfs(n,m,i+1,temp);
            temp.remove(temp.size()-1);
        }
    }

    public static void main(String[] args) throws IOException {
        // 집, 치킨집 좌표를 각각 리스트에 저장
        // 치킨집 중 m개를 선정
        // 선택된 치킨집 m개를 기준으로 집 좌표 리스트로 치킨거리 계산
        // 치킨거리의 최솟값 선정
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        for(int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<n;j++) {
                int x = Integer.parseInt(st.nextToken());
                if(x==1) house.add(new int[]{i,j});
                else if(x==2) chicken.add(new int[]{i,j});
            }
        }

        List<int[]> temp = new ArrayList<>();
        dfs(n,m,0,temp);

        System.out.println(sb.append(answer).toString());
    }
}

