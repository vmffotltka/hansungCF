#include <bits/stdc++.h>
using namespace std;

int T, N, Time[1000000];

struct Process {
    int priority, id;
    bool operator<(Process other) const {
        return (priority == other.priority ? id > other.id : priority < other.priority);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> T >> N;
    priority_queue<Process> pq;
    for (int i = 0; i < N; i++) {
        int id, t, p; cin >> id >> t >> p;
        Time[id] = t;
        pq.push({ p, id });
    }
    for (int i = 0; i < T; i++) {
        auto [priority, id] = pq.top(); pq.pop();
        cout << id << '\n';
        if (!--Time[id]) continue;
        pq.push({ priority - 1, id });
    }
}
