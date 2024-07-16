#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, num = 1, cnt = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        if (p == num) num++, cnt++;
    }
    cout << n - cnt;
}
