#include <bits/stdc++.h>
using namespace std;

int arr[6][4];
char comp[3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 9; j++) {
			if (j == 4)
				cin >> comp[i];
			else {
				int n; cin >> n;
				if (j < 4)
					arr[i * 2][j] = n;
				else
					arr[i * 2 + 1][j - 5] = n;
			}
		}
	}
	vector<string> ans;
	for (int n = 1; n <= 12; n++) {
		for (int heavy = 0; heavy <= 1; heavy++) {
			bool tri = true;
			for (int i = 0; i < 3; i++) {
				int right = 0, left = 0;
				for (int j = 0; j < 4; j++) {
					if (arr[i * 2][j] == n) (heavy ? left++ : left--);
				}
				for (int j = 0; j < 4; j++) {
					if (arr[i * 2 + 1][j] == n) (heavy ? right++ : right--);
				}
				if ((comp[i] == '>' && left <= right) ||
					(comp[i] == '<' && left >= right) ||
					(comp[i] == '=' && left != right)) {
					tri = false;
					break;
				}
			}
			if (tri) {
				ans.push_back(to_string(n) + (heavy ? "+" : "-"));
			}
		}
	}
	if (ans.empty()) cout << "impossible";
	else if (ans.size() > 1) cout << "indefinite";
	else cout << ans[0];
}
