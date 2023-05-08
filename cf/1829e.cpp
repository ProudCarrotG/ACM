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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void solve()
{
    int n, m;
    cin >> n >> m;
    int mp[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mp[i][j];

    int vis[n][m];
    memset(vis, 0, sizeof vis);

    int ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int res = 0;
            if (vis[i][j] == 0 && mp[i][j] != 0)
            {
                queue<PII> q;
                q.push({i, j});
                vis[i][j] = 1;
                res += mp[i][j];

                while (q.size())
                {
                    auto now = q.front();
                    q.pop();

                    for (int i = 0; i < 4; i++)
                    {
                        PII next = {now.x + dx[i], now.y + dy[i]};
                        if (0 <= next.x && next.x < n)
                            if (0 <= next.y && next.y < m)
                                if (vis[next.x][next.y] == 0)
                                    if (mp[next.x][next.y] != 0)
                                    {
                                        q.push(next);
                                        res += mp[next.x][next.y];
                                        vis[next.x][next.y] = 1;
                                    }
                    }
                }
            }

            ans = max(ans, res);
        }

    cout << ans << endl;
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