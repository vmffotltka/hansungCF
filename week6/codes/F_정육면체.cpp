#include <bits/stdc++.h>
using namespace std;

long long dp[201][201][201];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 1; i <= 200; i++) {
        dp[i][i][i] = 1;
        for (int j = i; j <= 200; j++) {
            for (int k = 2; k <= 200; k++) {
                long long mn = (dp[i][j][k] ? dp[i][j][k] : INT_MAX);
                for (int p = 1; p * 2 <= k; p++)
                    mn = min(mn, dp[i][j][p] + dp[i][j][k - p]);
                for (int p = 1; p * 2 <= j; p++)
                    mn = min(mn, dp[i][p][k] + dp[i][j - p][k]);
                for (int p = 1; p * 2 <= i; p++)
                    mn = min(mn, dp[p][j][k] + dp[i - p][j][k]);
                dp[i][j][k] = (dp[i][j][k] ? min(dp[i][j][k], mn) : mn);
                dp[i][k][j] = (dp[i][k][j] ? min(dp[i][k][j], mn) : mn);
                dp[j][i][k] = (dp[j][i][k] ? min(dp[j][i][k], mn) : mn);
                dp[j][k][i] = (dp[j][k][i] ? min(dp[j][k][i], mn) : mn);
                dp[k][i][j] = (dp[k][i][j] ? min(dp[k][i][j], mn) : mn);
                dp[k][j][i] = (dp[k][j][i] ? min(dp[k][j][i], mn) : mn);
            }
        }
    }
    int t; cin >> t; while (t--) {
        int garo, sero, height;
        cin >> garo >> sero >> height;
        cout << dp[height][garo][sero] << '\n';
    }
}
