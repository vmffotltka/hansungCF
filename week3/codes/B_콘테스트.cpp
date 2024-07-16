#include <bits/stdc++.h>
using namespace std;

int w[10], k[10];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 10; i++) cin >> w[i];
	for (int i = 0; i < 10; i++) cin >> k[i];
	sort(w, w + 10), sort(k, k + 10);
	cout << w[7] + w[8] + w[9] << " " << k[7] + k[8] + k[9];
}
