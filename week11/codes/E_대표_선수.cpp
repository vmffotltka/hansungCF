#include <bits/stdc++.h>
using namespace std;

int N, M, cnt[1000];
pair<int, int> arr[1000000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int p; cin >> p;
            arr[i * M + j] = { p, i };
        }
    }
    sort(arr, arr + N * M);
    int s = 0, e = 0, ans = INT_MAX, zeros = N;
    while (true) {
        if (zeros) {
            if (e == N * M) break;
            auto [num, idx] = arr[e];
            if (!cnt[idx])
                zeros--;
            cnt[idx]++;
            e++;
        }
        else {
            auto [num, idx] = arr[s];
            if (cnt[idx] == 1)
                zeros++;
            cnt[idx]--;
            auto [num2, idx2] = arr[e - 1];
            ans = min(ans, num2 - num);
            s++;
        }
    }
    cout << ans;
}
