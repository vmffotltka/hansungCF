#include <bits/stdc++.h>
using namespace std;

int N, M, inDegree[1001];
vector<int> edge[1001];
long long dp[1001][2];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        edge[u].push_back(v);
        inDegree[v]++;
    }
    if (N == 1) {
        cout << 1; return 0;
    }
    deque<int> dq;
    dq.push_back(1);
    dp[1][0] = -1;
    while (!dq.empty()) {
        int cur = dq.front(); dq.pop_front();
        dp[cur][0]++;
        if (cur == N) break;
        bool tri = true;
        for (auto next : edge[cur]) {
            if (!--inDegree[next])
                dq.push_back(next);
            if (tri && next != N) {
                tri = false;
                dp[next][0] += dp[cur][0];
                dp[next][1] += dp[cur][1];
            }
            dp[next][1] += dp[cur][0];
            dp[next][0] += dp[cur][1];
        }
    }
    cout << dp[N][1] - dp[N][0];
}
