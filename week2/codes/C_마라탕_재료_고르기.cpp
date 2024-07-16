#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int N, K, taste[10][10], ans = -INF;
vector<int> choice;

void dfs(int idx, int depth) {
	if (depth == K) {
		int sum = 0;
		for (int i = 0; i < K; i++) {
			for (int j = i + 1; j < K; j++) {
				sum += taste[choice[i]][choice[j]];
			}
		}
		ans = max(ans, sum);
		return;
	}
	for (int i = idx; i < N; i++) {
		choice.push_back(i);
		dfs(i + 1, depth + 1);
		choice.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> taste[i][j];
	dfs(0, 0);
	cout << ans;
}
