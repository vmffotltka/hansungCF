#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll dp[1001][1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i <= 1000; i++) dp[1][i] = 1;
    for (int i = 2; i <= 1000; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= 1000; j++) {
            dp[i][j] = dp[i][j - 1];
            ll sum1 = (j - i - 1 < 0 ? 0 : dp[i - 1][j - i - 1]), sum2 = dp[i - 1][j];
            dp[i][j] = (((dp[i][j] + sum2) % MOD) + MOD - sum1) % MOD;
        }
    }
    int t; cin >> t;
    while (t--) {
        int n, a, b; cin >> n >> a >> b;
        ll sum1 = dp[n][b], sum2 = (a ? dp[n][a - 1] : 0LL);
        cout << (MOD + sum1 - sum2) % MOD << '\n';
    }
}
