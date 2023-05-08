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
    int ans = 0;
    int now = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 0)
            now++;
        else
            now = 0;
        ans = max(ans, now);
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