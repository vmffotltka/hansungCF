#include <bits/stdc++.h>
#define INF LLONG_MAX
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll N, M, K, ans = INF, DIST[21][10001];
vector<pll> edge[10001];

struct Edge {
    ll dist, next, wrapped;
    bool operator<(Edge other) const {
        return dist > other.dist;
    }
};

void dijk() {
    priority_queue<Edge> pq;
    pq.push({ 0, 1, 0 });
    while (!pq.empty()) {
        auto [nowDist, now, wrapped] = pq.top(); pq.pop();
        if (nowDist > DIST[wrapped][now]) continue;
        for (auto [nextDist, next] : edge[now]) {
            ll dist = nowDist + nextDist;
            if (dist < DIST[wrapped][next]) {
                if (next == N)
                    ans = min(ans, dist);
                DIST[wrapped][next] = dist;
                pq.push({ dist, next, wrapped });
            }
            if (wrapped + 1 > K) continue;
            if (nowDist < DIST[wrapped + 1][next]) {
                if (next == N)
                    ans = min(ans, nowDist);
                DIST[wrapped + 1][next] = nowDist;
                pq.push({ nowDist, next, wrapped + 1 });
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> K;
    for (int i = 0; i <= K; i++)
        for (int j = 1; j <= N; j++)
            DIST[i][j] = INF;
    DIST[0][1] = 0;
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        edge[u].push_back({ w, v });
        edge[v].push_back({ w, u });
    }
    dijk();
    cout << ans;
}
