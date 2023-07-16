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
    // 树上两点距离
    int n, st, ed;
    cin >> n >> st >> ed;

    vector<int> edge[n + 1];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    queue<vector<int>> q;
    q.push({st, 0});
    vector<int> vis(n + 1, 0);
    vis[st] = 1;

    int res = INT_MAX;

    while (q.size()) {
        auto x = q.front();
        q.pop();
        int u = x[0];

        if (u == ed) {
            res = min(res, x[1]);
        }

        for (int i = 0; i < edge[u].size(); i++) {
            int v = edge[u][i];

            if (vis[v] == 0) {
                vis[v] = 1;
                q.push({v, x[1] + 1});
            }
        }
    }

    cout << res << endl;
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