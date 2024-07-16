#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void normalize(ll& a, ll& b) {
    if (b < 0) {
        a = -a;
        b = -b;
    }
    if (a == 0) {
        b = 1;
    }
    else if (b == 0) {
        a = 1;
    }
    else {
        ll g = gcd(abs(a), abs(b));
        a /= g;
        b /= g;
    }
}

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<ll, ll>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        unordered_map<pair<ll, ll>, ll, pair_hash> slope_count;
        ll h = 0, v = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            ll dx = points[j].first - points[i].first;
            ll dy = points[j].second - points[i].second;
            if (dx == 0) h++;
            else if (dy == 0) v++;
            else {
                normalize(dx, dy);
                slope_count[{dx, dy}]++;
            }
        }
        for (const auto& [slope, count] : slope_count) {
            ll dx = slope.first, dy = slope.second;
            dx = -dx;
            normalize(dy, dx);
            ans += count * slope_count[{dy, dx}];
            if (!slope_count[{dy, dx}]) slope_count.erase({ dy, dx });
        }
        ans += h * v * 2;
    }
    cout << ans / 2;
}
