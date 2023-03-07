/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<double> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    double answer = a[n-1];
    for(int i=0;i<n-1;i++)
    {
        answer += (a[i]/2);
    }
    cout << answer << '\n';
    return 0;
}
*/
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     vector<double> a(n);
//     for(int i=0;i<n;i++)
//     {
//         cin >> a[i];
//     }
//     sort(a.begin(),a.end());
//     double answer = a[n-1];
//     for(int i=0;i<n-1;i++)
//     {
//         answer += a[i]/2;
//     }
//     cout << answer << '\n';
//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//   int n;
//   cin >> n;
//   multiset<double> ms;
//   for(int i=0;i<n;i++) {
//     double x;
//     cin >> x;
//     ms.insert(x);
//   }
//   while(ms.size()!=1) {
//     auto it = ms.end();
//     it--;
//     double x = *it;
//     ms.erase(it);
//     double y = *ms.begin();
//     ms.erase(ms.begin());
//     ms.insert(x+(y/2));
//   }

//   cout << *ms.begin() << '\n';
//   return 0; 
// }
import java.util.*;
import java.io.*;

public class Main {
	
	static TreeMap<Double, Integer> map1 = new TreeMap<Double, Integer>();
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			double x = Integer.parseInt(st.nextToken());
			map1.put(x, map1.getOrDefault(x, 0)+1);
		}
		while(map1.size()!=1) {
			double start = map1.firstKey();
			double end = map1.lastKey();
			map1.put(start/2+end, map1.getOrDefault(start/2+end, 0)+1);
			if(map1.put(start, map1.get(start)-1)==1) {
				map1.remove(start);
			}
			if(map1.put(end, map1.get(end)-1)==1) {
				map1.remove(end);
			}
		}
		System.out.println(sb.append(map1.firstKey()));
	}
}
