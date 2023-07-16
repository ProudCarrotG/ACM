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
    vector<pair<int, int>> edge[n + 1];

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back({v, i});
        edge[v].push_back({u, i});
    }

    vector<int> visv(n + 1);
    vector<int> vise(m + 1);
    
    for (int x = 1; x <= n; x++) {
        if (visv[x] == 1)
            continue;

        int cntv = 1, cnte = 0;
        queue<int> q;
        q.push(x);
        visv[x] = 1;

        while (q.size()) {
            int u = q.front();
            q.pop();

            for (int i = 0; i < edge[u].size(); i++) {
                int v = edge[u][i].first;
                int p = edge[u][i].second;

                if (vise[p] == 0) {
                    vise[p] = 1;
                    cnte++;
                }
                if (visv[v] == 0) {
                    visv[v] = 1;
                    cntv++;
                    q.push(v);
                }
            }
        }

        if (cntv != cnte) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
    return;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

    int tt = 1;
    //  cin >> tt;
    while (tt--)
        solve();

    return 0;
}