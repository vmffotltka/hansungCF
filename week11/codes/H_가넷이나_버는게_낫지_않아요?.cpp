#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

struct Edge {
    ll next, time, garnet;
    bool operator<(Edge other) const {
        return (other.time == time ? other.garnet < garnet : other.time < time);
    }
};

ll N, M;
vector<vector<pll>> Dist;
vector<vector<Edge>> edge;

void dijk() {
    priority_queue<Edge> pq;
    pq.push({ 1, 0, 0 });
    Dist[1][0] = { 0, 0 };
    while (!pq.empty()) {
        auto [now, time, garnet] = pq.top(); pq.pop();
        if (Dist[now][1].first < time || (Dist[now][1].first == time && Dist[now][1].second > garnet)) continue;
        for (auto [next, nextTime, nextGarnet] : edge[now]) {
            ll dist = time + nextTime, g = garnet + nextGarnet;
            if ((Dist[next][0].first > dist) || (Dist[next][0].first == dist && Dist[next][0].second > g)) {
                if (Dist[next][0].first < LLONG_MAX) {
                    Dist[next][1] = Dist[next][0];
                }
                Dist[next][0] = { dist, g };
                pq.push({ next, dist, g });
            }
            else if ((Dist[next][0].first == dist && Dist[next][0].second < g) || (Dist[next][1].first > dist) || (Dist[next][1].first == dist && Dist[next][1].second < g)) {
                Dist[next][1] = { dist, g };
                pq.push({ next, dist, g });
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> N >> M;
        edge.assign(N + 1, vector<Edge>());
        Dist.assign(N + 1, vector<pll>(2, { LLONG_MAX, LLONG_MAX }));
        for (int i = 0; i < M; i++) {
            ll u, v, t, g; cin >> u >> v >> t >> g;
            edge[u].push_back({ v, t, g });
            edge[v].push_back({ u, t, g });
        }
        dijk();
        cout << "Game #" << i << ": Suckzoo ends game in time " << Dist[N][1].first << ", earning " << Dist[N][1].second << " garnet(s).\n";
    }
}
