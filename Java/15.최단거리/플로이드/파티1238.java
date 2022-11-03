import java.io.*;
import java.util.*;

public class Main {
	
	static int[][] a = new int[1001][1001];
	static int answer = -1;
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        for(int i=1;i<=n;i++) {
        	for(int j=1;j<=n;j++) a[i][j] = Integer.MAX_VALUE;
        }
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        for(int i=0;i<m;i++) {
        	st = new StringTokenizer(br.readLine());
        	int x = Integer.parseInt(st.nextToken());
        	int y = Integer.parseInt(st.nextToken());
        	int z = Integer.parseInt(st.nextToken());
        	a[x][y] = z;
        }
        for(int c=1;c<=n;c++) {
        	for(int i=1;i<=n;i++) {
        		for(int j=1;j<=n;j++) {
        			if(a[i][c]!=Integer.MAX_VALUE&&a[c][j]!=Integer.MAX_VALUE) {
        				a[i][j] = Math.min(a[i][j],a[i][c]+a[c][j]);
        			}
        		}
        	}
        }
        for(int i=1;i<=n;i++) {
        	if(i==k) continue;
        	answer = Math.max(answer, a[i][k]+a[k][i]);
        }
        System.out.println(sb.append(answer));
	}
}