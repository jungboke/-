- 점화식을 제대로만 세울수 있으면 쉽게 풀 수 있음.
  해당 문제는 특이하게 d(메모이제이션)배열에 int형 단일 값이 아닌 set을 사용해야 함. 어떤 값을 점화식의 타겟값으로 잡아 d[~]내에 사용할 것인지 파악하는 연습이 필요함.

1

```
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
vector<unordered_set<int>> d(10);

int make_NN(int N, int cnt) {
    int temp = 0;
    for(int i=0;i<cnt;i++) {
        temp = 10*temp + N;
    }
    return temp;
}

int solution(int N, int number) {
    int answer = 0;
    d[1].insert(N);
    for(int i=2;i<=9;i++) {
        for(int j=1;j<=i-1;j++) {
            for(auto k:d[j]) {
                for(auto c:d[i-j]) {
                    d[i].insert(k+c);
                    if(k-c>0) d[i].insert(k-c);
                    d[i].insert(k*c);
                    if(k/c>0) d[i].insert(k/c);
                }
            }
        }
        d[i].insert(make_NN(N,i));
    }
    for(int i=1;i<=9;i++) {
        if(d[i].empty()) continue;
        if(d[i].find(number)!=d[i].end()) {
            answer = i;
            break;
        }
    }
    if(answer==0) answer = -1;
    return answer;
}
```
