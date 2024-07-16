#include <bits/stdc++.h>
#define MOD 10301
using namespace std;

int N, A, B, dp1[501][1000], dp2[501][1000];
int sum1[1000], sum2[1000], ans = 1;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> A >> B;
    dp1[A][A - 1] = 1;
    for (int j = A - 1; j < N - B; j++) {
        for (int i = A; i <= N / 2; i++) {
            if (!dp1[i][j]) continue;
            int y = i, x = j + i;
            while (x < N - B) {
                dp1[y][x] = (dp1[y][x] + dp1[i][j]) % MOD;
                sum1[x] = (sum1[x] + dp1[i][j]) % MOD;
                ans = (ans + dp1[i][j]) % MOD;
                y++;
                x += 2;
            }
        }
    }
    dp2[B][N - B] = 1;
    for (int j = N - B; j >= A; j--) {
        for (int i = B; i <= N / 2; i++) {
            if (!dp2[i][j]) continue;
            int y = i, x = j - i;
            while (x >= A) {
                dp2[y][x] = (dp2[y][x] + dp2[i][j]) % MOD;
                sum2[x] = (sum2[x] + dp2[i][j]) % MOD;
                ans = (ans + dp2[i][j]) % MOD;
                y++;
                x -= 2;
            }
        }
    }
    for (int i = 1; i < N; i++)
        sum1[i] = (sum1[i] + sum1[i - 1]) % MOD;
    for (int i = 1; i < N; i++)
        ans = (ans + (sum1[i - 1] * sum2[i]) % MOD) % MOD;
    cout << ans;
}
