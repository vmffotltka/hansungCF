#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int xy, left, right;
    bool operator<(const Edge& other) const {
        if (xy != other.xy) return xy < other.xy;
        if (left != other.left) return left < other.left;
        return right < other.right;
    }
};

map<Edge, int> xDP[31], yDP[31];

int dfs(int depth, int len, int x1, int x2, int y1, int y2) {
    if (len == 2) {
        if (y2 == -1) {
            if (y1 == 1) return (x2 - x1 == 2 ? 2 : 1);
            else return 0;
        }
        else {
            if (x1 == 1) return (y1 == 0 ? 1 : 0);
            else return 0;
        }
    }
    if (y2 == -1 && xDP[depth][{y1, x1, x2}])
        return xDP[depth][{y1, x1, x2}];
    else if (x2 == -1 && yDP[depth][{x1, y1, y2}])
        return yDP[depth][{x1, y1, y2}];
    int way1 = 0, way2 = 0;
    if (y2 == -1) {
        if (y1 == len / 2) {
            if (0 < x1 && x2 < len) way1 = 0;
            else if (x1 == 0 && x2 == len) way1 = 2;
            else way1 = 1;
        }
        else if (y1 < len / 2) {
            if (x1 < len / 2 && len / 2 < x2) {
                way1 = dfs(depth - 1, len / 2, x1, len / 2, y1, -1);
                way2 = dfs(depth - 1, len / 2, 0, x2 - len / 2, y1, -1);
            }
            else if (len / 2 <= x1)
                way1 = dfs(depth - 1, len / 2, x1 - len / 2, x2 - len / 2, y1, -1);
            else
                way1 = dfs(depth - 1, len / 2, x1, x2, y1, -1);
        }
        else {
            if (x1 < len / 2 && len / 2 < x2) {
                way1 = dfs(depth - 1, len / 2, y1 - len / 2, -1, 0, len / 2 - x1);
                way2 = dfs(depth - 1, len / 2, len - y1, -1, 0, x2 - len / 2);
            }
            else if (len / 2 <= x1)
                way1 = dfs(depth - 1, len / 2, len - y1, -1, x1 - len / 2, x2 - len / 2);
            else
                way1 = dfs(depth - 1, len / 2, y1 - len / 2, -1, len / 2 - x2, len / 2 - x1);
        }
        xDP[depth][{y1, x1, x2}] = way1 + way2;
    }
    else {
        if (x1 == len / 2) {
            if (len / 2 <= y1 || y2 < len / 2) way1 = 0;
            else way1 = 1;
        }
        else if (x1 < len / 2) {
            if (y1 < len / 2 && len / 2 < y2) {
                way1 = dfs(depth - 1, len / 2, x1, -1, y1, len / 2);
                way2 = dfs(depth - 1, len / 2, 0, y2 - len / 2, len / 2 - x1, -1);
            }
            else if (len / 2 <= y1)
                way1 = dfs(depth - 1, len / 2, y1 - len / 2, y2 - len / 2, len / 2 - x1, -1);
            else
                way1 = dfs(depth - 1, len / 2, x1, -1, y1, y2);
        }
        else {
            if (y1 < len / 2 && len / 2 < y2) {
                way1 = dfs(depth - 1, len / 2, x1 - len / 2, -1, y1, len / 2);
                way2 = dfs(depth - 1, len / 2, len - y2, len / 2, x1 - len / 2, -1);
            }
            else if (len / 2 <= y1)
                way1 = dfs(depth - 1, len / 2, len - y2, len - y1, x1 - len / 2, -1);
            else
                way1 = dfs(depth - 1, len / 2, x1 - len / 2, -1, y1, y2);
        }
        yDP[depth][{x1, y1, y2}] = way1 + way2;
    }
    return way1 + way2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    while (true) {
        int n, x1, x2, y, len = 1;
        cin >> n;
        if (!n) break;
        cin >> x1 >> x2 >> y;
        for (int i = 0; i < n; i++)
            len *= 2;
        cout << dfs(n, len, x1, x2, y, -1) << '\n';
    }
}
