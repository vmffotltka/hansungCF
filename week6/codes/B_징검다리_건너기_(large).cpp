#include <bits/stdc++.h>
using namespace std;

long long N, arr[5000], dp[5000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = 1; i < N; i++) {
        dp[i] = INT_MAX;
        for (int j = i - 1; j >= 0; j--) {
            long long dist = (i - j) * (1 + abs(arr[i] - arr[j]));
            dp[i] = min(dp[i], max(dp[j], dist));
        }
    }
    cout << dp[N - 1];
}
