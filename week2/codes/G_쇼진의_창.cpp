#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long x, y, k; cin >> x >> y >> k;
	long long up = (k - 1) / x + 1, down = (k - 1) / (x + y) + 1, ans = k;
	for (long long time = max(x + y, k - k % (x + y) + (k % (x + y) ? x + y : 0)) + 1; time < k + (x + y) * x; time += x + y) {
		long long curUp = (time - 1) / x + 1, curDown = (time - 1) / (x + y) + 1;
		if (up * curDown > down * curUp) {
			up = curUp, down = curDown, ans = time;
		}
	}
	cout << ans;
}
