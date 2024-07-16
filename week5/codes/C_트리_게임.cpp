#include <bits/stdc++.h>
using namespace std;

int N, S, E, dist[100001], parent[100001];
vector<int> edge[100001];

void bfs() {
    deque<int> dq, tmp;
    dq.push_back(S);
    dist[S] = 0;
    int d = 1;
    while (!dq.empty()) {
        int cur = dq.front(); dq.pop_front();
        for (auto next : edge[cur]) {
            if (dist[next] != -1) continue;
            dist[next] = d;
            tmp.push_back(next);
            parent[next] = cur;
        }
        if (dq.empty()) {
            swap(dq, tmp);
            d++;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> S >> E;
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    bfs();
    int cur = parent[E];
    while (true) {
        if (dist[cur] & 1) {
            int child = (parent[cur] ? edge[cur].size() - 1 : edge[cur].size());
            if (child != 1) {
                cout << "Second";
                return 0;
            }
        }
        if (!parent[cur]) break;
        cur = parent[cur];
    }
    cout << "First";
}
