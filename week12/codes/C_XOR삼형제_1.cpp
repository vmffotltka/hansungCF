#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        int p = 5, s = 1;
        for (int i = p; i <= n; i *= 2)
            s *= 2;
        vector<int> ans;
        for (int i = s; i < s * 3; i++) {
            if (i > n) break;
            ans.push_back(i);
        }
        for (int i = s * 4; i < s * 5; i++) {
            if (i > n) break;
            ans.push_back(i);
        }
        cout << ans.size() << '\n';
        for (auto i : ans) cout << i << " ";
        cout << '\n';
    }
}
