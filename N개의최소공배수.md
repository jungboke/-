1
```
#include <string>
#include <vector>
using namespace std;
int go(int a,int b)
{
    int mul = a % b;
    while(mul!=0)
    {
        a = b;
        b = mul;
        mul = a % b;
    }
    return b;
}

int solution(vector<int> arr) {
    int answer = 0;
    for(int i=0;i<arr.size()-1;i++)
    {
        int a = arr[i];
        int b = arr[i+1];
        int yak = go(a,b);
        int mul = a * b;
        int x = mul / yak;
        arr[i] = x;
        arr.erase(arr.begin()+i+1);
        i--;
    }
    answer = arr[0];
    return answer;
}
```
2
```

```
+ 유클리드 호제법을 응용