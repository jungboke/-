## JAVA

### Java가 없는 것

- next_permutation, swap, pair, upper_bound, lower_bound, multi_set

### 기본

- 입력은 BufferedReader와 StringTokenizer를 활용하고,
  출력은 StringBuilder를 사용하여 append해서 출력함.
- Stack은 Stack<Integer> 처럼 사용되며, top()이 peek()으로
  명명됨.
- Queue는 offer, Set,List는 add, Map은 put, Stack은 push
- Queue와 Deque는 LinkedList<> 처럼 사용됨.
- Deque는 Queue의 C++ 활용과 비슷함.

```
q.offer();	// push
q.poll();	// pop
q.size();	// size
q.isEmpty();	// empty
q.peek();	// front
q.peekLast();	// back
```

- unordered_map은 HashMap이고, map은 TreeMap임.
- 자바에서 map은 배열로 접근불가하고, get,put으로 접근함.
- map[x]+=1; 식의 방법을 적용하려면 put(x,map.get(x)+1) 처럼 접근함. 이는 동일 키값을 넣을 시, 최근 값이 적용되는 점을 이용한 것임.
  그리고, c++과는 다르게 존재하지 않는 x에 대해 map[x]=0 으로 안나오고, null로 나오므로, null값 처리를 따로 해줘야함. getOrDefault를 통해 null일 때, 0으로 바꿔줄 수 있음. 또한 put의 반환값은 이전 value값이기 때문에 if(map1.put(~)==1) 을 통해 쉽게 value가 0이 되면 제거해줄 수 있음. - 이중우선순위큐
- 우선순위큐는 PriorityQueue<> 처럼 사용되며, 최대힙이 아닌 최소힙으로 적용됨. 따라서 PriorityQueue<>(Collections.reverseOrder())로 최대힙으로 변경해줄 수 있음. 내장함수명은 Queue와 같음.
- Set도 Map과 마찬가지로 HashSet과 TreeSet으로 나뉘는데, Hash는 unordered이고 Tree는 ordered임. Multiset은 Java STL에 없고, Guava라는 라이브러리를 사용해야 함. C++처럼 foreach문으로 순회가능함. Multiset은 구글 라이브러리를 따로 사용해야한다는 점에서 거의 안쓰이고, TreeMap을 주로 사용함.
  +) Set은 add와 remove를 사용함.
- c++의 가변크기 배열 vector는 java에서 ArrayList<>로 사용함.
- java STL 자료구조의 new 부분에서 <> 부분은 비워두고 선언부분에서만 명시해도 됨.
- String의 toCharArray()를 통해 String을 char배열로
  변환시킬 수 있음.
- ArrayList는 배열 인덱스가 아닌 get()으로 접근해야 하기 때문에 vector에 비해서 편의성이 떨어짐. 따라서 java로 문제를 풀때는 최대한 일반 고정배열로 해결하는 게 좋을 듯함. 어차피 c++과는 다르게 함수에 배열을 넘겨줄 수 있음.
- 2차원 ArrayList를 사용할 일이 있으면 `new ArrayList[100];` 처럼 ArrayList를 배열화해서 사용하는 게 좋을 듯함.
- 자바에서 Pair API는 있긴한데, JDK가 특정버전 이상이어야 해서, 코테에서 활용못할 수 도 있음. 따라서 int[]를 pair처럼 사용함. c++과는 다르게 배열을 매개변수나 타입으로 쉽게 활용할 수 있어서 그나마 다행임.
- 자바에서 memset은 Arrays.fill() 함수를 사용함. 2차원은 for문 Arrays.fill()을 활용해야 함.
- 자바에는 call by reference가 없는데 객체를 매개변수로 넘길 때, 주소값이 넘어가는 형태라 이걸 참조라고 할 수 없음. 따라서 call by value인 셈임. 참조란 담다는 의미임.
- 자바에서 String은 불변이기 때문에 String을 조작해야 하는 경우, String을 toCharArray로 변환한 Array를 다루는 게 좋음. 또한, StringBuilder는 출력값을 만들 때만 사용하는 게 아닌, String을 직접 char을 추가해가며 생성할 때 써야 함.
- Set을 sorting해야 할 때, 애초에 TreeSet을 통해 생성하면 자동정렬됨.
- 재귀함수에 String을 toCharArray한 Array를 매개변수로 넘겨질때, Array의 주소가 넘어가므로, 참조처럼 값변경이 이뤄진다는 것을 알아야함. 이때문에 매 재귀마다 같아야할 Array가 달라져서 문제가 됨.
- 자바에서는 eof를 받기 위해 br.readLine이 null이거나 ""일시, while(true) 문을 break해줌. 또한 소수점아래 ~자리를 표현하기 위해 String.format("%.4f", temp)처럼 사용함. - 생태학
- c++에서 그래프문제를 풀때, vector<int> a[100] 처럼 사용했던 것을 java에서는 똑같이 ArrayList[100]처럼 만들면 됨. 다만, for문을 통해 모든 ArrayList 배열을 new ArrayList로 초기화해주는 과정이 필요함. - 트리의 부모찾기
- ArrayList에서 max_element는 Collections.max()를 사용함.
- Integer.MAX_VALUE를 통해 INF값 대체함.
- String은 toCharArray, StringBuilder를 통해 특정 인덱스 값을 바꿀수 있는데, 왠만하면 StringBuilder 쓰는게 깔끔할 듯함.
- Array 복사는 Arrays.copyOf를 사용하고, List 복사는 new ArrayList<>(a) 처럼 ()안에 복사하려는 List를 넣음.
- 직접만든 클래스(Edge,Node)등을 사용하는 PriorityQueue는 Comparable을 사용하고, 단순 int, String 같은 경우는 Comparator를 사용해줌.

