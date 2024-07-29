#include <bits/stdc++.h>
using namespace std;

int N, Q;
deque<int> dq;
set<int> s1, s2;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    int front = 1;
    for (int i = 0; i < Q; i++) {
        int command; cin >> command;
        if (command == 0) {
            int p; cin >> p;
            s2.insert(p);
            (front ? dq.push_front(p) : dq.push_back(p));
        }
        else if (command == 1) {
            deque<int>().swap(dq);
            for (auto item : s2)
                s1.insert(item);
            set<int>().swap(s2);
            if (!s1.empty())
                dq.push_back(-1);
            front = 1;
        }
        else if (command == 2)
            front ^= 1;
        else {
            if (front) {
                if (dq.front() == -1) {
                    int p = *s1.begin();
                    cout << p << '\n';
                    s1.erase(p);
                    if (s1.empty())
                        dq.pop_front();
                }
                else {
                    s2.erase(dq.front());
                    cout << dq.front() << '\n';
                    dq.pop_front();
                }
            }
            else {
                if (dq.back() == -1) {
                    int p = *s1.rbegin();
                    cout << p << '\n';
                    s1.erase(p);
                    if (s1.empty())
                        dq.pop_back();
                }
                else {
                    s2.erase(dq.back());
                    cout << dq.back() << '\n';
                    dq.pop_back();
                }
            }
        }
    }
}
