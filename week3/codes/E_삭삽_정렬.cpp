#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t; while (t--) {
		int tst, n; cin >> tst >> n;
		vector<int> st; priority_queue<int> pq;
		for (int i = 0; i < n; i++) {
			int p; cin >> p;
			while (!st.empty() && st.back() > p) {
				pq.push(-st.back());
				st.pop_back();
			}
			st.push_back(p);
		}
		cout << tst << " " << (pq.empty() ? 0 : pq.size() + st.end() - upper_bound(st.begin(), st.end(), -pq.top())) << '\n';
	}
}
