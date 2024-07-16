#include <bits/stdc++.h>
using namespace std;

struct Son {
    int id, dur, time;
};

Son arr[200000];
bool comp(Son a, Son b) {
    return a.time < b.time;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, t, w; cin >> n >> t >> w;
    deque<pair<int, int>> dq;
    for (int i = 0; i < n; i++) {
        int id, t; cin >> id >> t;
        dq.push_back({ id, t });
    }
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int id, t, time; cin >> id >> t >> time;
        arr[i] = { id, t, time };
    }
    sort(arr, arr + m, comp);
    int idx = 0, T = t;
    for (int time = 1; time <= w; time++) {
        cout << dq.front().first << '\n';
        if (arr[idx].time == time) {
            dq.push_back({ arr[idx].id, arr[idx].dur });
            idx++;
        }
        if (!--dq.front().second) {
            dq.pop_front();
            T = t;
        }
        else {
            T--;
            if (!T) {
                dq.push_back(dq.front());
                dq.pop_front();
                T = t;
            }
        }
    }
}
