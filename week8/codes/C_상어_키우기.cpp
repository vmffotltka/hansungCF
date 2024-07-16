#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K, T, shark[200001], parent[200001];
ll find(ll n) {
    if (parent[n] == n) return n;
    return parent[n] = find(parent[n]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K >> T;
    for (int i = 1; i <= N; i++) parent[i] = i;
    for (int i = 1; i <= N; i++)
        cin >> shark[i];
    sort(shark, shark + N + 1);
    while (K--) {
        int idx = lower_bound(shark, shark + N + 1, T) - shark - 1;
        idx = find(idx);
        if (!idx) break;
        parent[idx] = find(idx - 1);
        T += shark[idx];
    }
    cout << T;
}
