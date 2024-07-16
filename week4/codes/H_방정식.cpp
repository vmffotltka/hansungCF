#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

struct Frac {
    ll a, b;
    bool rev;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; getline(cin, s);
    stack<pii> st; stack<Frac> X; stack<char> op;
    for (auto c : s) {
        if (c == ' ') continue;
        if (c == 'X') {
            st.push(pii(1, 0));
        }
        else if (isdigit(c)) {
            st.push(pii(c - '0', 1));
        }
        else {
            pii b = st.top(); st.pop();
            pii a = st.top(); st.pop();
            if (c == '+') {
                if (!a.second) {
                    X.push({ b.first, b.second, false });
                    st.push(pii(0, 0));
                    op.push(c);
                }
                else if (!b.second) {
                    X.push({ a.first, a.second, false });
                    st.push(pii(0, 0));
                    op.push(c);
                }
                else {
                    ll up = a.first * b.second + a.second * b.first;
                    ll down = a.second * b.second;
                    ll g = gcd(up, down);
                    st.push(pii(up / g, down / g));
                }
            }
            else if (c == '-') {
                if (!a.second) {
                    X.push({ b.first, b.second, false });
                    st.push(pii(0, 0));
                    op.push(c);
                }
                else if (!b.second) {
                    X.push({ a.first, a.second, true });
                    st.push(pii(0, 0));
                    op.push(c);
                }
                else {
                    ll up = a.first * b.second - a.second * b.first;
                    ll down = a.second * b.second;
                    ll g = gcd(up, down);
                    st.push(pii(up / g, down / g));
                }
            }
            else if (c == '*') {
                if (!a.second) {
                    X.push({ b.first, b.second, false });
                    st.push(pii(0, 0));
                    op.push(c);
                }
                else if (!b.second) {
                    X.push({ a.first, a.second, false });
                    st.push(pii(0, 0));
                    op.push(c);
                }
                else {
                    ll up = a.first * b.first;
                    ll down = a.second * b.second;
                    ll g = gcd(up, down);
                    st.push(pii(up / g, down / g));
                }
            }
            else if (c == '/') {
                if (!a.second) {
                    X.push({ b.first, b.second, false });
                    st.push(pii(0, 0));
                    op.push(c);
                }
                else if (!b.second) {
                    X.push({ a.first, a.second, true });
                    st.push(pii(0, 0));
                    op.push(c);
                }
                else {
                    ll up = a.first * b.second;
                    ll down = b.first * a.second;
                    ll g = gcd(up, down);
                    st.push(pii(up / g, down / g));
                }
            }
        }
    }
    if (X.empty() && st.top().second) {
        if (!st.top().first) cout << "MULTIPLE";
        else cout << "NONE";
        return 0;
    }
    ll ansNum = 0, ansDem = 1;
    while (!X.empty()) {
        auto [up, down, tri] = X.top(); X.pop();
        char oper = op.top(); op.pop();
        if (oper == '+') {
            ll p = ansNum * down - ansDem * up;
            ll q = ansDem * down;
            ll g = gcd(p, q);
            ansNum = p / g, ansDem = q / g;
        }
        else if (oper == '-') {
            if (!tri) {
                ll p = ansNum * down + ansDem * up;
                ll q = ansDem * down;
                ll g = gcd(p, q);
                ansNum = p / g, ansDem = q / g;
            }
            else {
                ll p = ansDem * up - ansNum * down;
                ll q = ansDem * down;
                ll g = gcd(p, q);
                ansNum = p / g, ansDem = q / g;
            }
        }
        else if (oper == '*') {
            if (!up && !ansNum) {
                cout << "MULTIPLE";
                return 0;
            }
            else if (!up) {
                cout << "NONE";
                return 0;
            }
            ll p = ansNum * down;
            ll q = ansDem * up;
            ll g = gcd(p, q);
            ansNum = p / g, ansDem = q / g;
        }
        else if (oper == '/') {
            if (!up && !ansNum) {
                cout << "MULTIPLE";
                return 0;
            }
            else if (!up) {
                cout << "NONE";
                return 0;
            }
            if (!tri) {
                ll p = ansNum * up;
                ll q = ansDem * down;
                ll g = gcd(p, q);
                ansNum = p / g, ansDem = q / g;
            }
            else {
                if (!ansNum) {
                    cout << "NONE";
                    return 0;
                }
                ll p = ansDem * up;
                ll q = ansNum * down;
                ll g = gcd(p, q);
                ansNum = p / g, ansDem = q / g;
            }
        }
    }
    ll g = gcd(ansNum, ansDem);
    ansNum /= g, ansDem /= g;
    if (ansDem < 0) ansNum *= -1, ansDem *= -1;
    cout << "X = " << ansNum << "/" << (ansNum ? ansDem : 1);
}
