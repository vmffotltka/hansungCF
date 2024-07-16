#include <bits/stdc++.h>
using namespace std;

long long N, Q, man1[200000], man2[200000], sumDist1[200000], sumDist2[200000];
pair<int, int> dist[200000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 0; i < N; i++)
        cin >> dist[i].second >> dist[i].first;
    sort(dist, dist + N);
    for (int i = 0; i < N; i++) {
        man1[i] = (!i ? dist[i].second : man1[i - 1] + dist[i].second);
        sumDist1[i] = (!i ? 0 : sumDist1[i - 1] + (dist[i].first - dist[i - 1].first) * man1[i - 1]);
    }
    for (int i = N - 1; i >= 0; i--) {
        man2[i] = (i == N - 1 ? dist[i].second : man2[i + 1] + dist[i].second);
        sumDist2[i] = (i == N - 1 ? 0 : sumDist2[i + 1] + (dist[i + 1].first - dist[i].first) * man2[i + 1]);
    }
    while (Q--) {
        long long p; cin >> p;
        int idx = lower_bound(dist, dist + N, pair<int, int>(p, 0)) - dist;
        if (dist[idx].first == p) {
            cout << sumDist1[idx] + sumDist2[idx] << '\n';
        }
        else if (idx == 0) {
            cout << sumDist2[0] + man2[0] * (dist[0].first - p) << '\n';
        }
        else if (idx == N) {
            cout << sumDist1[N - 1] + man1[N - 1] * (p - dist[N - 1].first) << '\n';
        }
        else {
            long long p1 = sumDist1[idx - 1] + man1[idx - 1] * (p - dist[idx - 1].first);
            long long p2 = sumDist2[idx] + man2[idx] * (dist[idx].first - p);
            cout << p1 + p2 << '\n';
        }
    }
}
