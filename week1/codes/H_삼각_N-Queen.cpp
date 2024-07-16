#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		int cnt = (n * 2 + 1) / 3; // 배치해야 할 퀸의 수
		cout << cnt << '\n';
		int j = 0;	
		for (int i = n - cnt; i < n; i++) { // 가로로 +2하면서 한줄 씩 내려온다
			if (j > i) j = 1; // 가로 인덱스가 세로 인덱스보다 클 경우 인덱스 1로 조정
			cout << i + 1 << " " << j + 1 << '\n';
			j += 2;
		}
	}
}
