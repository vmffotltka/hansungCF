#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll sero, garo, Sx, Sy, Dx, Dy, Cost[51][51];
ll dy[4] = { 1, -1, 0, 0 };
ll dx[4] = { 0, 0, 1, -1 };
pair<ll, ll> Dist[51][51];

struct Edge {
    ll bunja, bunmo, y, x;
    bool operator<(Edge other) const {
        return bunja * other.bunmo > bunmo * other.bunja;
    }
};

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

void dijk() {
    priority_queue<Edge> pq;
    pq.push({ Dist[Sy][Sx].first, Dist[Sy][Sx].second, Sy, Sx });
    while (!pq.empty()) {
        auto [nowBJ, nowBM, y, x] = pq.top(); pq.pop();
        if (nowBJ * Dist[y][x].second > nowBM * Dist[y][x].first)
            continue;
        for (ll i = 0; i < 4; i++) {
            ll ny = y + dy[i], nx = x + dx[i];
            if (1 <= ny && ny <= sero && 1 <= nx && nx <= garo && Cost[ny][nx] > 1) {
                ll nextBJ, nextBM, nextCost = Cost[ny][nx];
                nextBJ = nowBJ * nextCost + nowBM;
                nextBM = nowBM * nextCost;
                ll time1 = nowBJ / nowBM + (nowBJ % nowBM ? 1 : 0);
                ll time2 = nextBJ / nextBM + (nextBJ % nextBM ? 1 : 0);
                if (time1 < time2) {
                    nextBM = nextCost * Cost[y][x];
                    nextBJ = nextBM * time1 + nextCost + Cost[y][x];
                }
                ll g = gcd(nextBJ, nextBM);
                nextBJ /= g, nextBM /= g;
                if (!Dist[ny][nx].second || nextBJ * Dist[ny][nx].second < nextBM * Dist[ny][nx].first) {
                    Dist[ny][nx] = { nextBJ, nextBM };
                    pq.push({ nextBJ, nextBM, ny, nx });
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t; cin >> t; while (t--) {
        cin >> sero >> garo;
        memset(Cost, 0, sizeof(Cost));
        memset(Dist, 0, sizeof(Dist));
        for (ll i = 1; i <= sero; i++) {
            string s; cin >> s;
            for (ll j = 1; j <= garo; j++) {
                Cost[i][j] = s[j - 1] - '0';
            }
        }
        cin >> Sy >> Sx >> Dy >> Dx;
        ll cost = Cost[Sy][Sx];
        if (Sy == Dy && Sx == Dx) {
            cout << 0 << '\n';
            continue;
        }
        if (cost <= 1) {
            cout << "-1\n";
            continue;
        }
        Dist[Sy][Sx] = { 1, cost };
        dijk();
        ll ansBunja = Dist[Dy][Dx].first, ansBunmo = Dist[Dy][Dx].second;
        cout << (ansBunmo ? ansBunja / ansBunmo + (ansBunja % ansBunmo ? 1 : 0) : -1) << '\n';
    }
}
