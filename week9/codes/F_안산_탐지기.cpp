#include <bits/stdc++.h>
using namespace std;

int N, MX;

bool dfs(int start, int gap, bool tri) {
    int battery = (N - start + gap) / (gap * 2), ans;
    cout << "? " << min(N, start + gap) << " " << min(N, gap * 2) << " " << min(N, battery) << endl;
    cin >> ans;
    if (tri) {
        cout << "! " << (ans == MX ? start + gap : start) << endl;
        return true;
    }
    if (ans == MX) {
        if (battery == 1) {
            cout << "! " << start + gap << endl;
            return true;
        }
        int curLen = (N - start + gap) / (gap * 2);
        return dfs(start + gap, gap * 2, (curLen <= 2 ? true : false));
    }
    else {
        int curLen = (N - start + gap * 2) / (gap * 2);
        return dfs(start, gap * 2, (curLen <= 2 ? true : false));
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    cout << "? " << 1 << " " << 1 << " " << N << endl;
    cin >> MX;
    if (N == 1) {
        cout << "! " << 1 << endl;
        return 0;
    }
    dfs(1, 1, (N == 2 ? true : false));
}
