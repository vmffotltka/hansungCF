#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s, t; cin >> s >> t;
    int cnt1 = 0, cnt2 = 0;
    for (auto c : s) {
        if (c == 'B') cnt1++;
    }
    for (auto c : t) {
        if (c == 'B') cnt2++;
    }
    if (cnt1 > cnt2) { cout << 0; return 0; }
    if ((cnt2 - cnt1) % 2 == 0) {
        bool tri = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i]) {
                tri = false; break;
            }
        }
        if (tri) {
            bool tri2 = true;
            for (int i = s.length(); i < t.length(); i++) {
                if (t[i] != 'A') {
                    tri2 = false;
                    break;
                }
            }
            if (tri2) { cout << 1; return 0; }
        }
        int c1 = 0;
        for (int i = 0; i < t.length(); i++) {
            if (t[i] == 'B') {
                c1++;
                bool tri2 = true;
                for (int j = 0; j < s.length(); j++) {
                    if (i + j + 1 >= t.length() || t[i + j + 1] != s[j]) {
                        tri2 = false; break;
                    }
                }
                if (tri2) {
                    int c2 = 0;
                    for (int j = i + s.length() + 1; j < t.length(); j++) {
                        if (t[j] == 'B')
                            c2++;
                    }
                    if (c1 == c2) {
                        cout << 1; return 0;
                    }
                }
            }
        }
    }
    else {
        int c1 = 0;
        for (int i = t.length() - 1; i >= 0; i--) {
            if (t[i] == 'B') {
                c1++;
                bool tri = true;
                for (int j = 0; j < s.length(); j++) {
                    if (i - j - 1 < 0 || t[i - j - 1] != s[j]) {
                        tri = false; break;
                    }
                }
                if (tri) {
                    int c2 = 0;
                    for (int j = i - s.length() - 1; j >= 0; j--) {
                        if (t[j] == 'B')
                            c2++;
                    }
                    if (c1 -1 == c2) {
                        cout << 1; return 0;
                    }
                }
            }
        }
    }
    cout << 0;
}
