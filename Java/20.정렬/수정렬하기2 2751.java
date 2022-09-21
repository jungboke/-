import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static List<Integer> a = new ArrayList<>();
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		for(int i=0;i<n;i++) {
			int x = Integer.parseInt(br.readLine());
			a.add(x);
		}
		Collections.sort(a);
		for(int i=0;i<n;i++) {
			sb.append(a.get(i)+"\n");
		}
		System.out.println(sb);
	}
}