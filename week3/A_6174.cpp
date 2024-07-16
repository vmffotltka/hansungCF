#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t; while (t--) {
		string s; cin >> s;
		int ans = 0;
		while (true) {
			if (s == "6174") break;
			if (count(s.begin(), s.end(), s[0]) == 4) break;
			string a = s, b = s;
			sort(a.begin(), a.end());
			sort(b.rbegin(), b.rend());
			s = to_string(stoi(b) - stoi(a));
			string tmp(4 - s.length(), '0');
			s = tmp + s;
			ans++;
		}
		cout << ans << '\n';
	}
}
