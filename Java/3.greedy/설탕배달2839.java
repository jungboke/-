//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.StringTokenizer;
//
//public class Main {
//	
//	
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		int n = Integer.parseInt(br.readLine());
//		int on = n;
//		int five = n/5;
//		n%=5;
//		while(n%3!=0&&five>=0) {
//			five-=1;
//			n+=5;
//		}
//		if(five<0) sb.append(-1);
//		else sb.append(five+n/3);
//		System.out.println(sb);
//	}
//}
// import java.io.*;
// import java.util.*;

// public class Main {

	
// 	public static void main(String[] args) throws IOException {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;
		
// 		int n = Integer.parseInt(br.readLine());
// 		int answer = n/5;
// 		n%=5;
// 		while(n!=0) {
// 			if(n%3!=0) {
// 				answer-=1;
// 				n+=5;
// 			} else {
// 				answer+=n/3;
// 				n%=3;
// 			}
// 			if(answer==-1) break;
// 		}
// 		System.out.println(sb.append(answer));
// 	}
// }
import java.io.*;
import java.util.*;

public class Main {

    static void dfs(int n, int cnt, StringBuilder sb) {
        if(n==0) {
            System.out.println(sb.append(cnt).toString());
            System.exit(0);
        } else if(n<0) {
            return;
        }
        dfs(n-5,cnt+1,sb);
        dfs(n-3,cnt+1,sb);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        dfs(n,0, sb);
        System.out.println(sb.append(-1).toString());
    }
}

