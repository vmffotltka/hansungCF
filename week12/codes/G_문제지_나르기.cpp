#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, Q, M[2048], Coor[11], Parking[11], BIT = 0;

void dfs1(int idx, ll sum) {
    if (idx == 11) {
        M[BIT] = max(M[BIT], sum);
        BIT++;
        return;
    }
    dfs1(idx + 1, sum + Coor[idx]);
    dfs1(idx + 1, sum - Coor[idx]);
}

ll dfs2(int idx, ll sum) {
    if (idx == 11) {
        ll ret = M[BIT] + sum;
        BIT++;
        return ret;
    }
    ll p1 = dfs2(idx + 1, sum - Parking[idx]);
    ll p2 = dfs2(idx + 1, sum + Parking[idx]);
    return max(p1, p2);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 0; i < 2048; i++)
        M[i] = -LLONG_MAX;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 11; j++)
            cin >> Coor[j];
        BIT = 0;
        dfs1(0, 0);
    }
    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < 11; j++)
            cin >> Parking[j];
        BIT = 0;
        ll ans = dfs2(0, 0);
        cout << ans << '\n';
    }
}
