import java.util.*;
import java.io.*;

public class Solution {
	
	static int[][] board = new int[11][11];
	static List<int[]> people = new ArrayList<>();
	static List<int[]> gate = new ArrayList<>();
	static int answer = Integer.MAX_VALUE;
	
	static int cal(List<int[]> group, int[] gate) {
		List<Integer> move = new ArrayList<>();
		List<Integer> wait = new ArrayList<>();
		List<Integer> down = new ArrayList<>();
		int ex = gate[0]; int ey = gate[1];
		for(int i=0;i<group.size();i++) {
			int sx = group.get(i)[0]; int sy = group.get(i)[1];
			move.add(Math.abs(sx-ex)+Math.abs(sy-ey));
		}
		int t = 0;
		while(!(move.isEmpty()&&wait.isEmpty()&&down.isEmpty())) {
			t+=1;
			for(int i=0;i<down.size();i++) {
				down.set(i, down.get(i)-1);
				if(down.get(i)==0) {
					down.remove(i);
					i-=1;
				}
			}
			for(int i=0;i<wait.size();i++) {
				wait.set(i, wait.get(i)-1);
				if(wait.get(i)<=0&&down.size()<3) {
					down.add(gate[2]);
					wait.remove(i);
					i-=1;
				}
			}
			for(int i=0;i<move.size();i++) {
				move.set(i, move.get(i)-1);
				if(move.get(i)<=0&&wait.size()<3) {
					wait.add(1);
					move.remove(i);
					i-=1;
				}
			}
		}
		return t;
	}
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("data/2383.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		int ot = t;
		while(t-->0) {
			int n = Integer.parseInt(br.readLine());
			for(int i=0;i<n;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<n;j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
					if(board[i][j]==1) {
						people.add(new int[] {i,j});
					} else if(board[i][j]!=0) {
						gate.add(new int[] {i,j,board[i][j]});
					}
				}
			}
			int k = people.size();
			for(int i=0;i<(1<<k);i++) {
				List<int[]> a = new ArrayList<>();
				List<int[]> b = new ArrayList<>();
				for(int j=0;j<k;j++) {
					if((i&(1<<j))!=0) a.add(people.get(j));
					else b.add(people.get(j));
				}
				int time1 = cal(a,gate.get(0));
				int time2 = cal(b,gate.get(1));
				int totalTime = Math.max(time1, time2);
				answer = Math.min(answer, totalTime);
			}
			sb.append("#"+(ot-t)+" "+answer+"\n");
			answer = Integer.MAX_VALUE;
			people.clear();
			gate.clear();
		}
		System.out.println(sb);
	}
}
