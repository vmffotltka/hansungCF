#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, ans = 0; cin >> n;
	for (int i = 1; i <= n; i++) {
		int p; cin >> p;
		if (i != p) ans++;
	}
	cout << ans;
}
