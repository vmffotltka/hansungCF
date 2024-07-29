#include <bits/stdc++.h>
using namespace std;

int N, M, ans[100000];
priority_queue<int> pq[200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int sushi; cin >> sushi;
            pq[sushi].push(-i);
        }
    }
    for (int i = 0; i < M; i++) {
        int sushi; cin >> sushi;
        if (!pq[sushi].empty()) {
            ans[-pq[sushi].top()]++;
            pq[sushi].pop();
        }
    }
    for (int i = 0; i < N; i++)
        cout << ans[i] << " ";
}
