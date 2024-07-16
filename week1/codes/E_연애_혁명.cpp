#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int u, v, w, com;
};

int parent[10001];
vector<Edge> arr;

int find(int n) {
	if (parent[n] == n) return n;
	return parent[n] = find(parent[n]);
}

bool comp(Edge a, Edge b) {
	return a.w > b.w;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, ans = 0; cin >> n >> m;
	arr = vector<Edge>(m);
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		int u, v, w, com; cin >> u >> v >> w >> com;
		arr[i] = { u, v, w, com };
		if (com) {
			u = find(u), v = find(v);
			parent[v] = u;
		}
	}
	sort(arr.begin(), arr.end(), comp);
	for (int i = 0; i < m; i++) {
		int u = arr[i].u, v = arr[i].v, w = arr[i].w, com = arr[i].com;
		if (com) continue;
		u = find(u), v = find(v);
		if (u == v) {
			ans += w; continue;
		}
		parent[v] = u;
	}
	cout << ans;
}
