#include <bits/stdc++.h>
using namespace std;

int N, K, arr[1000], vis[1000001];
deque<int> dq;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    dq.push_back(0);
    cin >> K;
    while (K--) {
        deque<int> tmp;
        while (!dq.empty()) {
            int p = dq.front(); dq.pop_front();
            for (int i = 0; i < N; i++) {
                if (vis[p + arr[i]]) continue;
                vis[p + arr[i]]++;
                tmp.push_back(p + arr[i]);
            }
        }
        swap(dq, tmp);
    }
    for (int i = 1; i <= 1000000; i++) {
        if (vis[i]) continue;
        cout << (i & 1 ? "jjaksoon" : "holsoon") << " win at " << i;
        return 0;
    }
}
