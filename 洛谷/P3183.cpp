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
    vector<int> edge[n + 1], cnt(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        cnt[v]++;
    }

    queue<int> q;
    vector<int> vis(n + 1), res(n + 1);
    for (int i = 1; i <= n; i++)
        if (cnt[i] == 0 && edge[i].size() != 0) {
            res[i] = 1;
            q.push(i);
        }

    while (q.size()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < edge[now].size(); i++) {
            int next = edge[now][i];
            res[next] += res[now];
            cnt[next]--;
            if (cnt[next] == 0)
                q.push(next);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (edge[i].size() == 0)
            ans += res[i];

    cout << ans << endl;
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
    //  cin >> tt;`
    while (tt--)
        solve();

    return 0;
}