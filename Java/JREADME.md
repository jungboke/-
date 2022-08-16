## JAVA

### 기본
- 입력은 BufferedReader와 StringTokenizer를 활용하고,
출력은 StringBuilder를 사용하여 append해서 출력함.
- Stack은 Stack<Integer> 처럼 사용되며, top()이 peek()으로
명명됨.
- Queue는 offer, Set,List는 add, Map은 put, Stack은 push
- Queue와 Deque는 LinkedList<> 처럼 사용됨.
- Deque는 Queue의 C++ 활용과 비슷함.

````
q.offer();	// push
q.poll();	// pop
q.size();	// size
q.isEmpty();	// empty
q.peek();	// front
q.peekLast();	// back
````

- unordered_map은 HashMap이고, map은 TreeMap임.  
- 자바에서 map은 배열로 접근불가하고, get,put으로 접근함.
- map[x]+=1; 식의 방법을 적용하려면 put(x,map.get(x)+1) 처럼 접근함. 이는 동일 키값을 넣을 시, 최근 값이 적용되는 점을 이용한 것임.
그리고, c++과는 다르게 존재하지 않는 x에 대해 map[x]=0 으로 안나오고, null로 나오므로, null값 처리를 따로 해줘야함. getOrDefault를 통해 null일 때, 0으로 바꿔줄 수 있음. 또한 put의 반환값은 이전 value값이기 때문에 if(map1.put(~)==1) 을 통해 쉽게 value가 0이 되면 제거해줄 수 있음. - 이중우선순위큐
- 우선순위큐는 PriorityQueue<> 처럼 사용되며, 최대힙이 아닌 최소힙으로 적용됨. 따라서 PriorityQueue<>(Collections.reverseOrder())로 최대힙으로 변경해줄 수 있음. 내장함수명은 Queue와 같음.
- Set도 Map과 마찬가지로 HashSet과 TreeSet으로 나뉘는데, Hash는  unordered이고 Tree는 ordered임. Multiset은 Java STL에 없고, Guava라는 라이브러리를 사용해야 함. C++처럼 foreach문으로 순회가능함. Multiset은 구글 라이브러리를 따로 사용해야한다는 점에서 거의 안쓰이고, TreeMap을 주로 사용함.
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
<<<<<<< HEAD
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

- 
=======
- String은 toCharArray, StringBuilder를 통해 특정 인덱스 값을 바꿀수 있는데, 왠만하면 StringBuilder 쓰는게 깔끔할 듯함.
>>>>>>> 7085cbf0ceeb44e8a289c6c700ba7438ddf4fa33
