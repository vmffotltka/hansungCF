#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, ans = 0; cin >> n;
	for (int i = 1; i <= n; i++) {
		int num = i;
		while (num) {
			int p = num % 10;
			if (p == 3 || p == 6 || p == 9) ans++;
			num /= 10;
		}
	}
	cout << ans;
}
