#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M, K, sat = 0; cin >> N >> M >> K;
    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        int importance; cin >> importance;
        pq.push(importance);
    }
    vector<int> log;
    while (!pq.empty()) {
        int now = pq.top(); pq.pop();
        sat = sat / 2 + now;
        if (now - M > K)
            pq.push(now - M);
        log.push_back(sat);
    }
    cout << log.size() << '\n';
    for (auto i : log)
        cout << i << '\n';
}
