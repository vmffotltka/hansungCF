#include <bits/stdc++.h>
using namespace std;

int M, N, mn, arr[20];

vector<int> ans, tmp;

void dfs(int b, int idx) {
    if (b == (1 << M) - 1) {
        if (mn > tmp.size()) {
            mn = tmp.size();
            ans = tmp;
        }
        return;
    }
    for (int i = idx; i < N; i++) {
        tmp.push_back(i);
        dfs(b | arr[i], i + 1);
        tmp.pop_back();
    }
}

vector<int> split(string s) {
    vector<int> tokens;
    istringstream iss(s);
    string token;
    while (iss >> token)
        tokens.push_back(stoi(token) - 1);
    return tokens;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int test = 1; test <= t; test++) {
        cin >> M >> N;
        cin.ignore();
        for (int i = 0; i < N; i++) {
            string s; getline(cin, s);
            int bit = 0;
            vector<int> sp = split(s);
            for (auto p : sp)
                bit += (1 << p);
            arr[i] = bit;
        }
        ans.clear(), tmp.clear();
        mn = INT_MAX;
        dfs(0, 0);
        cout << "Data Set " << test << ": ";
        for (auto i : ans)
            cout << static_cast<char>(i + 'A') << " ";
        if (test != t)
            cout << "\n\n";
    }
}
