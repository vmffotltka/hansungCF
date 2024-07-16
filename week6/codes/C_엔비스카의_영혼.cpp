#include <bits/stdc++.h>
using namespace std;

long long N, A, B, dp[1000001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> A >> B;
    for (int i = 1; i <= N; i++) {
        dp[i] = min(LLONG_MAX, dp[i - 1]);
        if (i - A - 1 >= 0)
            dp[i] = min(dp[i], dp[i - A - 1]);
        if (i - B - 1 >= 0)
            dp[i] = min(dp[i], dp[i - B - 1]);
        dp[i]++;
    }
    cout << dp[N];
}
