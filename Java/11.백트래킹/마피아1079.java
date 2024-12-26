// import java.io.*;
// import java.util.*;

// public class Main {
	
// 	static int[][] board = new int[17][17];
// 	static int[] gp = new int[17];
// 	static boolean[] check = new boolean[17];
// 	static int answer = 0;
// 	static int N,K;
	
	
// 	static void dfs(int cnt, int day) {
// 		if(cnt%2==0) {
// 			if(cnt==2) {
// 				answer = Math.max(answer, day+1);
// 				return;
// 			}
// 			for(int i=0;i<N;i++) {
// 				if(i==K) continue;
// 				if(check[i]==true) continue;
// 				check[i] = true;
// 				for(int j=0;j<N;j++) {
// 					gp[j]+=board[i][j];
// 				}
// 				dfs(cnt-1,day+1);
// 				for(int j=0;j<N;j++) {
// 					gp[j]-=board[i][j];
// 				}
// 				check[i] = false;
// 			}
// 		} else {
// 			int maxi = Integer.MIN_VALUE;
// 			int max_idx = -1;
// 			for(int i=0;i<N;i++) {
// 				if(check[i]==true) continue;
// 				if(gp[i]>maxi) {
// 					maxi = gp[i];
// 					max_idx = i;
// 				}
// 			}
// 			if(max_idx==K) {
// 				answer = Math.max(answer, day);
// 				return;
// 			}
// 			check[max_idx] = true;
// 			dfs(cnt-1,day);
// 			check[max_idx] = false;
// 		}
// 	}
	
// 	public static void main(String[] args) throws NumberFormatException, IOException {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;
		
// 		int n = Integer.parseInt(br.readLine());
// 		N=n;
// 		st = new StringTokenizer(br.readLine());
// 		for(int i=0;i<n;i++) {
// 			gp[i] = Integer.parseInt((st.nextToken()));
// 		}
// 		for(int i=0;i<n;i++) {
// 			st = new StringTokenizer(br.readLine());
// 			for(int j=0;j<n;j++) {
// 				board[i][j] = Integer.parseInt(st.nextToken());
// 			}
// 		}
// 		int k = Integer.parseInt(br.readLine());
// 		K=k;
// 		dfs(n,0);
// 		System.out.println(sb.append(answer));
// 	} 
// }
// import java.io.*;
// import java.util.*;

// public class Main {
	
// 	static int[] point = new int[17];
// 	static int[][] a = new int[17][17];
// 	static boolean[] check = new boolean[17];
// 	static int answer = Integer.MIN_VALUE;
// 	static int N,M;
	
// 	static void kill(int x, boolean flag) {
// 		if(flag==true) {
// 			for(int i=0;i<N;i++) {
// 				point[i]+=a[x][i];
// 			}
// 		} else {
// 			for(int i=0;i<N;i++) {
// 				point[i]-=a[x][i];
// 			}
// 		}
// 	}
	
// 	static void dfs(int cnt, int day) {
// 		if(cnt%2==0) {
// 			if(cnt==2) {
// 				answer = Math.max(answer, day+1);
// 				return;
// 			}
// 			for(int i=0;i<N;i++) {
// 				if(i==M) continue;
// 				if(check[i]==true) continue;
// 				check[i] = true;
// 				kill(i,true);
// 				dfs(cnt-1,day+1);
// 				kill(i,false);
// 				check[i] = false;
// 			}			
// 		} else {
// 			int maxi = Integer.MIN_VALUE;
// 			int max_num = -1;
// 			for(int i=0;i<N;i++) {
// 				if(check[i]==true) continue;
// 				if(maxi<point[i]) {
// 					maxi = point[i];
// 					max_num = i;
// 				}
// 			}
// 			if(max_num==M) {
// 				answer = Math.max(answer, day);
// 				return;
// 			}
// 			check[max_num] = true;
// 			dfs(cnt-1,day);
// 			check[max_num] = false;
// 		}
		
// 	}
	
// 	public static void main(String[] args) throws Exception {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringBuilder sb = new StringBuilder();
// 		StringTokenizer st;
		
// 		int n = Integer.parseInt(br.readLine());
// 		N=n;
// 		st = new StringTokenizer(br.readLine());
// 		for(int i=0;i<n;i++) {
// 			point[i] = Integer.parseInt(st.nextToken());
// 		}
// 		for(int i=0;i<n;i++) {
// 			st = new StringTokenizer(br.readLine());
// 			for(int j=0;j<n;j++) {
// 				a[i][j] = Integer.parseInt(st.nextToken());
// 			}
// 		}
// 		int m = Integer.parseInt(br.readLine());
// 		M=m;
// 		dfs(n,0);
// 		System.out.println(sb.append(answer));
// 	}
// }
import java.io.*;
import java.util.*;

public class Main {

    static int[] gp = new int[16];

    static int[][] cp = new int[16][16];

    static boolean[] check = new boolean[16];

    static int answer = 0;

    static void cal(int x, int n) {
        for(int i=0;i<n;i++) {
            gp[i] += cp[x][i];
        }
    }

    static void decal(int x, int n) {
        for(int i=0;i<n;i++) {
            gp[i] -= cp[x][i];
        }
    }

    static void dfs(int n, int m, int day, int cnt) {
        if(cnt%2==1) {
            int maxi = Integer.MIN_VALUE;
            int maxi_num = -1;
            for(int i=0;i<n;i++) {
                if(check[i]==true) continue;
                if(maxi<gp[i]) {
                    maxi = gp[i];
                    maxi_num = i;
                }
            }
            if(maxi_num==m) {
                answer = Math.max(answer,day);
                return;
            } else {
                check[maxi_num] = true;
                dfs(n,m,day,cnt-1);
                check[maxi_num] = false;
            }
        } else {
            for(int i=0;i<n;i++) {
                if(check[i]==true) continue;
                if(i==m) continue;
                check[i] = true;
                cal(i,n);
                dfs(n,m,day+1,cnt-1);
                decal(i,n);
                check[i] = false;
            }
        }

    }

    public static void main(String[] args) throws IOException {
        // 은진이의 유죄지수가 가장 높게 되면 날짜를 최댓값과 비교하고 되돌아가는 백트래킹 작성
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++) {
            gp[i] = Integer.parseInt(st.nextToken());
        }
        for(int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<n;j++) {
                cp[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int m = Integer.parseInt(br.readLine());

        dfs(n,m,0,n);

        System.out.println(sb.append(answer).toString());
    }
}


