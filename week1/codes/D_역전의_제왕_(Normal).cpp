#include <bits/stdc++.h>
using namespace std;

struct User {
	int id = 0, solve = 0, pen = 0, submit = 0, idx = 0;
};

bool comp(User a, User b) {
	if (a.solve == b.solve) {
		if (a.pen == b.pen) {
			if (a.submit == b.submit) {
				return a.idx < b.idx;
			}
			else return a.submit < b.submit;
		}
		else return a.pen < b.pen;
	}
	else return a.solve > b.solve;
}

bool comp2(User a, User b) {
	return a.id > b.id;
}

User arr[50];
int ans[50];
bool ac[50][13] = {};
vector<User> R;
vector<User> freeze[51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string st; cin >> st;
		int id, p, s; cin >> id >> p >> s;
		if (ac[id - 1][p - 1]) continue;
		ac[id - 1][p - 1] = true;
		id--;
		int time = (st[1] - '0') * 60 + (st[3] - '0') * 10 + (st[4] - '0');
		if (time <= 180) {
			arr[id].id = id;
			arr[id].idx = i;
			arr[id].pen += time + (s - 1) * 20;
			arr[id].solve++;
			arr[id].submit = time;
		}
		else {
			freeze[id].push_back({ p, 0, time + (s - 1) * 20, time, i });
		}
	}
	for (int i = 0; i < n; i++) {
		sort(freeze[i].begin(), freeze[i].end(), comp2);
		R.push_back(arr[i]);
	}
	sort(R.begin(), R.end(), comp);
	while (true) {
		bool tri2 = true;
		for (int i = n - 1; i >= 0; i--) {
			int cid = R[i].id;
			bool tri = false;
			if (!freeze[cid].empty()) {
				auto &f = freeze[cid].back();
				int pid = f.id, pen = f.pen;
				freeze[cid].pop_back();
				R[i].solve++, arr[cid].solve++;
				R[i].pen += pen, arr[cid].pen += pen;
				R[i].idx = max(arr[cid].idx, f.idx);
				arr[cid].idx = max(arr[cid].idx, f.idx);
				R[i].submit = max(arr[cid].submit, f.submit);
				arr[cid].submit = max(arr[cid].submit, f.submit);
				
				tri = true;
			}
			if (tri) {
				tri2 = false;
				sort(R.begin(), R.end(), comp);
				for (int j = 0; j < n; j++) {
					if (R[j].id == cid) {
						ans[cid] += i - j;
						break;
					}
				}
				break;
			}
		}
		if (tri2) break;
	}
	int mx = 0;
	vector<User> tmp;
	for (int i = 0; i < n; i++) {
		if (mx < ans[i]) {
			mx = ans[i];
			vector<User>().swap(tmp);
			tmp.push_back(arr[i]);
		}
		else if (mx == ans[i]) {
			tmp.push_back(arr[i]);
		}
	}
	sort(tmp.begin(), tmp.end(), comp);
	cout << tmp[0].id + 1;
}
