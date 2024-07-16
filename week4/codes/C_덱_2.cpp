#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	deque<int> dq;
	int q; cin >> q; while (q--) {
		int cmd, p; cin >> cmd;
		if (cmd == 1) {
			cin >> p; dq.push_front(p);
		}
		else if (cmd == 2) {
			cin >> p; dq.push_back(p);
		}
		else if (cmd == 3) {
			if (dq.empty()) cout << "-1\n";
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (cmd == 4) {
			if (dq.empty()) cout << "-1\n";
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (cmd == 5) {
			cout << dq.size() << '\n';
		}
		else if (cmd == 6) {
			cout << (dq.empty() ? 1 : 0) << '\n';
		}
		else if (cmd == 7) {
			cout << (dq.empty() ? -1 : dq.front()) << '\n';
		}
		else {
			cout << (dq.empty() ? -1 : dq.back()) << '\n';
		}
	}
}
