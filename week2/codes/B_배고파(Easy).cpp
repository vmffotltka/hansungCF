#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t; while (t--) {
		long long n; cin >> n;
		for (int i = 0; ((long long)1 << i) <= n; i++) {
			for (int j = i; ((long long)1 << j) <= n; j++) {
				if (((long long)1 << i) + ((long long)1 << j) == n)
					cout << i << " " << j << '\n';
			}
		}
	}
}
