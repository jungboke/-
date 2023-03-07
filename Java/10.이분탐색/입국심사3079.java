// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n;
//     long long m;
//     cin >> n >> m;
//     vector<long long> a(n);
//     for(int i=0;i<n;i++)
//     {
//         cin >> a[i];
//     }
//     long long start = 1;
//     long long end = *max_element(a.begin(),a.end()) * m;
//     long long mini = end+1;
//     while(start<=end)
//     {
//         long long mid = (start+end)/2;
//         long long man = 0;
//         for(int i=0;i<a.size();i++)
//         {
//             man += mid/a[i];
//         }
//         if(man>=m)
//         {
//             end = mid-1;
//             if(mini>mid) mini = mid;
//         }
//         else
//         {
//             start = mid+1;
//         }
//     }
//     cout << mini << '\n';
//     return 0;
// }
import java.util.*;
import java.io.*;

public class Main {
	
	static List<Long> a = new ArrayList<>();
	static long answer = Long.MAX_VALUE;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		long m = Integer.parseInt(st.nextToken());
		for(int i=0;i<n;i++) {
			long x = Integer.parseInt(br.readLine());
			a.add(x);
		}
		long start = 0;
		long end = (long)Collections.max(a)*m;
		while(start<=end) {
			long mid = (start+end)/2;
			long sum = 0;
			for(int i=0;i<n;i++) {
				sum += (mid/a.get(i));
				if(sum>=m) break;
			}
			if(sum>=m) {
				end = mid-1;
				answer = Math.min(answer, mid);
			} else {
				start = mid+1;
			}
		}
		System.out.println(sb.append(answer));
	}
}

/*
    이분탐색시 upperbound,lowerbound 개념으로 생각.
*/