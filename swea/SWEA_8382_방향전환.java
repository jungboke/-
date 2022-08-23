import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
			st = new StringTokenizer(br.readLine());
			int x1 = Integer.parseInt(st.nextToken());
			int y1 = Integer.parseInt(st.nextToken());
			int x2 = Integer.parseInt(st.nextToken());
			int y2 = Integer.parseInt(st.nextToken());
			int col = Math.abs(x1-x2);
			int row = Math.abs(y1-y2);
			int answer = 0;
			if(row>col) {
				int temp = row; row = col; col = temp;
			}
			if(row==col) answer = row+col;
			else if(row==0) {
				if(col%2==0) answer = col+col;
				else answer = col+col-1;
			}
			else {
				if(row%2==0) {
					if(col%2==0) answer = col+col;
					else answer = col+col-1;
				} else {
					if(col%2==0) answer = col+col-1;
					else answer = col+col;
				}
			}
			sb.append("#"+(ot-t)+" "+answer+"\n");
		}
		System.out.println(sb);
	}
}