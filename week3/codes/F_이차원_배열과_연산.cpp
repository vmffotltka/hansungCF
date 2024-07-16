#include <bits/stdc++.h>
using namespace std;

int arr[100][100];

bool comp(pair<int, int>a, pair<int, int>b) {
	return (a.second == b.second ? a.first < b.first : a.second < b.second);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int r, c, k; cin >> r >> c >> k;
	cin.ignore();
	int row = 3, col = 3;
	string s;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
	}
	for (int t = 0; t <= 100; t++) {
		if (arr[r - 1][c - 1] == k) { cout << t; return 0; }
		if (row < col) {
			int len = 0;
			for (int j = 0; j < col; j++) {
				map<int, int> m;
				vector<pair<int, int>> v;
				for (int i = 0; i < row; i++) {
					if (!arr[i][j]) continue;
					m[arr[i][j]]++;
				}
				for (auto item : m) {
					v.push_back(item);
				}
				sort(v.begin(), v.end(), comp);
				int idx = 0;
				for (auto item : v) {
					arr[idx++][j] = item.first;
					arr[idx++][j] = item.second;
				}
				while (idx < 100) {
					arr[idx++][j] = 0;
				}
				len = max(len, (int)v.size() * 2);
			}
			row = len;
		}
		else {
			int len = 0;
			for (int i = 0; i < row; i++) {
				map<int, int> m;
				vector<pair<int, int>> v;
				for (int j = 0; j < col; j++) {
					if (!arr[i][j]) continue;
					m[arr[i][j]]++;
				}
				for (auto item : m) {
					v.push_back(item);
				}
				sort(v.begin(), v.end(), comp);
				int idx = 0;
				for (auto item : v) {
					arr[i][idx++] = item.first;
					arr[i][idx++] = item.second;
				}
				while (idx < 100) {
					arr[i][idx++] = 0;
				}
				len = max(len, (int)v.size() * 2);
			}
			col = len;
		}
	}
	cout << -1;
}
