#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll segment[6];

ll form(ll x, ll y) {
    x -= x % 5, y -= y % 5;
    x /= 5, y /= 5;
    return ((x + y) % 2 ? 2 : 1);
}

void compute1(ll x1, ll y1, ll x2, ll y2) {
    if (x1 == x2) return;
    ll yBound1 = (y1 % 5 ? y1 + (5 - y1 % 5) : y1), yBound2 = y2 - y2 % 5;
    if (yBound1 > yBound2) {
        ll formation = form(x1, y1);
        if (formation == 1)
            segment[x2 - x1] += y2 - y1;
        else
            segment[y2 - y1] += x2 - x1;
    }
    else {
        ll form1 = form(x1, y1), form2 = form(x1, y2);
        if (form1 == 1)
            segment[x2 - x1] += yBound1 - y1;
        else
            segment[yBound1 - y1] += x2 - x1;
        if (form2 == 1)
            segment[x2 - x1] += y2 - yBound2;
        else
            segment[y2 - yBound2] += x2 - x1;
        if (yBound1 < yBound2) {
            form1 = form(x1, yBound1), form2 = form(x1, yBound2 - 5);
            ll len = yBound2 - yBound1;
            if (form1 == form2) {
                if (form1 == 1) {
                    segment[x2 - x1] += 5;
                }
                else {
                    segment[5] += x2 - x1;
                }
                segment[x2 - x1] += 5 * ((len - 5) / 10);
                segment[5] += (x2 - x1) * ((len - 5) / 10);
            }
            else {
                segment[x2 - x1] += 5 * (len / 10);
                segment[5] += (x2 - x1) * (len / 10);
            }
        }
    }
}

void compute2(ll x1, ll y1, ll x2, ll y2) {
    ll yBound1 = (y1 % 5 ? y1 + (5 - y1 % 5) : y1), yBound2 = y2 - y2 % 5;
    ll form1 = form(x1, y1);
    vector<ll> tmp1(6), tmp2(6);
    if (yBound1 > yBound2) {
        if (form1 == 1) {
            tmp1[5] += y2 - y1;
            tmp2[y2 - y1] += 5;
        }
        else {
            tmp1[y2 - y1] += 5;
            tmp2[5] += y2 - y1;
        }
    }
    else {
        ll form2 = form(x1, yBound2);
        if (form1 == 1) {
            tmp1[5] += yBound1 - y1;
            tmp2[yBound1 - y1] += 5;
        }
        else {
            tmp1[yBound1 - y1] += 5;
            tmp2[5] += yBound1 - y1;
        }
        if (form2 == 1) {
            tmp1[5] += y2 - yBound2;
            tmp2[y2 - yBound2] += 5;
        }
        else {
            tmp1[y2 - yBound2] += 5;
            tmp2[5] += y2 - yBound2;
        }
        if (yBound1 < yBound2) {
            tmp1[5] += yBound2 - yBound1;
            tmp2[5] += yBound2 - yBound1;
        }
    }
    ll len = x2 - x1;
    if (len % 10) {
        for (ll i = 1; i <= 5; i++)
            segment[i] += tmp1[i];
        for (ll i = 1; i <= 5; i++)
            segment[i] += tmp1[i] * ((len - 5) / 10) + tmp2[i] * ((len - 5) / 10);
    }
    else {
        for (ll i = 1; i <= 5; i++)
            segment[i] += tmp1[i] * (len / 10) + tmp2[i] * (len / 10);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    ll xBound1 = (x1 % 5 ? x1 + (5 - x1 % 5) : x1), xBound2 = x2 - x2 % 5;
    if (xBound1 > xBound2) {
        compute1(x1, y1, x2, y2);
    }
    else if (xBound1 == xBound2) {
        compute1(x1, y1, xBound1, y2);
        compute1(xBound1, y1, x2, y2);
    }
    else {
        compute1(x1, y1, xBound1, y2);
        compute1(xBound2, y1, x2, y2);
        compute2(xBound1, y1, xBound2, y2);
    }
    ll ans = segment[5];
    if (segment[4]) {
        ans += segment[4];
        segment[1] = max(0LL, segment[1] - segment[4]);
    }
    if (segment[3] > segment[2]) {
        ans += segment[2];
        segment[3] -= segment[2];
        segment[2] = 0;
    }
    else {
        ans += segment[3];
        segment[2] -= segment[3];
        segment[3] = 0;
    }
    if (segment[3]) {
        ans += segment[3];
        segment[1] = max(0LL, segment[1] - segment[3] * 2);
    }
    if (segment[2]) {
        ans += (segment[2] - segment[2] % 2) / 2;
        segment[1] = max(0LL, segment[1] - (segment[2] - segment[2] % 2) / 2);
        if (segment[2] & 1) {
            ans++;
            segment[1] = max(0LL, segment[1] - 3);
        }
    }
    if (segment[1])
        ans += (segment[1] + 4) / 5;
    cout << ans;
}
