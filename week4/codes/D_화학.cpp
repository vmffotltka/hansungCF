#include <bits/stdc++.h>
using namespace std;

void parsing(string s, map<string, int>& result) {
    int idx = 0, cnt = 0;
    string elem = "";
    stack<pair<string, int>> st;
    while (idx < s.length()) {
        while (idx < s.length() && isalpha(s[idx])) {
            if (isupper(s[idx])) {
                if (elem != "" && cnt) st.push({elem, cnt});
                else if (elem != "" && !cnt) st.push({elem, 1});
                elem = "", cnt = 0;
            }
            elem += s[idx++];
        }
        while (idx < s.length() && isdigit(s[idx])) {
            cnt *= 10;
            cnt += s[idx++] - '0';
        }
        if (s[idx] == '(' || s[idx] == ')') {
            if (elem != "") {
                if (cnt) st.push({ elem, cnt });
                else st.push({ elem, 1 });
                elem = "", cnt = 0;
            }
            if (s[idx] == '(') {
                st.push({ "(", -1 });
                idx++;
            }
            else {
                idx++;
                int mul = 0;
                while (idx < s.length() && isdigit(s[idx])) {
                    mul *= 10;
                    mul += s[idx++] - '0';
                }
                mul = (mul ? mul : 1);
                stack<pair<string, int>> tmp;
                while (st.top().first != "(") {
                    tmp.push({ st.top().first, st.top().second * mul });
                    st.pop();
                }
                st.pop();
                while (!tmp.empty()) {
                    st.push(tmp.top());
                    tmp.pop();
                }
            }
        }
    }
    if (elem != "" && cnt) st.push({ elem, cnt });
    else if (elem != "" && !cnt) st.push({ elem, 1 });
    while (!st.empty()) {
        result[st.top().first] += st.top().second;
        st.pop();
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    while (cin >> s) {
        map<string, int> result;
        parsing(s, result);
        auto it = result.begin();
        for (it; it != result.end(); it++) {
            auto [elem, count] = *it;
            if (count == 1)
                cout << elem;
            else
                cout << count << elem;
            if (next(it) != result.end())
                cout << "+";
        }
        cout << '\n';
    }
}
