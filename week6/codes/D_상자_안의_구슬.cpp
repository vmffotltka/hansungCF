#include <bits/stdc++.h>
using namespace std;

int N, A, B, score[1001][1001], dp[1001][1001];
int boxA[1001], boxB[1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> A >> B;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> score[i][j];
        }
    }
    for (int i = 1; i <= A; i++)
        cin >> boxA[i];
    for (int i = 1; i <= B; i++)
        cin >> boxB[i];
    int ans = -INT_MAX, y = 0, x = 0;
    for (int i = 1; i <= A; i++) {
        for (int j = 1; j <= B; j++) {
            dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + score[boxA[i]][boxB[j]]);
            if (ans < dp[i][j]) {
                ans = dp[i][j];
                y = i, x = j;
            }
        }
    }
    cout << ans << '\n';
    vector<int> tmp;
    for (int i = y; i < A; i++)
        tmp.push_back(1);
    for (int i = x; i < B; i++)
        tmp.push_back(2);
    while (true) {
        if (y > 0 && x > 0 && dp[y - 1][x - 1] + score[boxA[y]][boxB[x]] == ans) {
            tmp.push_back(3);
            y--, x--;
        }
        else if (y > 0 && dp[y - 1][x] == ans) {
            tmp.push_back(1);
            y--;
        }
        else if (x > 0 && dp[y][x - 1] == ans) {
            tmp.push_back(2);
            x--;
        }
        ans = dp[y][x];
        if (!y && !x) break;
    }
    for (int i = tmp.size() - 1; i >= 0; i--)
        cout << tmp[i] << " ";
}
