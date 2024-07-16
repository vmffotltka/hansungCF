#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;

ll N, AND[200001][30][2], OR[200001][30][2], XOR[200001][30][2];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    ll ansAND = 0, ansOR = 0, ansXOR = 0;
    for (int i = 1; i <= N; i++) {
        ll p; cin >> p;
        for (int j = 0; j < 30; j++) {
            int bit = (1LL << j) & p;
            if (bit) {
                AND[i][j][0] = AND[i - 1][j][0];
                AND[i][j][1] = (AND[i - 1][j][1] + 1) % MOD;
                OR[i][j][0] = 0;
                OR[i][j][1] = (OR[i - 1][j][0] + OR[i - 1][j][1] + 1) % MOD;
                XOR[i][j][0] = XOR[i - 1][j][1];
                XOR[i][j][1] = (XOR[i - 1][j][0] + 1) % MOD;
            }
            else {
                AND[i][j][0] = (AND[i - 1][j][0] + AND[i - 1][j][1] + 1) % MOD;
                AND[i][j][1] = 0;
                OR[i][j][0] = (OR[i - 1][j][0] + 1) % MOD;
                OR[i][j][1] = OR[i - 1][j][1];
                XOR[i][j][0] = (XOR[i - 1][j][0] + 1) % MOD;
                XOR[i][j][1] = XOR[i - 1][j][1];
            }
            ansAND = (ansAND + (((1LL << j) * AND[i][j][1]) % MOD)) % MOD;
            ansOR = (ansOR + (((1LL << j) * OR[i][j][1]) % MOD)) % MOD;
            ansXOR = (ansXOR + (((1LL << j) * XOR[i][j][1]) % MOD)) % MOD;
        }
    }
    cout << ansAND << " " << ansOR << " " << ansXOR;
}
