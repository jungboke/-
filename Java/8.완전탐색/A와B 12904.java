import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static void dfs(String a, String b) {
		if(a.length()==b.length()) {
			if(a.equals(b)) {
				System.out.println(1);
				System.exit(0);
			}
			return;
		}
		if(a.endsWith("A")) {
			String temp = a.substring(0, a.length()-1);
			dfs(temp,b);
		}
		if(a.endsWith("B")) {
			String temp = a.substring(0,a.length()-1);
			String temp2 = new StringBuilder(temp).reverse().toString();
			dfs(temp2,b);
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		String a = br.readLine();
		String b = br.readLine();
		dfs(b,a);
		System.out.println(0);
	}
}