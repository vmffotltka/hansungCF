#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int s, m; cin >> s >> m;
    if (s < 1024) cout << "No thanks";
    else {
        int change = s - 1023;
        for (int i = 0; (1 << i) <= change; i++) {
            if (((1 << i) & change) && (!((1 << i) & m))) {
                cout << "Impossible";
                return 0;
            }
        }
        cout << "Thanks";
    }
}
