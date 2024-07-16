#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M, K, X, sum[100002];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> K >> X;
    for (int i = 2; i <= N + 1; i++) {
        ll p; cin >> p;
        X += p;
        sum[i] = sum[i - 1];
        if (X < K) 
            sum[i]++;
    }
    while (M--) {
        int l, r; cin >> l >> r;
        cout << sum[r] - sum[l] << '\n';
    }
}
