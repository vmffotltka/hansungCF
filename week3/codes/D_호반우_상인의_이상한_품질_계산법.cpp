#include <bits/stdc++.h>
using namespace std;

int arr[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int ans = 0;
	for (int i = n / 2; i < n; i++) {
		if (n & 1 && i == n / 2) continue;
		ans += arr[i] * 2;
	}
	if (n & 1) ans += arr[n / 2];
	cout << ans;
}
