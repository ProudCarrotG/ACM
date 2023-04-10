#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
signed main()
{
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

    int n, m;
    cin >> n >> m;
    vector<int> edge[n + 1];
    vector<int> out(n + 1, 0);

    for (int u, v, i = 1; i <= m; i++)
    {
        cin >> u >> v;
        edge[v].push_back(u);
        out[u]++;
    }

    priority_queue<pair<int, int>> q;
    q.push({0, n});
    vector<int> dis(n + 1, INT_MAX), vis(n + 1, 0);
    dis[n] = 0;

    while (q.size())
    {
        auto u = q.top().second;
        q.pop();

        if (vis[u])
            continue;
        vis[u] = 1;

        for (auto v : edge[u])
        {
            out[v]--;
            int x = out[v] + 1 + dis[u];
            if (dis[v] > x)
            {
                dis[v] = x;
                q.push({-x, v});
            }
        }
    }

    cout << dis[1] << endl;

    return 0;
}