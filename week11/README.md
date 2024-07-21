### 우선순위 큐 (Priority Queue)
우선순위 큐는 각 요소가 **우선순위**를 가지며, **가장 높은 우선순위를 가진 요소가 가장 먼저 처리되는 큐**입니다. 일반적인 큐와 달리, 우선순위 큐는 삽입 순서가 아니라 우선순위에 따라 요소를 제거합니다.

#### 1. 개요
우선순위 큐는 다음과 같은 특징을 가지고 있습니다:
* 우선순위: 각 요소는 우선순위를 가지며, 큐에서 요소를 꺼낼 때 우선순위가 가장 높은 요소가 먼저 처리됩니다.
* 연산:
    * **삽입** (Insert): 큐에 새로운 요소를 추가합니다.
    * **삭제** (Extract): 우선순위가 가장 높은 요소를 제거하고 반환합니다.
    * **최상위** (Peek/Top): 우선순위가 가장 높은 요소를 반환하지만 제거하지 않습니다.

#### 2. 구현 방법
우선순위 큐는 주로 두 가지 방법으로 구현됩니다:
##### 2-1. 힙 (Heap) 기반 구현
* **최소 힙** (Min-Heap): 부모 노드가 자식 노드보다 작거나 같은 값을 가지는 완전 이진 트리입니다. 루트 노드는 최소값을 가지고 있습니다.
* **최대 힙** (Max-Heap): 부모 노드가 자식 노드보다 크거나 같은 값을 가지는 완전 이진 트리입니다. 루트 노드는 최대값을 가지고 있습니다.

힙 기반 우선순위 큐의 시간 복잡도:
* 삽입: $O(logN)$ 
* 삭제: $O(logN)$ 
* 최상위 조회: $O(1)$ 

##### 2-2. 정렬된 리스트 기반 구현
 * **정렬된 리스트**: 요소들이 우선순위에 따라 정렬된 리스트를 유지합니다. 삽입 시 위치를 찾아서 삽입하고, 삭제 시 리스트의 시작 부분에서 제거합니다.

정렬된 리스트 기반 우선순위 큐의 시간 복잡도:
* 삽입: $O(N)$ (리스트의 위치를 찾아야 하므로)
* 삭제: $O(1)$ (리스트의 시작 부분에서 제거하므로)
* 최상위 조회: $O(1)$ 

#### 3. C++에서의 우선순위 큐
C++에서는 표준 라이브러리의 `<queue>` 헤더에 있는 `priority_queue` 클래스를 사용하여 우선순위 큐를 구현할 수 있습니다.
```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // 기본적으로 최대 힙(Max-Heap)으로 동작
    priority_queue<int> maxHeap;
    
    // 원소 삽입
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(5);
    
    // 최상위 원소 출력 및 제거
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " "; // 최상위 원소 출력
        maxHeap.pop();                // 최상위 원소 제거
    }
    cout << endl;
    
    // 최소 힙(Min-Heap)으로 동작하도록 설정
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // 원소 삽입
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(5);
    
    // 최상위 원소 출력 및 제거
    while (!minHeap.empty()) {
        cout << minHeap.top() << " "; // 최상위 원소 출력
        minHeap.pop();                // 최상위 원소 제거
    }
    cout << endl;
    
    return 0;
}

```

#### 4. Java에서의 우선순위 

Java에서는 `PriorityQueue` 클래스를 사용하여 우선순위 큐를 구현할 수 있습니다.
```java
import java.util.PriorityQueue;
import java.util.Comparator;

public class PriorityQueueExample {
    public static void main(String[] args) {
        // 기본적으로 최소 힙(Min-Heap)으로 동작
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        
        // 원소 삽입
        minHeap.add(10);
        minHeap.add(20);
        minHeap.add(5);
        
        // 최상위 원소 출력 및 제거
        while (!minHeap.isEmpty()) {
            System.out.print(minHeap.poll() + " "); // 최상위 원소 출력 및 제거
        }
        System.out.println();
        
        // 최대 힙(Max-Heap)으로 동작하도록 설정
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        
        // 원소 삽입
        maxHeap.add(10);
        maxHeap.add(20);
        maxHeap.add(5);
        
        // 최상위 원소 출력 및 제거
        while (!maxHeap.isEmpty()) {
            System.out.print(maxHeap.poll() + " "); // 최상위 원소 출력 및 제거
        }
        System.out.println();
    }
}

```

#### 5. Python에서의 우선순위 큐
Python에서는 `heapq` 모듈을 사용하여 우선순위 큐를 구현할 수 있습니다. heapq는 최소 힙을 지원합니다.

```python
import heapq

def main():
    # 최소 힙(Min-Heap) 사용
    min_heap = []
    
    # 원소 삽입
    heapq.heappush(min_heap, 10)
    heapq.heappush(min_heap, 20)
    heapq.heappush(min_heap, 5)
    
    # 최상위 원소 출력 및 제거
    while min_heap:
        print(heapq.heappop(min_heap), end=" ")  # 최상위 원소 출력 및 제거
    print()
    
    # 최대 힙(Max-Heap) 구현 (값에 -1을 곱하여 구현)
    max_heap = []
    
    # 원소 삽입
    heapq.heappush(max_heap, -10)
    heapq.heappush(max_heap, -20)
    heapq.heappush(max_heap, -5)
    
    # 최상위 원소 출력 및 제거
    while max_heap:
        print(-heapq.heappop(max_heap), end=" ")  # 최상위 원소 출력 및 제거
    print()

if __name__ == "__main__":
    main()

```

#### 6. 결론
우선순위 큐는 **효율적인 데이터 처리**와 **알고리즘 설계**에서 중요한 역할을 합니다. 각 언어에서 제공하는 우선순위 큐 구현 방법은 성능과 사용 편의성 면에서 차이가 있지만, 기본적으로 **우선순위에 따라 데이터를 처리할 수 있는 강력한 도구**입니다.

* **C++** 의 `priority_queue`는 STL의 강력한 기능을 통해 힙 기반의 효율적인 우선순위 큐를 제공합니다. 최소 힙과 최대 힙 모두 지원하며, 복잡한 데이터 구조를 다루는 데 적합합니다.
* **Java** 의 `PriorityQueue`는 유연한 비교 기능을 제공하여 최소 힙과 최대 힙을 구현할 수 있습니다. 객체의 우선순위에 따라 정렬하여 다양한 문제를 해결하는 데 유용합니다.
* **Python** 의 `heapq`는 간단한 인터페이스를 제공하며, 최소 힙을 기본으로 지원하지만, 음수 값을 사용하여 최대 힙을 구현할 수도 있습니다.


우선순위 큐는 다익스트라 알고리즘, A* 알고리즘, 스케줄링 문제 등 다양한 알고리즘에서 핵심적인 역할을 하며, 복잡한 데이터 처리 문제를 해결하는 데 도움을 줍니다. 적절한 구현과 활용을 통해 효율적인 솔루션을 설계하고, 데이터 구조의 이해를 통해 더 나은 프로그램을 개발할 수 있습니다.
