//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.Map.Entry;
//import java.util.StringTokenizer;
//import java.util.TreeMap;
//
//public class Main {
//
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringBuilder sb = new StringBuilder();
//		StringTokenizer st;
//		TreeMap<String,Integer> map1 = new TreeMap<>();
//
//		while(true) {
//			String x = br.readLine();
//			if(x==null||x.equals("")) break;
//			map1.put(x,map1.getOrDefault(x, 0)+1);
//		}
//		int sum = 0;
//		for(Entry<String,Integer> e : map1.entrySet()) {
//			sum += e.getValue();
//		}
//		for(Entry<String,Integer> e : map1.entrySet()) {
//			double temp = ((double)e.getValue()/sum)*100;
//			sb.append(e.getKey() + ' ' + String.format("%.4f", temp) + "\n");
//		}
//		System.out.println(sb);
//	}
//}
// import java.io.BufferedReader;
// import java.io.IOException;
// import java.io.InputStreamReader;
// import java.util.ArrayList;
// import java.util.Arrays;
// import java.util.Collections;
// import java.util.Comparator;
// import java.util.HashMap;
// import java.util.LinkedList;
// import java.util.List;
// import java.util.Map.Entry;
// import java.util.Queue;
// import java.util.StringTokenizer;
// import java.util.TreeMap;

// public class Main {
	
// 	static TreeMap<String, Integer> map1 = new TreeMap<>(); 
	
// 	public static void main(String[] args) throws NumberFormatException, IOException {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;
		
// 		while(true) {
// 			String x = br.readLine();
// 			if(x==null||x.equals("")) break;
// 			map1.put(x,map1.getOrDefault(x, 0)+1);
// 		}
// 		int sum = 0;
// 		for(Entry<String, Integer> e : map1.entrySet()) {
// 			sum += e.getValue();
// 		}
// 		for(Entry<String, Integer> e : map1.entrySet()) {
// 			double temp = ((double)e.getValue()/sum)*100;
// 			sb.append(e.getKey() + " " + String.format("%.4f", temp) + "\n");
// 		}
// 		System.out.println(sb);
// 	}
// }
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        TreeMap<String, Integer> map1 = new TreeMap<>();

        while(true) {
            String x = br.readLine();
            if(x==null||"".equals(x)) break;
            map1.put(x,map1.getOrDefault(x,0)+1);
        }

        int sum = 0;

        for(Map.Entry<String, Integer> e : map1.entrySet()) {
            sum+=e.getValue();
        }

        for(Map.Entry<String, Integer> e : map1.entrySet()) {
            double y = ((double)e.getValue()/sum)*100;
            sb.append(e.getKey()).append(" ").append(String.format("%.4f",y)).append("\n");
        }

        System.out.println(sb.toString());
    }
}

