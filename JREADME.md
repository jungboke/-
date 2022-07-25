## JAVA

### 기본
- 입력은 BufferedReader와 StringTokenizer를 활용하고,
출력은 StringBuilder를 사용하여 append해서 출력함.
- Stack은 Stack<Integer> 처럼 사용되며, top()이 peek()으로
명명됨.
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
그리고, c++과는 다르게 존재하지 않는 x에 대해 map[x]=0 으로 안나오고, null로 나오므로, null값 처리를 따로 해줘야함. getOrDefault를 통해 null일 때, 0으로 바꿔줄 수 있음. 또한 put의 반환값은 이전 value값이기 때문에 if(map1.put(~)==1) 을 통해 쉽게 value가 0이 되면 제거해줄 수 있음.
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

### 자료구조
- 