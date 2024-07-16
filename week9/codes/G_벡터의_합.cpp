#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y, idx, cmd;
    bool const operator <(Point a) {
        return (x == a.x ? y < a.y : x < a.x);
    }
};

int N;
Point arr[100000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y, cmd; cin >> x >> y;
        if (x < 0 && y < 0) cmd = 4;
        else if (y < 0) cmd = 3;
        else if (x < 0) cmd = 2;
        else cmd = 1;
        arr[i] = { abs(x), abs(y), i + 1, cmd };
    }
    sort(arr, arr + N);
    int dist = INT_MAX;
    Point a, b;
    for (int i = 1; i < N; i++) {
        for (int j = i - 1; j >= 0; j--) {
            int dx = arr[i].x - arr[j].x, dy = arr[i].y - arr[j].y;
            if (dx * dx > dist) break;
            int cur = dx * dx + dy * dy;
            if (dist > cur) {
                dist = cur;
                a = arr[i], b = arr[j];
            }
        }
    }
    cout << a.idx << " " << 5 - a.cmd << " " << b.idx << " " << b.cmd;
}
