import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	public static int[][] a = new int[5][5];
	public static boolean[][] check = new boolean[5][5];
	
	public static int Bingo(int x) {
		int result = 0;
		outer : for(int i=0;i<5;i++) {
			for(int j=0;j<5;j++) {
				if(a[i][j]==x) {
					check[i][j] = true;
					break outer;
				}
			}
		}
		for(int i=0;i<5;i++) {
			int cnt = 0;
			for(int j=0;j<5;j++) {
				if(check[i][j]==true) cnt+=1;
			}
			if(cnt==5) result+=1;
		}
		for(int j=0;j<5;j++) {
			int cnt = 0;
			for(int i=0;i<5;i++) {
				if(check[i][j]==true) cnt+=1;
			}
			if(cnt==5) result+=1;
		}
		int cnt = 0;
		for(int i=0;i<5;i++) {
			for(int j=0;j<5;j++) {
				if(i-j!=0) continue;
				if(check[i][j]==true) cnt+=1;
			}
			if(cnt==5) result+=1;
		}
		cnt = 0;
		for(int i=0;i<5;i++) {
			for(int j=0;j<5;j++) {
				if(i+j!=4) continue;
				if(check[i][j]==true) cnt+=1;
			}
			if(cnt==5) result+=1;
		}
		return result;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		for(int i=0;i<5;i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for(int j=0;j<5;j++) {
				a[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		int answer = -1;
		int cnt = 1;
		for(int i=0;i<5;i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for(int j=0;j<5;j++) {
				int x = Integer.parseInt(st.nextToken());
				if(Bingo(x)>=3) {
					if(answer==-1) answer = cnt; 
				}
				cnt+=1;
			}
		}
		System.out.println(sb.append(answer).append("\n"));
	}
}

