#include <bits/stdc++.h>
using namespace std;

int arr[5][5];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
set<string> s;
string ans(6, '0');

void dfs(int y, int x, int depth) {
    if (depth == 6) {
        s.insert(ans);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y, nx = dx[i] + x;
        if (0 <= ny && ny < 5 && 0 <= nx && nx < 5) {
            ans[depth] = arr[ny][nx] + '0';
            dfs(ny, nx, depth + 1);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) cin >> arr[i][j];
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            ans[0] = arr[i][j] + '0';
            dfs(i, j, 1);
        }
    }
    cout << s.size();
}
