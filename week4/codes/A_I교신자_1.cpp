#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;

vector<ll> st;
ll I, A, B, C, K, ans[40], cnt[3];

void dfs(int depth) {
	if (depth == A + B + C) {
		for (int i = 0; i < K; i++) {
			ans[i] = (ans[i] + st[st.size() - 1 - i]) % MOD;
		}
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (!cnt[i]) continue;
		cnt[i]--;
		if (i == 0) {
			st.push_back(I);
			dfs(depth + 1);
			st.pop_back();
		}
		else {
			ll p = (st.empty() ? I : st.back());
			if (!st.empty()) st.pop_back();
			ll q = (st.empty() ? I : st.back());
			if (!st.empty()) st.pop_back();
			st.push_back((i == 1 ? (p + q) : (p * q)) % MOD);
			dfs(depth + 1);
			st.pop_back();
			st.push_back(q);
			st.push_back(p);
		}
		cnt[i]++;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> I >> A >> B >> C >> K;
	cnt[0] = A, cnt[1] = B, cnt[2] = C;
	st = vector<ll>(50, I);
	dfs(0);
	for (int i = 0; i < K; i++) {
		cout << ans[i] << '\n';
	}
}
