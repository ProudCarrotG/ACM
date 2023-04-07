#include <bits/stdc++.h>

using namespace std;

#define int long long

int ans = 0;
map<int, int> mp;
vector<int> edge[400010 + 10];

void dfs(int u)
{
    if (ans >= 1e6)
        return;
    ans++;

    for (int i = 0; i < edge[u].size(); i++)
    {
        int v = edge[u][i];
        if (mp[v] == 0)
        {
            mp[v] = 1;
            dfs(v);
            mp[v] = 0;
        }
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    mp[1] = 1;
    dfs(1);

    cout << ans << endl;

    return 0;
}