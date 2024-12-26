//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.List;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	static List<int[]> a = new ArrayList<>();
//
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//
//		int n = Integer.parseInt(br.readLine());
//		for(int i=0;i<n;i++) {
//			st = new StringTokenizer(br.readLine());
//			int x = Integer.parseInt(st.nextToken());
//			int y = Integer.parseInt(st.nextToken());
//			a.add(new int[] {x,y});
//		}
//		int mini = Integer.MAX_VALUE;
//		for(int i=1;i<(1<<n);i++) {
//			int sumS = 1;
//			int sumC = 0;
//			for(int j=0;j<n;j++) {
//				if((i&(1<<j))!=0) {
//					sumS*=a.get(j)[0];
//					sumC+=a.get(j)[1];
//				}
//			}
//			mini = Math.min(mini, Math.abs(sumS-sumC));
//		}
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
	
// 	static List<int[]> a = new ArrayList<>();
// 	static int mini = Integer.MAX_VALUE;
	
// 	public static void main(String[] args) throws NumberFormatException, IOException {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;
		
// 		int n = Integer.parseInt(br.readLine());
// 		for(int i=0;i<n;i++) {
// 			st = new StringTokenizer(br.readLine());
// 			int x = Integer.parseInt(st.nextToken());
// 			int y = Integer.parseInt(st.nextToken());
// 			a.add(new int[] {x,y});
// 		}
// 		for(int i=1;i<(1<<n);i++) {
// 			int mul = 1;
// 			int sum = 0;
// 			for(int j=0;j<n;j++) {
// 				if((i&(1<<j))!=0) {
// 					mul*=a.get(j)[0];
// 					sum+=a.get(j)[1];
// 				}
// 			}
// 			mini = Math.min(mini, Math.abs(mul-sum));
// 		}
// 		System.out.println(sb.append(mini));
// 	}
// }
import java.io.*;
import java.util.*;

public class Main {

    static List<long[]> a = new ArrayList<>();

    static long answer = Long.MAX_VALUE;

    static void cal(List<Integer> temp) {
        // 신맛
        long result1 = 1;
        // 쓴맛
        long result2 = 0;
        for(int i=0;i<temp.size();i++) {
            result1 *= a.get(temp.get(i))[0];
            result2 += a.get(temp.get(i))[1];
        }
        answer = Math.min(answer, Math.abs(result1-result2));
    }


    public static void main(String[] args) throws IOException {
        // 비트마스킹으로 1부터 시작하는 모든 집합을 구함
        // 각 집합을 바탕으로 신맛, 쓴맛 차이가 가장 적은 경우를 계산
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        for(int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            long x = Integer.parseInt(st.nextToken());
            long y = Integer.parseInt(st.nextToken());
            a.add(new long[]{x,y});
        }

        for(int i=1;i<(1<<n);i++) {
            List<Integer> temp = new ArrayList<>();
            for(int j=0;j<n;j++) {
               if((i&(1<<j))!=0) {
                   temp.add(j);
               }
            }
            cal(temp);
        }

        System.out.println(sb.append(answer).toString());
    }
}

