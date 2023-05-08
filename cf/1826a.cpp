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
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; i++)
        cin >> l[i];

    for (int ans = 0; ans <= n; ans++)
    {
        int tot = 0;
        for (int i = 0; i < n; i++)
        {
            if (l[i] > ans)
                tot++;
        }
        if (tot == ans)
        {
            cout << ans << endl;
            return;
        }
    }

    cout << -1 << endl;
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