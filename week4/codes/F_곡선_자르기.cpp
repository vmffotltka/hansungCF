#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll, ll> arr[1000000];
deque<pair<ll, ll>> dq;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        dq.push_back({ x, y });
    }
    while (true) {
        if (dq[0].second < 0 && dq[1].second > 0) break;
        dq.push_back(dq.front());
        dq.pop_front();
    }
    ll r1 = INT_MAX, idx = 0;
    ll x = dq[0].first, y = dq[0].second;
    for (int i = 1; i < n; i++) {
        ll nx = dq[i].first, ny = dq[i].second;
        if (y * ny < 0) {
            if (r1 == INT_MAX) r1 = x;
            else {
                arr[idx++] = { min(r1, x), max(r1, x) };
                r1 = INT_MAX;
            }
        }
        x = nx, y = ny;
    }
    sort(arr, arr + idx);
    int ans1 = 0, ans2 = 1;
    stack<pair<ll, ll>> st;
    for (int i = 0; i < idx; i++) {
        bool tri = false;
        while (!st.empty() && !(st.top().first < arr[i].first && arr[i].second < st.top().second)) {
            st.pop();
            tri = true;
        }
        if (tri) ans2++;
        if (st.empty()) ans1++;
        st.push(arr[i]);
    }
    cout << ans1 << " " << ans2;
}
