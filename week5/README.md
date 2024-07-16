# DFS와 BFS

    DFS(깊이 우선 탐색)와 BFS(너비 우선 탐색)는 그래프 탐색 알고리즘으로, 그래프 또는 트리 구조를 탐색하는 데 사용됩니다. 이 두 알고리즘은 문제 해결에 자주 사용되며, 각각의 특성과 용도에 따라 선택됩니다.



***


## 1. DFS(Depth-First Search)

### 1-1. 개념

DFS는 그래프의 모든 정점을 탐색할 때 **가능한 한 깊이 들어가서 탐색**을 진행한 후, 더 이상 갈 수 없게 되면 가장 마지막에 만났던 갈림길로 되돌아가서 다른 방향으로 탐색을 진행합니다. 이 과정은 **재귀적**으로 또는 **스택**을 이용하여 구현할 수 있습니다.

### 1-2. 작동 방식

1. 시작 정점을 스택에 추가합니다.
2. 스택에서 정점을 하나 꺼내 방문합니다.
3. 방문한 정점의 인접 정점들을 스택에 추가합니다.
4. 스택이 빌 때까지 2번과 3번을 반복합니다.

### 1-3. Python 예제 코드

```python
def dfs(graph, start):
    visited = set()
    stack = [start]

    while stack:
        vertex = stack.pop()
        if vertex not in visited:
            visited.add(vertex)
            stack.extend(set(graph[vertex]) - visited)

    return visited
```


***


## 2. BFS(Breadth-First Search)

### 2-1. 개념

BFS는 그래프의 모든 정점을 탐색할 때 **현재 정점의 모든 인접 정점을 먼저 탐색**한 후, 다음 정점으로 넘어가는 방식으로 진행됩니다. 이 과정은 **큐**를 이용하여 구현할 수 있습니다.

### 2-2. 작동 방식

1. 시작 정점을 큐에 추가합니다.
2. 큐에서 정점을 하나 꺼내 방문합니다.
3. 방문한 정점의 인접 정점들을 큐에 추가합니다.
4. 큐가 빌 때까지 2번과 3번을 반복합니다.

### 2-3. Python 예제 코드

```python
def bfs(graph, start):
    visited = set()
    queue = [start]

    while queue:
        vertex = queue.pop(0)
        if vertex not in visited:
            visited.add(vertex)
            queue.extend(set(graph[vertex]) - visited)

    return visited
```


***

## 3. DFS vs BFS


| 특성 | DFS | BFS |
| --- | --- | --- |
| 자료구조 | 스택(재귀 또는 명시적 스택 사용) | 큐 |
| 용도 | 경로 탐색, 사이클 탐지, 백트래킹 문제 | 최단 경로 탐색, 레벨별 탐색 |
| 시간복잡도 | $O(V+E)$ | $O(V+E)$ |
| 공간복잡도 | $O(V)$ | $O(V)$ |


***

## 4. 마무리 하며

DFS와 BFS는 다양한 문제를 해결하는 데 매우 유용한 알고리즘입니다. 각 알고리즘의 특성과 용도를 잘 이해하고 적절히 사용하면 더 효율적인 문제 해결이 가능합니다.

이번 주 시험은 잘 보셨나요? 한 학기 동안 고생 많으셨습니다. 쉬어가는 느낌으로 기분 좋게 문제 풀어보고 다음 주에 만납시다!!
