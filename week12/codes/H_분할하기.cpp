#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    k--;
    cout << "YES\n";
    vector<int> ans = { 0 };
    int gap = 2, p = 1, start = 1;
    while (true) {
        if (p * 2 > k) break;
        p *= 2;
    }
    int cnt = k;
    while (cnt) {
        if (k & p) {
            for (int i = start; i < start + p * gap; i += gap) {
                ans.push_back(i);
                cnt--;
                if (!cnt) break;
            }
            start <<= 1, gap <<= 1;
        }
        p >>= 1;
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << " ";
}
