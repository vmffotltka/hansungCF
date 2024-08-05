#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, arr[9][9];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];
    ll ans = -LLONG_MAX;
    for (ll bit = 0; bit < (1LL << N); bit++) {
        vector<bool> minu(N);
        ll score = 0;
        for (ll i = 0; i < N; i++) {
            if ((1LL << i) & bit) {
                minu[i] = true;
                for (int j = 0; j < N; j++) {
                    score += arr[i][j];
                }
            }
        }
        for (ll j = 0; j < N; j++) {
            ll mi = 0, jo = 0;
            for (ll i = 0; i < N; i++) {
                if (minu[i])
                    jo += arr[i][j];
                else
                    mi += arr[i][j];
            }
            if (jo > mi)
                score += mi - jo;
        }
        ans = max(ans, score);
    }
    cout << ans;
}
