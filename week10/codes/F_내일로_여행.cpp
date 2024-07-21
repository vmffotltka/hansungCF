#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int N, R, M, K, DIST[101][101], discounted[101][101], DEST[200];
map<string, int> cityIndex;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> R;
    int idx = 1;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        if (!cityIndex[s])
            cityIndex[s] = idx++;
    }
    for (int i = 1; i < idx; i++) {
        for (int j = 1; j < idx; j++) {
            if (i == j) continue;
            DIST[i][j] = INF, discounted[i][j] = INF;
        }
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        string s; cin >> s;
        DEST[i] = cityIndex[s];
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        string vehicle, start, dest; int cost;
        cin >> vehicle >> start >> dest >> cost;
        int u = cityIndex[start], v = cityIndex[dest];
        if (vehicle == "Mugunghwa" || vehicle == "ITX-Saemaeul" || vehicle == "ITX-Cheongchun")
            discounted[u][v] = 0, discounted[v][u] = 0;
        else if (vehicle == "S-Train" || vehicle == "V-Train") {
            discounted[u][v] = min(discounted[u][v], cost);
            discounted[v][u] = min(discounted[v][u], cost);
        }
        else {
            discounted[u][v] = min(discounted[u][v], cost * 2);
            discounted[v][u] = min(discounted[v][u], cost * 2);
        }
        DIST[u][v] = min(DIST[u][v], cost * 2);
        DIST[v][u] = min(DIST[v][u], cost * 2);
    }
    for (int k = 1; k < idx; k++) {
        for (int i = 1; i < idx; i++) {
            for (int j = 1; j < idx; j++) {
                if (DIST[i][k] == INF || DIST[k][j] == INF) continue;
                DIST[i][j] = min(DIST[i][j], DIST[i][k] + DIST[k][j]);
                discounted[i][j] = min(discounted[i][j], discounted[i][k] + discounted[k][j]);
            }
        }
    }
    int noTicket = 0, buyTicket = R * 2;
    for (int i = 0; i < M; i++) {
        int u = DEST[i], v = DEST[(i + 1) % M];
        noTicket += DIST[u][v];
        buyTicket += discounted[u][v];
    }
    cout << (noTicket > buyTicket ? "Yes" : "No");
}
