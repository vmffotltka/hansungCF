#include <bits/stdc++.h>
using namespace std;

int vis[50][50];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t; while (t--) {
        memset(vis, 0, sizeof(vis));
        int X, Y, x, y, cnt = 0; cin >> X >> Y >> x >> y;
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                if (vis[i][j] == -1) continue;
                vis[i][j] = 1;
                cnt++;
                if (i + y < Y && j + x < X)
                    vis[i + y][j + x] = -1;
            }
        }
        cout << cnt << '\n';
    }
}
