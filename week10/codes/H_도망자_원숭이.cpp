#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int N, M, Q, DIST[501][501], monkey[501][501];
pair<int, int> arr[500];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            DIST[i][j] = INF;
        }
    }
    for (int i = 0; i < N; i++) {
        cin >> monkey[i + 1][i + 1];
        arr[i] = { monkey[i + 1][i + 1], i + 1 };
    }
    sort(arr, arr + N);
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        DIST[u][v] = min(DIST[u][v], w);
        DIST[v][u] = min(DIST[v][u], w);
        int m = max(monkey[u][u], monkey[v][v]);
        monkey[u][v] = m, monkey[v][u] = m;
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                int viaNode = arr[k - 1].second;
                if (DIST[i][viaNode] == INF || DIST[viaNode][j] == INF) continue;
                int way1 = DIST[i][j] + monkey[i][j];
                int way2 = DIST[i][viaNode] + DIST[viaNode][j] + max(monkey[i][viaNode], monkey[viaNode][j]);
                if (way1 > way2) {
                    DIST[i][j] = DIST[i][viaNode] + DIST[viaNode][j];
                    monkey[i][j] = max(monkey[i][viaNode], monkey[viaNode][j]);
                }
            }
        }
    }
    for (int i = 0; i < Q; i++) {
        int u, v; cin >> u >> v;
        cout << (DIST[u][v] == INF ? -1 : DIST[u][v] + monkey[u][v]) << '\n';
    }
}
