#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int N, HP, ans = INF;
int cool[5], damage[5], wait[5];

void setCoolTime(int p) {
	for (int i = 0; i < N; i++) {
		wait[i] = max(0, wait[i] + p);
	}
}

void dfs(int time) {
	if (HP <= 0) {
		ans = min(ans, time);
		return;
	}
	bool tri = true;
	int mn = INF;
	for (int i = 0; i < N; i++) {
		if (!wait[i]) {
			vector<int> clone(wait, wait + N);
			tri = false;
			HP -= damage[i];
			wait[i] += cool[i];
			setCoolTime(-1);
			dfs(time + 1);
			for (int i = 0; i < N; i++)
				wait[i] = clone[i];
			HP += damage[i];
		}
		else mn = min(mn, wait[i]);
	}
	if (tri) {
		setCoolTime(-mn);
		time += mn;
		for (int i = 0; i < N; i++) {
			if (wait[i]) continue;
			vector<int> clone(wait, wait + N);
			HP -= damage[i];
			wait[i] += cool[i];
			setCoolTime(-1);
			dfs(time + 1);
			for (int i = 0; i < N; i++)
				wait[i] = clone[i];
			HP += damage[i];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> HP;
	for (int i = 0; i < N; i++)
		cin >> cool[i] >> damage[i];
	dfs(0);
	cout << ans;
}
