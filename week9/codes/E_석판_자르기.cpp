#include <bits/stdc++.h>
using namespace std;

int N, arr[20][20], jewelrySUM[21][21], impuritySUM[21][21];

int dfs(int x1, int y1, int x2, int y2, int cut) {
    int jewelry = jewelrySUM[y1][x1] + jewelrySUM[y2][x2] - jewelrySUM[y1][x2] - jewelrySUM[y2][x1];
    int impurity = impuritySUM[y1][x1] + impuritySUM[y2][x2] - impuritySUM[y1][x2] - impuritySUM[y2][x1];
    if (!impurity)
        return (jewelry == 1 ? 1 : 0);
    int ret = 0;
    if (cut == 0) {
        for (int i = y1 + 1; i < y2 - 1; i++) {
            int je = jewelrySUM[i][x1] + jewelrySUM[i + 1][x2] - jewelrySUM[i][x2] - jewelrySUM[i + 1][x1];
            int im = impuritySUM[i][x1] + impuritySUM[i + 1][x2] - impuritySUM[i][x2] - impuritySUM[i + 1][x1];
            if (!je && im) {
                int p1 = dfs(x1, y1, x2, i, cut ^ 1);
                if (!p1) continue;
                int p2 = dfs(x1, i + 1, x2, y2, cut ^ 1);
                ret += p1 * p2;
            }
        }
    }
    else {
        for (int i = x1 + 1; i < x2 - 1; i++) {
            int je = jewelrySUM[y1][i] + jewelrySUM[y2][i + 1] - jewelrySUM[y2][i] - jewelrySUM[y1][i + 1];
            int im = impuritySUM[y1][i] + impuritySUM[y2][i + 1] - impuritySUM[y2][i] - impuritySUM[y1][i + 1];
            if (!je && im) {
                int p1 = dfs(x1, y1, i, y2, cut ^ 1);
                if (!p1) continue;
                int p2 = dfs(i + 1, y1, x2, y2, cut ^ 1);
                ret += p1 * p2;
            }
        }
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            jewelrySUM[i][j] = jewelrySUM[i][j - 1];
            impuritySUM[i][j] = impuritySUM[i][j - 1];
            if (arr[i - 1][j - 1] == 1) impuritySUM[i][j]++;
            if (arr[i - 1][j - 1] == 2) jewelrySUM[i][j]++;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            jewelrySUM[j][i] += jewelrySUM[j - 1][i];
            impuritySUM[j][i] += impuritySUM[j - 1][i];
        }
    }
    if (jewelrySUM[N][N] < 2) {
        cout << -1; return 0;
    }
    long long ans = 0;
    ans += dfs(0, 0, N, N, 0);
    ans += dfs(0, 0, N, N, 1);
    cout << (ans ? ans : -1);
}
