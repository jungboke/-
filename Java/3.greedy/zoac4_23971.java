import java.io.*;
import java.util.*;

public class Main {

    static long answer = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int h = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int x = h/(n+1);
        if(h%(n+1)!=0) x+=1;
        int y = w/(m+1);
        if(w%(m+1)!=0) y+=1;
        answer = (long)x*y;

        System.out.println(sb.append(answer).toString());
    }
}

