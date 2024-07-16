#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

pii arr[1000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; string s;
        cin >> n >> s;
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            arr[i].first = -x, arr[i].second = y;
        }
        sort(arr, arr + n);
        priority_queue<pii> pq;
        int turn = (s == "Petra" ? 1 : 0), P = 0, J = 0;
        for (int i = 0; i < n; i++) {
            pq.push({ -arr[i].second, -arr[i].first });
            if (turn) {
                auto [x, y] = pq.top(); pq.pop();
                P += y;
            }
            turn ^= 1;
        }
        while (!pq.empty()) {
            auto [x, y] = pq.top(); pq.pop();
            J -= x;
        }
        cout << P << " " << J << '\n';
    }
}
