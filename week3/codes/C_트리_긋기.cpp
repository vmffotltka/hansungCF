#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x, y, idx;
};

Point arr[1000];

bool comp(Point a, Point b) {
	return (a.y == b.y ? a.x < b.x : a.y < b.y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
		arr[i].idx = i + 1;
	}
	sort(arr, arr + n, comp);
	for (int i = 1; i < n; i++) {
		cout << arr[i].idx << " " << arr[i - 1].idx << '\n';
	}
}
