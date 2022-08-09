import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class SWEA_1228_암호문1 {
	
	static List<Integer> a = new LinkedList<>();
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("data/1228.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = 10;
		int ot = t;
		while(t-->0) {
			int n = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<n;i++) {
				a.add(Integer.parseInt(st.nextToken()));
			}
			int m = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<m;i++) {
				char x = st.nextToken().charAt(0);
				if(x=='I') {
					int y = Integer.parseInt(st.nextToken());
					int z = Integer.parseInt(st.nextToken());
					List<Integer> temp = new LinkedList<>();
					for(int j=0;j<z;j++) {
						temp.add(Integer.parseInt(st.nextToken()));
					}
					a.addAll(y, temp);
				}
			}
			sb.append("#"+(ot-t)+" ");
			for(int i=0;i<10;i++) sb.append(a.get(i)+" ");
			sb.append("\n");
			a.clear();
		}
		System.out.println(sb);
	}
}
