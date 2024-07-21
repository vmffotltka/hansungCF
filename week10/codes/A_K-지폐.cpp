#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, M, K, S, T, DIST[51][10001];
vector<pii> edge[10001];

void dijkstra() {
    priority_queue<pii> pq;
    pq.push({ 0, S });
    while (!pq.empty()) {
        auto [dist, now] = pq.top(); pq.pop();
        for (auto [next, w] : edge[now]) {
            int d = w - dist;
            if (!DIST[d % K][next] || DIST[d % K][next] > d) {
                DIST[d % K][next] = d;
                pq.push({ -d, next });
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> K >> S >> T;
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        edge[u].push_back({ v, w });
    }
    dijkstra();
    if (DIST[0][T])
        cout << DIST[0][T];
    else
        cout << "IMPOSSIBLE";
}
