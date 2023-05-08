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

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> edge[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[v].push_back(u);
        edge[u].push_back(v);
    }

    vector<int> point(n + 1, -1);
    int mid = -1, edg = -1;

    for (int i = 1; i <= n; i++)
    {
        if (edge[i].size() == 1)
        {
            point[i] = 0;
            point[edge[i][0]] = 1;
            edg = edge[i][0];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (point[i] == 1)
        {
            for (int j = 0; j < edge[i].size(); j++)
            {
                int v = edge[i][j];
                if (point[v] == -1)
                {
                    mid = v;
                    cout << edge[mid].size() << ' ' << edge[edg].size() - 1 << endl;
                    return;
                }
            }
        }
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

    int tt;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}