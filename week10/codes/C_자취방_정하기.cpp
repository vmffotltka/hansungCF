#include <bits/stdc++.h>
#define INF LLONG_MAX
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll N, M, T;
vector<pll> edge[200001];
bool vis[200001];
ll DIST[200001];

bool bfs(int start) {
    deque<int> dq;
    dq.push_back(start);
    vis[start] = true;
    bool ret = false;
    while (!dq.empty()) {
        int now = dq.front(); dq.pop_front();
        for (auto [next, nextDist] : edge[now]) {
            if (nextDist < 0) {
                ret = true; // 음수 간선 발견
            }
            if (!vis[next]) {
                vis[next] = true;
                dq.push_back(next);
            }
        }
    }
    return ret;
}

void dijkstra(int start) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({ 0, start });
    DIST[start] = 0;
    while (!pq.empty()) {
        auto [nowDist, now] = pq.top(); pq.pop();
        if (DIST[now] < nowDist)
            continue;
        for (auto [next, nextDist] : edge[now]) {
            ll dist = nowDist + nextDist;
            if (DIST[next] > dist) {
                DIST[next] = dist;
                pq.push({ dist, next });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (ll i = 0; i < M; i++) {
        ll u, v, a, b;
        cin >> u >> v >> a >> b;
        ll w = a + b;
        edge[u].push_back({ v, w });
        edge[v].push_back({ u, w });
    }
    cin >> T;

    bool hasNegativeEdge = bfs(1);
    vector<ll> result;

    if (hasNegativeEdge) {
        for (ll i = 2; i <= N; i++) {
            if (vis[i]) result.push_back(i);
        }
    }
    else {
        fill(DIST, DIST + N + 1, INF);
        dijkstra(1);
        for (ll i = 2; i <= N; i++) {
            if (DIST[i] <= T * 2) result.push_back(i);
        }
    }

    cout << result.size() << '\n';
    for (auto& r : result) cout << r << ' ';
}
