// import java.io.BufferedReader;
// import java.io.IOException;
// import java.io.InputStreamReader;
// import java.util.Deque;
// import java.util.LinkedList;
// import java.util.Queue;
// import java.util.StringTokenizer;

// public class Main {

// 	public static void main(String[] args) throws NumberFormatException, IOException {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;
// 		Deque<Integer> q = new LinkedList<>();

// 		int n = Integer.parseInt(br.readLine());
// 		for(int i=0;i<n;i++) {
// 			st = new StringTokenizer(br.readLine()," ");
// 			String x = st.nextToken();
// 			if(x.equals("push")) {
// 				int y = Integer.parseInt(st.nextToken());
// 				q.offer(y);
// 			} else if(x.equals("pop")) {
// 				if(q.isEmpty()) sb.append(-1).append("\n");
// 				else {
// 					sb.append(q.peekFirst()).append("\n");
// 					q.pollFirst();
// 				}
// 			} else if(x.equals("size")) {
// 				sb.append(q.size()).append("\n");
// 			} else if(x.equals("empty")) {
// 				if(q.isEmpty()) sb.append(1).append("\n");
// 				else sb.append(0).append("\n");
// 			} else if(x.equals("front")) {
// 				if(q.isEmpty()) sb.append(-1).append("\n");
// 				else sb.append(q.peekFirst()).append("\n");
// 			} else if(x.equals("back")) {
// 				if(q.isEmpty()) sb.append(-1).append("\n");
// 				else sb.append(q.peekLast()).append("\n");
// 			}
// 		}
// 		System.out.println(sb);
// 	}
// }
import java.io.*;
import java.util.*;

public class Main {

    static Deque<Integer> q = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        for(int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine()," ");
            String x = st.nextToken();
            if("push".equals(x)) {
                String y = st.nextToken();
                q.offer(Integer.parseInt(y));
            } else if("pop".equals(x)) {
                if(q.isEmpty()) sb.append("-1").append("\n");
                else sb.append(Integer.toString(q.pollFirst())).append("\n");
            } else if("size".equals(x)) {
                sb.append(q.size()).append("\n");
            } else if("empty".equals(x)) {
                sb.append(q.isEmpty()==true?1:0).append("\n");
            } else if("front".equals(x)) {
                if(q.isEmpty()) sb.append("-1").append("\n");
                else sb.append(Integer.toString(q.peekFirst())).append("\n");
            } else if("back".equals(x)) {
                if(q.isEmpty()) sb.append("-1").append("\n");
                else sb.append(Integer.toString(q.peekLast())).append("\n");
            }
        }
        System.out.println(sb.toString());
    }
}

