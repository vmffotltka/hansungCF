#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int N, M, Q, dist[101][101][101];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (k == j) continue;
                dist[i][j][k] = INF;
            }
        }
    }
    for (int i = 0; i < M; i++) {
        int b, t, c; cin >> b >> t >> c;
        for (int j = 1; j <= N; j++)
            dist[j][b][t] = c;
    }
    for (int except = 1; except <= N; except++) {
        for (int k = 1; k <= N; k++) {
            if (k == except) continue;
            for (int i = 1; i <= N; i++) {
                if (i == except) continue;
                for (int j = 1; j <= N; j++) {
                    if (j == except || dist[except][i][k] == INF || dist[except][k][j] == INF)
                        continue;
                    dist[except][i][j] = min(dist[except][i][j], dist[except][i][k] + dist[except][k][j]);
                }
            }
        }
    }
    for (int i = 0; i < Q; i++) {
        int s, k, e; cin >> s >> k >> e;
        if (dist[k][s][e] == INF) cout << "No\n";
        else cout << dist[k][s][e] << '\n';
    }
}
