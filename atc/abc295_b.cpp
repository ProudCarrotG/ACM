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

signed main()
{
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

    int r, c;
    cin >> r >> c;
    char mp[r][c];
    struct node
    {
        int x, y, k;
    };
    queue<node> q;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            cin >> mp[i][j];
            if ('0' <= mp[i][j] && mp[i][j] <= '9')
                q.push({i, j, mp[i][j]});
        }

    while (q.size())
    {
        auto now = q.front();
        q.pop();

        int k = now.k - '0';
        for (int i = -k; i <= k; i++)
        {
            for (int j = -k; j <= k; j++)
            {
                if (abs(i) + abs(j) <= k)
                    if (0 <= now.x + i && now.x + i < r)
                        if (0 <= now.y + j && now.y + j < c)
                            mp[now.x + i][now.y + j] = '.';
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << mp[i][j];
        cout << endl;
    }

    return 0;
}