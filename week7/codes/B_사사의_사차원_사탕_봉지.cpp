#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M, sum[300000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> sum[i];
        if (!i) continue;
        sum[i] += sum[i - 1];
    }
    while (N--) {
        ll p; cin >> p;
        int idx = lower_bound(sum, sum + M, p) - sum + 1;
        if (idx == M + 1) cout << "Go away!\n";
        else cout << idx << '\n';
    }
}
