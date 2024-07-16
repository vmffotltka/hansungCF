#include <bits/stdc++.h>
using namespace std;

long long N, K, Q, arr[100000], dp[100000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K >> Q;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    long long cnt = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == K) cnt = 0;
        else cnt++;
        dp[i] = (!i ? cnt : dp[i - 1] + cnt);
    }
    for (int i = 0; i < Q; i++) {
        long long p; cin >> p;
        cout << dp[p - 1] << '\n';
    }
}
