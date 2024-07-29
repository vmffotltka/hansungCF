#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (!a) {
            if (!pq.empty()) {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else
                cout << "-1\n";
        }
        else {
            for (int i = 0; i < a; i++) {
                int p; cin >> p;
                pq.push(p);
            }
        }
    }
}
