import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static int dx[] = {-1,-1,-1,0,1,1,1,0};
	public static int dy[] = {-1,0,1,1,1,0,-1,-1};

	public static char[][] a = new char[11][11];
	public static char[][] b = new char[11][11];
	public static int N;

	public static void bomb() {
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(a[i][j]=='*') b[i][j] = '*';
			}
		}
	}

	public static int change(int x ,int y) {
		int cnt = 0;
		for(int i=0;i<8;i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx>=0&&nx<N&&ny>=0&&ny<N) {
				if(a[nx][ny]=='*') cnt+=1;
			}
		}
		return cnt;
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		int n = Integer.parseInt(br.readLine());
		N=n;
		for(int i=0;i<n;i++) {
			String temp = br.readLine();
			for(int j=0;j<n;j++) {
				a[i][j] = temp.charAt(j);
			}
		}
		for(int i=0;i<n;i++) {
			String temp = br.readLine();
			for(int j=0;j<n;j++) {
				b[i][j] = temp.charAt(j);
			}
		}
		outer : for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(b[i][j]=='x') {
					if(a[i][j]=='*') bomb();
					else b[i][j] = (char)(change(i,j)+'0');
				}
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				sb.append(b[i][j]);
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
