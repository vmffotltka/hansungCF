#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

pii dp[1000][501][2], arr[1000];

bool comp(pii a, pii b) {
    return (a.first == b.first ? a.second < b.second : a.first > b.first);
}

pii compare(pii a, pii b) {
    if (a.second == b.second) {
        return (a.first < b.first ? a : b);
    }
    else {
        return (a.second > b.second ? a : b);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        memset(dp, 0, sizeof(dp));
        string s; int n, sum = 0;
        cin >> n >> s;
        for (int i = 0; i < n; i++) {
            cin >> arr[i].first >> arr[i].second;
            sum += arr[i].first;
        }
        sort(arr, arr + n, comp);
        pii ans = { (s == "Petra" ? 0 : INT_MAX), 0 };
        for (int i = (s == "Petra" ? 1 : 0); i < n; i++) {
            int limit = (s == "Petra" ? (i + 1) / 2 : (i + 2) / 2);
            for (int j = 1; j <= limit; j++) {
                dp[i][j][0] = (i != 0 ? compare(dp[i - 1][j][0], dp[i - 1][j][1]) : pair<int, int>(0, 0));
                dp[i][j][1] = (i != 0 ? compare(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) : pair<int, int>(0, 0));
                dp[i][j][1].first += arr[i].first;
                dp[i][j][1].second += arr[i].second;

                ans = compare(ans, compare(dp[i][j][0], dp[i][j][1]));
            }
        }
        cout << sum - ans.first << " " << ans.second << '\n';
    }
}
