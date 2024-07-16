#include <bits/stdc++.h>
#define MAX 1048577
using namespace std;

int arr[MAX];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    int gap = n / k, idx = gap;
    while (idx <= n) {
        sort(arr + idx - gap, arr + idx);
        for (int i = idx - gap; i < idx; i++)
            cout << arr[i] << " ";
        idx += gap;
    }
}
