#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while (t--) {
        string s; cin >> s;
        bool ans = true;
        while (true) {
            for (int i = 0; i < s.length() / 2; i++) {
                if (s[i] == s[s.length() - 1 - i]) {
                    ans = false; break;
                }
            }
            if (!ans || s.length() == 1) break;
            s = s.substr(0, s.length() / 2);
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}
