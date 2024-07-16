#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll arr[200000];

pii dfs(ll left, ll right) {
    if (left == right - 1)
        return { arr[left], arr[left] };
    ll bound = (right + left) / 2;
    pii toLeft = dfs(left, bound), toRight = dfs(bound, right);
    ll p1 = toLeft.first + toRight.second, p2 = toLeft.second + toRight.first;
    ll g = gcd(toLeft.first, toRight.first);
    return { g, max(p1, p2) };
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    pii ans = dfs(0, n);
    cout << max(ans.first, ans.second);
}
