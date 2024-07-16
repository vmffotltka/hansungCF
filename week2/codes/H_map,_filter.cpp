#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;

ull a = 1, b = 0, arr[100000], accArr[100000], arrSize = 0;
map<ull, ull> cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ull n, q; cin >> n;
    for (ull i = 0; i < n; i++) {
        ull p; cin >> p;
        cnt[p]++;
    }
    ull sum = 0;
    for (auto& i : cnt) {
        arr[arrSize] = i.first;
        sum += i.second;
        accArr[arrSize] = sum;
        arrSize++;
    }
    cin >> q;
    ull mod = 0;
    while (q--) {
        string s; cin >> s;
        if (s == "map") {
            char c; cin >> c;
            ull p; cin >> p;
            if (c == '+') {
                b += p;
            }
            else if (c == '*') {
                a *= p, b *= p;
            }
            else {
                mod = p;
                a %= mod, b %= mod;
                map<ull, ull> tmp, tmpAcc;
                for (auto& i : cnt) {
                    tmp[(((i.first) * a) % mod + b) % mod] += i.second;
                }
                cnt.swap(tmp);
                arrSize = 0;
                ull sum = 0;
                for (auto& i : cnt) {
                    arr[arrSize] = i.first;
                    sum += i.second;
                    accArr[arrSize] = sum;
                    arrSize++;
                }
                a = 1, b = 0;
            }
        }
        else {
            string s; cin >> s;
            long double num; cin >> num;
            num = (num - b) / (long double)a;
            if (abs((ull)num - num) <= 1e-9) num = (ull)num;
            auto it = lower_bound(arr, arr + arrSize, num);
            if (s == ">=") {
                if (it == arr + arrSize) {
                    cout << "0\n";
                }
                else if (it == arr) {
                    cout << accArr[arrSize - 1] << '\n';
                }
                else {
                    cout << accArr[arrSize - 1] - accArr[(it - arr) - 1] << '\n';
                }
            }
            else if (s == "<=") {
                if (it == arr && *it > num) {
                    cout << "0\n";
                }
                else {
                    if (it == arr + arrSize || *it > num) --it;
                    cout << accArr[it - arr] << '\n';
                }
            }
            else {
                if (it == arr + arrSize || *it != num) {
                    cout << "0\n";
                }
                else if (it == arr) {
                    cout << accArr[it - arr] << '\n';
                }
                else {
                    cout << accArr[it - arr] - accArr[(it - arr) - 1] << '\n';
                }
            }
        }
    }
}
