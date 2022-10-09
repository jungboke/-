//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.StringTokenizer;
//
//public class Main {
//
//	static class Node {
//		char left = '0';
//		char right = '0';
//	}
//
//	static void preorder(char root) {
//		if(root=='0') {
//			return;
//		}
//		System.out.print(root);
//		preorder(a[root-'A'].left);
//		preorder(a[root-'A'].right);
//	}
//
//	static void inorder(char root) {
//		if(root=='0') {
//			return;
//		}
//		inorder(a[root-'A'].left);
//		System.out.print(root);
//		inorder(a[root-'A'].right);
//	}
//
//	static void postorder(char root) {
//		if(root=='0') {
//			return;
//		}
//		postorder(a[root-'A'].left);
//		postorder(a[root-'A'].right);
//		System.out.print(root);
//	}
//
//	static Node[] a = new Node[30];
//
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//
//		int n = Integer.parseInt(br.readLine());
//		for(int i=0;i<n;i++) {
//			st = new StringTokenizer(br.readLine());
//			char x = st.nextToken().charAt(0);
//			char y = st.nextToken().charAt(0);
//			char z = st.nextToken().charAt(0);
//			Node temp = new Node();
//			if(y!='.') temp.left = y;
//			if(z!='.') temp.right = z;
//			a[x-'A'] = temp;
//		}
//		preorder('A');
//		System.out.println();
//		inorder('A');
//		System.out.println();
//		postorder('A');
//	}
//}
import java.io.*;
import java.util.*;

public class Main {
	
	static class Node {
		char v;
		char left;
		char right;
		Node(char v, char left, char right) {
			this.v = v;
			this.left = left;
			this.right = right;
		}
	}
	static Node[] a = new Node[27];
	
	static void preorder(char root) {
		if(root=='.') return;
		System.out.print(a[root-'A'].v);
		preorder(a[root-'A'].left);
		preorder(a[root-'A'].right);
	}
	
	static void inorder(char root) {
		if(root=='.') return;
		inorder(a[root-'A'].left);
		System.out.print(a[root-'A'].v);
		inorder(a[root-'A'].right);
	}
	
	static void postorder(char root) {
		if(root=='.') return;
		postorder(a[root-'A'].left);
		postorder(a[root-'A'].right);
		System.out.print(a[root-'A'].v);
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			char x = st.nextToken().charAt(0);
			char y = st.nextToken().charAt(0);
			char z = st.nextToken().charAt(0);
			Node temp = new Node(x,y,z);
			a[x-'A'] = temp;
		}
		preorder('A');
		System.out.println();
		inorder('A');
		System.out.println();
		postorder('A');
	}
}
