#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int parent[500001], pre[500001], arr[500000];
bool selected[500001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    memset(pre, -1, sizeof(pre));
    for (int i = 0; i < k; i++) {
        parent[i] = k;
        cin >> arr[i];
        if (pre[arr[i]] != -1)
            parent[pre[arr[i]]] = i;
        pre[arr[i]] = i;
    }
    int cnt = 0, ans = 0;
    priority_queue<pii> pq;
    for (int i = 0; i < k; i++) {
        if (!selected[arr[i]]) {
            if (cnt < n)
                cnt++;
            else {
                selected[pq.top().second] = false;
                pq.pop();
                ans++;
            }
            selected[arr[i]] = true;
        }
        pq.push({ parent[i], arr[i] });
    }
    cout << ans;
}
