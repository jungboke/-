//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.List;
//import java.util.StringTokenizer;
//
//public class Main {
//	
//	static List<Integer> a = new ArrayList<>();
//	
//	static void dfs(List<Integer> temp, int start) {
//		if(temp.size()==7) {
//			int sum = 0;
//			for(int i=0;i<temp.size();i++) {
//				sum+=temp.get(i);
//			}
//			if(sum==100) {
//				for(int i=0;i<temp.size();i++) {
//					System.out.println(temp.get(i));
//				}
//				System.exit(0);
//			}
//			return;
//		}
//		for(int i=start;i<a.size();i++) {
//			temp.add(a.get(i));
//			dfs(temp,i+1);
//			temp.remove(temp.size()-1);
//		}
//	}
//
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		
//		for(int i=0;i<9;i++) {
//			int x = Integer.parseInt(br.readLine());
//			a.add(x);
//		}
//		List<Integer> temp = new ArrayList<>();
//		dfs(temp,0);
//	}
//}
import java.io.*;
import java.util.*;

public class Main {

	static List<Integer> a = new ArrayList<>();
	
	static void dfs(List<Integer> temp, int start) {
		if(temp.size()==7) {
			int sum = 0;
			for(int i=0;i<temp.size();i++) {
				sum+=temp.get(i);
			}
			if(sum==100) {
				for(int i=0;i<temp.size();i++) {
					System.out.println(temp.get(i));
				}
				System.exit(0);
			}
			return;
		}
		for(int i=start;i<a.size();i++) {
			temp.add(a.get(i));
			dfs(temp,i+1);
			temp.remove(temp.size()-1);
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		for(int i=0;i<9;i++) {
			int x = Integer.parseInt(br.readLine());
			a.add(x);
		}
		List<Integer> temp = new ArrayList<>();
		dfs(temp,0);
	}
}