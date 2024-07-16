#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    string pw; cin >> pw;
    while (m--) {
        string s; cin >> s;
        int idx = 0;
        for (auto c : s) {
            if (idx == pw.length()) break;
            if (c == pw[idx])
                idx++;
        }
        cout << (idx == pw.length() ? "true\n" : "false\n");
    }
}
