#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int len, cost, dest;
    bool operator<(Edge const& other) const {
        return len > other.len;
    }
};

int K, N, R, ans = INT_MAX, DIST[10001][101];
vector<Edge> edge[101];

void dijk() {
    priority_queue<Edge> pq;
    pq.push({ 0, 0, 1 });
    while (!pq.empty()) {
        auto [nowLen, nowCost, now] = pq.top(); pq.pop();
        for (auto [nextLen, nextCost, next] : edge[now]) {
            int len = nextLen + nowLen, cost = nowCost + nextCost;
            if (cost > K) continue;
            if (!DIST[cost][next] || DIST[cost][next] > len) {
                if (next == N)
                    ans = min(ans, len);
                DIST[cost][next] = len;
                pq.push({ len, cost, next });
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> K >> N >> R;
    for (int i = 0; i < R; i++) {
        int u, v, l, w; cin >> u >> v >> l >> w;
        edge[u].push_back({ l, w, v });
    }
    dijk();
    cout << (ans == INT_MAX ? -1 : ans);
}