```
static PriorityQueue<Integer> pq = new PriorityQueue<>(new Comparator<Integer>() {
		public int compare(Integer x, Integer y) {
			if(Math.abs(x)==Math.abs(y)) {
				return Integer.compare(x, y);
			}
			return Integer.compare(Math.abs(x), Math.abs(y));
		}
	});
```

- next_permutation은 직접 구현해줘야 함.

```
static boolean next_permutation(int[] arr) {
		int N = arr.length;
		int i = N-1;
		while(i>0&&arr[i-1]>=arr[i]) --i;

		if(i==0) return false;

		int j = N-1;
		while(arr[i-1]>=arr[j]) --j;

		int temp = arr[i-1];
		arr[i-1] = arr[j];
		arr[j] = temp;

		int k = N-1;
		while(i<k) {
			temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
			++i; --k;
		}
		return true;
	}
```

- String은 toCharArray, StringBuilder를 통해 특정 인덱스 값을 바꿀수 있는데, 왠만하면 StringBuilder 쓰는게 깔끔할 듯함.
- int to char -> char x = (char)(1+'0')
- Array.equals 을 통해 서로 다른 array 비교
- Arrays.copyof를 통해 array복사 가능, 대입연산자로 하면 주소값이 복사되니까 주의
- 자바에는 multi_set이 구현안돼있어서 기존c++에서 multi_set을 사용하여 푼 문제들 중 못푸는 문제들이 있음. TreeMap으로 multi_set을 구현가능하지만, 해당 TreeMap은 <Integer,Integer> 타입이기 때문에 이분탐색이 불가능함. - 보석도둑
- String의 reverse, append 등은 StringBuilder를 활용하고, subString은 String으로도 해결할 수있음. - A와B
- String의 마지막 인덱스의 값은 endsWith로 해결할 수 있음. - A와B
- 함수의 매개변수로 배열을 넘길 때, c++때와는 달리 주소가 넘어가기 때문에 모든 배열이 하나의 주소를 공유함. 따라서 문제가 발생할 수 있으므로, 최대한 String으로 넘기거나, clone배열을 넘겨줘야 함.
- char배열을 String으로 바꾸기 위해서는 .toString()이 아니라 new String(x)처럼 사용해줘야 함.
- Combination, Permutation은 재귀함수로 구현할 수 있는데, 부분집합은 구현하는데 좀 헷갈려서 컨벤션을 통일할 필요가 있음. - 괄호제거
- 2차원 배열은 clone 안통함. 무조건 2중 for문으로 하기.
- Collections.contains를 통해 객체가 들어있는지 확인하려면 클래스에 equals가 overriding되어 있어야 함. - 움직이는 미로탈출
- 함수 내에서 생성된 객체의 이름뿐 아니라, 객체의 주소값도 함수가 끝나면 제거됨. 따라서 함수내 주소값을 전역객체에 대입하는 것을 조심해야 함. - 캐슬디펜스
- Java에서 String을 매개변수로 넘겨서 조작할 때, str="a"처럼 한다면, 단순히 str이라는 변수값만 바꾸는 거라 내용값이 바뀌지 않음. str.replace()처럼 str이 가리키는 내용값을 직접 변경하는 것만 통함. 따라서 char[] 을 넘겨서 바꾸는 것은 내용값을 바꾸는거라 String과는 다르게 변경이 가능했음. 결과적으로 String을 매개변수로 넘겨 값을 변경하고 싶을때는 String을 넘기지 말고, StringBuilder로 넘겨주는게 훨씬 편함. - 전구와 스위치
- java에서 int[] 배열에는 기본적으로 0값이 들어가지만 Integer[]를 하면 null이 들어가기 때문에 0으로 추가적으로 초기화해주는 작업이 필요함.
