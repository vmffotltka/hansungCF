## 1. 스택(Stack)



#### 1-1. 스택의 개념



스택은 **후입선출(LIFO, Last In First Out)** 의 원칙에 따라 데이터를 저장하고 접근하는 선형 자료구조입니다. 이 구조는 데이터를 넣는(push) 연산과 데이터를 빼내는(pop) 연산으로 이루어져 있습니다.


#### 1-2. 스택의 구현



* Python : 리스트를 사용한 스택 구현

```python
stack = []
stack.append(item)  # push 연산
popped_item = stack.pop()  # pop 연산
```

* C++ : <stack> 표준 라이브러리의 stack 컨테이너를 사용한 스택 구현

```cpp
#include <stack>
std::stack<int> stack;
stack.push(item);  // push 연산
int popped_item = stack.top(); stack.pop();  // pop 연산
```

* Java : 자바의 Stack 클래스를 사용한 스택 구현

```java
import java.util.Stack;
Stack<Integer> stack = new Stack<>();
stack.push(item);  // push 연산
int poppedItem = stack.pop();  // pop 연산
```



#### 1-3. 스택의 활용


    
            재귀 함수 호출, 후위 표기법 계산, 웹 브라우저 방문 기록...



***
## 2. 큐(Queue)


#### 2-1. 큐의 개념

큐는 **선입선출(FIFO, First In First Out)** 의 원칙에 따라 데이터를 저장하고 접근하는 선형 자료구조입니다. 큐는 데이터를 추가하는 enqueue 연산과 데이터를 제거하는 dequeue 연산으로 이루어져 있습니다.

#### 2-2. 큐의 구현

* Python : collections 모듈의 deque 클래스를 사용한 큐 구현

```python
from collections import deque
queue = deque()
queue.append(item)  # enqueue 연산
dequeued_item = queue.popleft()  # dequeue 연산
```

* C++ : <queue> 표준 라이브러리의 queue 컨테이너를 사용한 큐 구현

```cpp
#include <queue>
std::queue<int> queue;
queue.push(item);  // enqueue 연산
int dequeued_item = queue.front(); queue.pop();  // dequeue 연산
```

* Java : 자바의 Queue 인터페이스를 구현한 LinkedList 클래스를 사용한 큐 구현

```java
import java.util.LinkedList;
import java.util.Queue;
Queue<Integer> queue = new LinkedList<>();
queue.add(item);  // enqueue 연산
int dequeuedItem = queue.poll();  // dequeue 연산
```

#### 2-3. 큐의 활용

            운영체제의 프로세스 스케줄링, 너비 우선 탐색...




***


## 3. 덱(Deque)

#### 3-1. 덱의 개념

덱은 **양쪽 끝에서 삽입과 삭제가 모두 가능한 자료구조**로, **Double-ended Queue** 의 줄임말입니다. 덱은 스택과 큐의 특징을 모두 가지고 있어서 다양한 상황에서 유용하게 활용될 수 있습니다.

#### 3-2. 덱의 구현

* Python : collections 모듈의 deque 클래스를 사용한 덱 구현

```python
from collections import deque
deque = deque()
deque.appendleft(item)  # 앞에 삽입
deque.append(item)  # 뒤에 삽입
dequeued_front_item = deque.popleft()  # 앞에서 제거
dequeued_back_item = deque.pop()  # 뒤에서 제거
```

* C++ : <deque> 표준 라이브러리의 deque 컨테이너를 사용한 덱 구현

```cpp
#include <deque>
std::deque<int> deque;
deque.push_front(item);  // 앞에 삽입
deque.push_back(item);  // 뒤에 삽입
int dequeued_front_item = deque.front(); deque.pop_front();  // 앞에서 제거
int dequeued_back_item = deque.back(); deque.pop_back();  // 뒤에서 제거
```

* Java : 자바의 Deque 인터페이스를 구현한 LinkedList 클래스를 사용한 덱 구현
```java
import java.util.LinkedList;
import java.util.Deque;
Deque<Integer> deque = new LinkedList<>();
deque.addFirst(item);  // 앞에 삽입
deque.addLast(item);  // 뒤에 삽입
int dequeuedFrontItem = deque.removeFirst();  // 앞에서 제거
int dequeuedBackItem = deque.removeLast();  // 뒤에서 제거
```

#### 3-3. 덱의 활용

            슬라이딩 윈도우 기법, 이중 우선순위 큐...
    


***


### 4. 마무리하며

스택, 큐, 덱 자료구조는 비단 PS분야, 코딩테스트에 나오는 것만이 아닌 전체적인 컴퓨터 구조의 기반이 되고 있습니다. 문제를 보고 어떤 자료구조를 사용해야 할지 잘 결정하고 응용하는 실력을 길러봅시다!

시험 기간이 얼마 남지 않았는데 남은 기간도 화이팅 합시다!!
