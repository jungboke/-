import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Algo3_대전_8반_백승범 {
	
	static char[][] board = new char[30001][31];
	static int R,C;
	
	static int check(int y) {
		int result = -1;
		for(int i=0;i<R;i++) {
			if(board[i][y]=='.') {
				result = i;
				break;
			} else {
				break;
			}
		}
		return result;
	}
	
	static void move(int x ,int y) {
		// 마지막 열까지 진행하기 위해 while문 사용
		while(x+1<R) {
			if(board[x+1][y]=='.') {
				x+=1;
			} else if(board[x+1][y]=='O') {
				if(y-1>=0&&board[x][y-1]=='.'&&board[x+1][y-1]=='.') {
					x+=1;
					y-=1;
				} else if(y+1<C&&board[x][y+1]=='.'&&board[x+1][y+1]=='.') {
					x+=1;
					y+=1;
				} else {
					break;
				}
			} else {
				break;
			}
		}
		// 최종적으로 화산암이 도착할 수 있는 위치를 O으로 바꿔줌.
		board[x][y] = 'O';
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		// R, C 입력
		st = new StringTokenizer(br.readLine());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		R=r;C=c;
		// RXC 2차원배열 입력
		for(int i=0;i<r;i++) {
			String temp = br.readLine();
			for(int j=0;j<c;j++) {
				board[i][j] = temp.charAt(j);
			}
		}
		// N개의 y좌표 입력
		int n = Integer.parseInt(br.readLine());
		for(int i=0;i<n;i++) {
			// 인덱스 0부터 계산하기 위해 -1
			int y = Integer.parseInt(br.readLine())-1;
			int x = check(y);
			// y열의 상단부터 체크하여 화산암이 떨어질 자리가 없으면 -1리턴
			if(x==-1) continue;
			// x,y 좌표에서 시작하여 화산암의 최대 이동경로 계산
			move(x,y);
		}
		// 결과배열 출력
		for(int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {
				sb.append(board[i][j]);
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
