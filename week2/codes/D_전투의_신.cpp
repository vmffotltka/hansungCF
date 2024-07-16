#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

long long N, A, PA, B, PB;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> A >> PA >> B >> PB;
	long long mx = -INF, ansX = 0, ansY = 0;
	for (long long i = 0; i <= N; i += PA) {
		long long ability = (i / PA) * A + ((N - i) / PB) * B;
		if (ability > mx) {
			mx = max(mx, ability);
			ansX = i / PA, ansY = (N - i) / PB;
		}
	}
	cout << ansX << " " << ansY;
}
