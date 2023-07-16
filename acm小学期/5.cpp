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
    int n, x;
    cin >> n >> x;
    vector<int> edge[n + 1];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    vector<int> depth(n + 1, -1);
    depth[1] = 0;
    queue<int> q;
    q.push(1);

    int res = 0;
    vector<int> vis(n + 1);
    vis[x] = 1;

    while (q.size()) {
        int u = q.front();
        q.pop();

        if (vis[u] == 1 && edge[u].size() == 1 && u != 1)
            res++;

        for (int i = 0; i < edge[u].size(); i++) {
            int v = edge[u][i];
            if (depth[v] == -1) {
                if (vis[u] == 1) {
                    vis[v] = 1;
                }
                depth[v] = depth[u] + 1;
                q.push(v);
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