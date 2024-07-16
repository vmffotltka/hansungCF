#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const string NATO[26] = { "ALFA", "BRAVO", "CHARLIE", "DELTA", "ECHO", "FOXTROT", "GOLF", "HOTEL", "INDIA", "JULIETT", "KILO", "LIMA", "MIKE", "NOVEMBER", "OSCAR", "PAPA", "QUEBEC", "ROMEO", "SIERRA", "TANGO", "UNIFORM", "VICTOR", "WHISKEY", "XRAY", "YANKEE", "ZULU" };
ll LEN[26][41][26], SUM[26][41], dp[41][200000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; ll q, idx = 0; cin >> s >> q;
    for (int i = 0; i < 26; i++) LEN[i][0][i] = 1, SUM[i][0] = 1;
    for (int i = 0; i < 26; i++) {
        for (int j = 1; j <= 40; j++) {
            ll sum = 0;
            for (int k = 0; k < 26; k++) {
                for (auto c : NATO[k]) {
                    LEN[i][j][c - 'A'] = min(static_cast<ll>(1e18), LEN[i][j][c - 'A'] + LEN[i][j - 1][k]);
                    sum = min(static_cast<ll>(1e18), sum + LEN[i][j - 1][k]);
                }
            }
            SUM[i][j] = sum;
        }
    }
    for (int i = 0; i <= 40; i++) {
        for (ll j = 0; j < s.length(); j++) {
            ll sum = 0;
            for (int k = 0; k < 26; k++)
                sum = min(static_cast<ll>(1e18), sum + LEN[s[j] - 'A'][i][k]);
            dp[i][j] = (!j ? sum : min(static_cast<ll>(1e18), dp[i][j - 1] + sum));
        }
    }
    while (q--) {
        ll cmd, p; cin >> cmd >> p;
        if (cmd == 1)
            idx = min(40LL, idx + p);
        else {
            ll index = lower_bound(dp[idx], dp[idx] + s.length(), p) - dp[idx];
            ll target = (index ? p - dp[idx][index - 1] : p), depth = 0;
            char cur = s[index];
            while (true) {
                int dif = idx - depth;
                bool tri = false;
                for (auto c : NATO[cur - 'A']) {
                    target -= SUM[c - 'A'][dif];
                    if (target <= 0) {
                        if (!dif) {
                            cout << c;
                            tri = true;
                        }
                        else {
                            depth++;
                            cur = c;
                            target += SUM[c - 'A'][dif];
                        }
                        break;
                    }
                }
                if (tri) break;
            }
        }
    }
}
