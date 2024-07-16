#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    long long k; cin >> k;
    k--;
    int cnt = 0;
    for (int i = 0; (1LL << i) <= k; i++) {
        if ((1LL << i) & k)
            cnt++;
    }
    cout << (cnt & 1 ? 1 : 0);
}
