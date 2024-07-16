#include <bits/stdc++.h>
using namespace std;

bool isPrime[1300000];
vector<int> prime;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(isPrime, true, sizeof(isPrime));
	for (int i = 2; i < 1300000; i++) {
		if (!isPrime[i]) continue;
		prime.push_back(i);
		for (int j = i * 2; j < 1300000; j += i) {
			isPrime[j] = false;
		}
	}
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		if (isPrime[n] || n == 1) { cout << "0\n"; continue; }
		int idx = lower_bound(prime.begin(), prime.end(), n) - prime.begin();
		cout << prime[idx] - prime[idx - 1] << '\n';
	}
}
