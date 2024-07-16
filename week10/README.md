### 다익스트라 알고리즘 & 플로이드 워셜
그래프 이론에서 **최단 경로**를 찾는 문제는 매우 중요합니다. 다익스트라 알고리즘과 플로이드 워셜 알고리즘은 이러한 문제를 해결하는 대표적인 알고리즘입니다.



***



#### 1. 다익스트라 알고리즘
##### 개요
다익스트라 알고리즘은 그래프에서 **한 노드에서 다른 모든 노드까지의 최단 경로를 찾는 알고리즘**입니다. 음의 가중치를 허용하지 않습니다.
##### 동작 과정
1. 시작 노드를 설정합니다.
2. 시작 노드에서 다른 노드까지의 거리를 **무한대로 초기화**합니다. 시작 노드의 거리는 0으로 설정합니다.
3. 방문하지 않은 노드 중에서 **최단 거리를 가진 노드를 선택**합니다.
4. 해당 노드를 거쳐 다른 노드로 가는 비용을 계산하고, 현재 알려진 **최단 거리보다 작으면 갱**신합니다.
5. 모든 노드를 방문할 때까지 3-4 단계를 반복합니다.

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(const vector<vector<pair<int, int>>> &graph, int start) {
    vector<int> distance(graph.size(), INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    distance[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (dist > distance[node]) continue;
        
        for (auto &edge : graph[node]) {
            int next_node = edge.first;
            int next_dist = dist + edge.second;
            
            if (next_dist < distance[next_node]) {
                distance[next_node] = next_dist;
                pq.push({next_dist, next_node});
            }
        }
    }
    
    for (int i = 0; i < distance.size(); ++i) {
        if (distance[i] == INF) cout << "INF ";
        else cout << distance[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<pair<int, int>>> graph = {
        {{1, 10}, {2, 3}},
        {{2, 1}, {3, 2}},
        {{1, 4}, {3, 8}, {4, 2}},
        {{4, 7}},
        {{3, 9}}
    };
    
    dijkstra(graph, 0);
    return 0;
}
```




***




#### 2. 플로이드 워셜 알고리즘
##### 개요
플로이드 워셜 알고리즘은 그래프에서 **모든 노드 쌍 간의 최단 경로를 찾는 알고리즘**입니다. 음의 가중치를 허용하지만, 음의 사이클은 허용하지 않습니다.
##### 동작 과정
1. 그래프의 인접 행렬을 초기화합니다.
2. 모든 노드 쌍 (i, j)에 대해 중간 노드 k를 거쳐가는 경로를 고려하여 최단 경로를 갱신합니다.
3. k를 1부터 n까지 반복하여 모든 노드 쌍에 대해 최단 경로를 계산합니다.

```cpp
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void floyd_warshall(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<vector<int>> dist = graph;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 3, INF, INF},
        {2, 0, INF, 5},
        {INF, 1, 0, INF},
        {INF, INF, 2, 0}
    };

    floyd_warshall(graph);
    return 0;
}

```




***




#### 3. 다익스트라 vs 플로이드 워셜
##### 다익스트라 알고리즘
* 장점: **한 출발점에서 다른 모든 노드까지의 최단 경로**를 효율적으로 계산합니다.
* 단점: **음의 가중치가 있는 그래프에서는 사용할 수 없습니다**.
* 시간 복잡도: $O((V + E) log V)$ , V는 노드의 수, E는 간선의 수

##### 플로이드 워셜 알고리즘
* 장점: **모든 노드 쌍 간의 최단 경로를 계산**할 수 있습니다.
* 단점: **시간 복잡도가 높아** 노드 수가 많은 그래프에서는 비효율적입니다.
* 시간 복잡도: $O(V^3)$ , V는 노드의 수




***




#### 4. 응용

##### 다익스트라 알고리즘의 응용
* GPS 네비게이션 시스템에서 최단 경로 찾기
* 네트워크 라우팅 프로토콜

##### 플로이드 워셜 알고리즘의 응용
* 모든 노드 쌍 간의 최단 경로가 필요한 문제
* 그래프의 트랜스 클로저(Transitive Closure) 계산

#### 5. 결론
다익스트라 알고리즘과 플로이드 워셜 알고리즘은 그래프 이론에서 중요한 역할을 합니다. 각각의 알고리즘은 특성과 용도가 다르므로, 문제의 성격에 따라 적절한 알고리즘을 선택하여 사용해야 합니다. 다익스트라 알고리즘은 한 출발점에서 다른 모든 노드까지의 최단 경로를 찾는 데 유용하며, 플로이드 워셜 알고리즘은 모든 노드 쌍 간의 최단 경로를 계산하는 데 유용합니다. 이를 통해 다양한 그래프 문제를 효율적으로 해결할 수 있습니다.
