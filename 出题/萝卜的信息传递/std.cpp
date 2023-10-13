#include <bits/stdc++.h>
using namespace std;
#define int long long
#define LL long long
#define PII pair<int, int>
#define umap unordered_map
#define x first
#define y second
#define endl "\n"
#ifndef ONLINE_JUDGE
#define debug(x) cout << #x << ' ' << x << endl;
#define fg cout << "-----------------" << endl;
#else
#define debug(x)
#define fg
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n + 1), y(n + 1), r(n + 1);
    vector<double> p(n + 1);
    vector<vector<double>> dis(n + 1, vector<double>(n + 1, LLONG_MAX));
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> r[i] >> p[i];
        dis[i][i] = 0;
    }

    auto reach = [&](int a, int b) {
        double dis = sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
        return (double)r[a] >= dis;
    };

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (reach(i, j) && i != j)
                dis[i][j] = r[i] * p[i];
            // cout << dis[i][j] << ' ';
        }
        // cout << endl;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (dis[i][k] != LLONG_MAX && dis[k][j] != LLONG_MAX)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }

    while (m--) {
        int a, b;
        cin >> a >> b;
        if (dis[a][b] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << dis[a][b] << endl;
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("0.in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

    cout << fixed << setprecision(6);

    int tt = 1;
    //  cin >> tt;
    while (tt--)
        solve();

    return 0;
}