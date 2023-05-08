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

    queue<int> q;
    q.push(m);
    while (q.size())
    {
        int now = q.front();
        q.pop();

        if (now == n)
        {
            cout << "YES" << endl;
            return;
        }

        if (now % 2 == 0)
        {
            int next = now + now / 2;
            if (next <= n)
                q.push(next);
        }

        int next = now + now * 2;
        if (next <= n)
            q.push(next);
    }
    cout << "NO" << endl;
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