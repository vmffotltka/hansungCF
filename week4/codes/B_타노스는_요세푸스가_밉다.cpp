#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k; cin >> n >> k;
	deque<int> dq;
	for (int i = 0; i < n; i++) dq.push_back(i + 1);
	while (true) {
		if (dq.size() <= k) {
			cout << dq.front();
			return 0;
		}
		dq.push_back(dq.front());
		dq.pop_front();
		for (int i = 0; i < k - 1; i++)
			dq.pop_front();
	}
}
