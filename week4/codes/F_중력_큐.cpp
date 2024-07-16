#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    deque<int> dq;
    int idx = 0, ball = 0, wall = 0;
    int q; cin >> q; while (q--) {
        string cmd; cin >> cmd;
        if (cmd == "push") {
            char c; cin >> c;
            int p = (c == 'b' ? 1 : -1);
            if ((idx == 3 && p == 1) || (idx == 1 && p == 1 && !wall))
                continue;
            dq.push_front(p);
            (p == 1 ? ball++ : wall++);
        }
        else if (cmd == "pop") {
            if (dq.empty()) continue;
            (dq.back() == 1 ? ball-- : wall--);
            dq.pop_back();
            if (idx == 1) {
                while (!dq.empty() && dq.back() == 1) {
                    ball--;
                    dq.pop_back();
                }
            }
        }
        else if (cmd == "rotate") {
            char c; cin >> c;
            if (c == 'r')
                idx = (idx + 1) % 4;
            else
                idx = (idx + 3) % 4;
            if (idx == 1) {
                while (!dq.empty() && dq.back() == 1) {
                    ball--;
                    dq.pop_back();
                }
            }
            else if (idx == 3) {
                while (!dq.empty() && dq.front() == 1) {
                    ball--;
                    dq.pop_front();
                }
            }
        }
        else if (cmd == "count") {
            char c; cin >> c;
            cout << (c == 'b' ? ball : wall) << '\n';
        }
    }
}
