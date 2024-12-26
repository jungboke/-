// import java.io.BufferedReader;
// import java.io.IOException;
// import java.io.InputStreamReader;
// import java.util.StringTokenizer;
// import java.util.TreeMap;

// public class Main {

// 	public static void main(String[] args) throws NumberFormatException, IOException {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;

// 		int t = Integer.parseInt(br.readLine());
// 		while(t-->0) {
// 			TreeMap<Integer, Integer> map1 = new TreeMap<Integer, Integer>();
// 			int n = Integer.parseInt(br.readLine());
// 			for(int i=0;i<n;i++) {
// 				st = new StringTokenizer(br.readLine(), " ");
// 				String x = st.nextToken();
// 				if(x.equals("I")) {
// 					int y = Integer.parseInt(st.nextToken());
// 					map1.put(y, map1.getOrDefault(y, 0) + 1);
// 				} else if(x.equals("D")) {
// 					int y = Integer.parseInt(st.nextToken());
// 					if(map1.size()==0) continue;
// 					int z = y == 1 ? map1.lastKey() : map1.firstKey();
// 					if(map1.put(z, map1.get(z)-1)==1) {
// 						map1.remove(z);
// 					}
// 				}
// 			}
// 			if(map1.isEmpty()) {
// 				sb.append("EMPTY").append("\n");
// 			} else {
// 				sb.append(map1.lastKey()).append(" ").append(map1.firstKey()).append("\n");
// 			}
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

        int t = Integer.parseInt(br.readLine());
        while(t-->0) {
            TreeMap<Integer, Integer> map1 = new TreeMap<>();
            int x = Integer.parseInt(br.readLine());
            for(int i=0;i<x;i++) {
                st = new StringTokenizer(br.readLine()," ");
                String y = st.nextToken();
                int z = Integer.parseInt(st.nextToken());
                if("I".equals(y)) map1.put(z,map1.getOrDefault(z,0)+1);
                else if("D".equals(y)) {
                    if(map1.size()==0) continue;
                    if(z==-1) {
                        int k = map1.firstKey();
                        if(map1.put(k,map1.get(k)-1)==1) {
                            map1.remove(k);
                        }
                    } else if(z==1) {
                        int k = map1.lastKey();
                        if(map1.put(k,map1.get(k)-1)==1) {
                            map1.remove(k);
                        }
                    }
                }
            }
            if(map1.size()==0) {
                sb.append("EMPTY").append("\n");
            } else {
                sb.append(map1.lastKey()).append(" ").append(map1.firstKey()).append("\n");
            }
        }
        System.out.println(sb.toString());
    }
}

