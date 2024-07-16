#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, Q, A[200000], sum[200000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll next1 = (i + 1) % N, next2 = (i + 2) % N, next3 = (i + 3) % N;
        sum[i] = A[i] * A[next1] * A[next2] * A[next3];
        ans += sum[i];
    }
    for (int i = 0; i < Q; i++) {
        int q; cin >> q;
        q--;
        sum[(N + q - 3) % N] *= -1;
        sum[(N + q - 2) % N] *= -1;
        sum[(N + q - 1) % N] *= -1;
        sum[q] *= -1;
        ans += sum[(N + q - 3) % N] * 2;
        ans += sum[(N + q - 2) % N] * 2;
        ans += sum[(N + q - 1) % N] * 2;
        ans += sum[q] * 2;
        cout << ans << '\n';
    }
}
