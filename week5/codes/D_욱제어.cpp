#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, idx = 0;
pii len[1000];
string ans[1000], s = "";

void dfs(int depth) {
    if (idx == N) return;
    if (len[idx].first == depth) {
        ans[len[idx++].second] = s;
        return;
    }
    s += '0';
    dfs(depth + 1);
    s.pop_back();
    s += '1';
    dfs(depth + 1);
    s.pop_back();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> len[i].first;
        len[i].second = i;
    }
    sort(len, len + N);
    dfs(0);
    if (idx != N) cout << -1;
    else {
        cout << 1 << '\n';
        for (int i = 0; i < N; i++) {
            cout << ans[i] << '\n';
        }
    }
}
