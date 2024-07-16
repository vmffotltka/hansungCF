#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m; cin >> n >> m;
	vector<int> arr(n), cnt(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int mx = -1, ans;
	for (int i = 0; i < m; i++) {
		int p; cin >> p;
		for (int j = 0; j < n; j++) {
			if (arr[j] <= p) {
				cnt[j]++;
				if (mx < cnt[j]) {
					mx = cnt[j];
					ans = j + 1;
				}
				break;
			}
		}
	}
	cout << ans;
}
