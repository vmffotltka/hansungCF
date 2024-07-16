#include <bits/stdc++.h>
using namespace std;

bool prime[2001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(prime, true, sizeof(prime));
    prime[0] = false, prime[1] = false;
    for (int i = 2; i <= 2001; i++) {
        if (!prime[i]) continue;
        for (int j = i * 2; j <= 2001; j += i)
            prime[j] = false;
    }
    int t; cin >> t; while (t--) {
        int a, b, turn = 0, kuro = 0, siro = 0, idx = 0;
        cin >> a >> b;
        while (idx < b) {
            int dest = idx + 1;
            for (int i = idx + 1; i <= min(b, idx + a); i++) {
                if (prime[i]) {
                    (!turn ? kuro++ : siro++);
                    dest = i;
                }
            }
            idx = dest;
            turn ^= 1;
        }
        cout << (kuro == siro ? "draw\n" : (kuro > siro ? "kuro\n" : "siro\n"));
    }
}
