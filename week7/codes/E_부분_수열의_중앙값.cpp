#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, B, pos[100001], neg[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> B;
    ll big = 0, small = 0, ans = 0;
    bool tri = false;
    for (int i = 0; i < N; i++) {
        ll p; cin >> p;
        if (p == B) tri = true;
        else (p < B ? small++ : big++);
        int dif = big - small;
        if (tri) {
            if (!dif) ans++;
            ans += (dif < 0 ? neg[-dif] : pos[dif]);
        }
        if (!tri) (dif < 0 ? neg[-dif]++ : pos[dif]++);
    }
    cout << ans;
}
