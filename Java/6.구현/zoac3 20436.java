import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static char[][] a = {
			{'q','w','e','r','t','y','u','i','o','p'},
			{'a','s','d','f','g','h','j','k','l'},
			{'z','x','c','v','b','n','m'}
	};


	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		int lx = 0,ly = 0,rx = 0,ry = 0;
		st = new StringTokenizer(br.readLine(), " ");
		char x = st.nextToken().charAt(0);
		char y = st.nextToken().charAt(0);
		String z = br.readLine();
		for(int i=0;i<a.length;i++) {
			for(int j=0;j<a[i].length;j++) {
				if(a[i][j]==x) {
					lx = i;
					ly = j;
				} else if(a[i][j]==y) {
					rx = i;
					ry = j;
				}
			}
		}
		int answer = 0;
		for(int c=0;c<z.length();c++) {
			int nx = 0,ny = 0;
			for(int i=0;i<a.length;i++) {
				for(int j=0;j<a[i].length;j++) {
					if(a[i][j]==z.charAt(c)) {
						nx = i;
						ny=  j;
					}
				}
			}
			if(ny<=4&&!(nx==2&&ny==4)) {
				answer += Math.abs(lx-nx) + Math.abs(ly-ny);
				lx = nx;
				ly = ny;
			} else {
				answer += Math.abs(rx-nx) + Math.abs(ry-ny);
				rx = nx;
				ry = ny;
			}
		}
		System.out.println(sb.append(answer+z.length()).append("\n"));
	}
}
