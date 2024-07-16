#include <bits/stdc++.h>
using namespace std;

int N;
double tree[2000], L, W;
double dp[1001][1001], seg;

double dist(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dy * dy + dx * dx);
}

double solve(int left, int right) {
    if (dp[left][right] != -1) return dp[left][right];
    
    double mn = INFINITY;
    int total = left + right;
    if (total == N) return 0.0;
    if (left < N / 2) {
        double leftCost = dist(tree[total], 0, left * seg, 0) + solve(left + 1, right);
        mn = min(mn, leftCost);
    }
    if (right < N / 2) {
        double rightCost = dist(tree[total], 0, right * seg, W) + solve(left, right + 1);
        mn = min(mn, rightCost);
    }
    dp[left][right] = mn;
    return dp[left][right];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(10);
    cout << fixed;
    cin >> N >> L >> W;
    for (int i = 0; i < N; i++)
        cin >> tree[i];
    sort(tree, tree + N);
    seg = L / (N / 2.0 - 1);
    for (int i = 0; i <= N / 2; i++) {
        for (int j = 0; j <= N / 2; j++)
            dp[i][j] = -1;
    }
    cout << solve(0, 0);
}
