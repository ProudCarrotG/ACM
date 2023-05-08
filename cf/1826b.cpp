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
    int ans = 0;
    // cout << __gcd(0, 10);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int flag = 1;
    for (int i = 0, j = n - 1; i < n && j >= 0; i++, j--)
    {
        if (a[i] != a[j])
        {
            flag = 0;
            if (a[i] - a[j] != 0)
                ans = __gcd(ans, abs(a[i] - a[j]));
        }
    }
    if (flag == 1)
    {
        cout << 0 << endl;
        return;
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