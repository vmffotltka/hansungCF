#include <bits/stdc++.h>
#define DEPTH 17
using namespace std;

int sero, garo, T, K;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int in[100002], out[100002], parent[100000][DEPTH], level[100000];
map<int, bool> horizontal_wall[100000], vertical_wall[100000];

void bfs() {
	deque<pair<int, int>> dq, tmp;
	vector<vector<int>> vis(sero, vector<int>(garo, -1));
	dq.push_back({ 0, 0 });
	vis[0][0] = 0, level[0] = 0;
	int dist = 1;
	while (!dq.empty()) {
		int y = dq.front().first, x = dq.front().second;
		dq.pop_front();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (0 <= ny && ny < sero && 0 <= nx && nx < garo && vis[ny][nx] == -1) {
				if (i == 0 && horizontal_wall[ny][x]) continue;
				else if (i == 1 && horizontal_wall[y][x]) continue;
				else if (i == 2 && vertical_wall[y][nx]) continue;
				else if (i == 3 && vertical_wall[y][x]) continue;
				vis[ny][nx] = dist;
				level[ny * garo + nx] = dist;
				parent[ny * garo + nx][0] = y * garo + x;
				tmp.push_back({ ny, nx });
			}
		}
		if (dq.empty()) {
			dist++;
			swap(dq, tmp);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> sero >> garo >> T;
	for (int i = 0; i < sero - 1; i++) {
		for (int j = 0; j < garo; j++) {
			int p; cin >> p;
			if (!p) continue;
			horizontal_wall[i][j] = true;
		}
	}
	for (int i = 0; i < sero; i++) {
		for (int j = 0; j < garo - 1; j++) {
			int p; cin >> p;
			if (!p) continue;
			vertical_wall[i][j] = true;
		}
	}
	bfs();
	for (int i = 1; i < DEPTH; i++) {
		for (int j = 0; j < sero * garo; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		int s, e, sy, sx, ey, ex, w;
		cin >> s >> e >> sy >> sx >> ey >> ex >> w;
		int U = sy * garo + sx, V = ey * garo + ex;
		int u = U, v = V;
		if (level[u] > level[v]) swap(u, v);
		int gap = level[v] - level[u];
		for (int i = DEPTH - 1; i >= 0; i--) {
			if ((1 << i) <= gap && (1 << i) & gap) {
				v = parent[v][i];
			}
		}
		int ancestor;
		if (u == v) ancestor = u;
		else {
			for (int i = DEPTH - 1; i >= 0; i--) {
				if (parent[u][i] != parent[v][i]) {
					u = parent[u][i];
					v = parent[v][i];
				}
			}
			ancestor = parent[u][0];
		}
		int dist = level[U] + level[V] - level[ancestor] * 2 + 1;
		in[s] += dist * w;
		out[e + 1] += dist * w;
	}
	long long cnt = 0;
	for (int i = 1; i <= T; i++) {
		cnt += in[i] - out[i];
		cout << cnt << '\n';
	}
}
