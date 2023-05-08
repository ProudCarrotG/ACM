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
    map<string, int> mp;
    // mp["00"] = INT_MAX;
    mp["10"] = INT_MAX;
    mp["01"] = INT_MAX;
    mp["11"] = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        string s;
        cin >> s;
        mp[s] = min(mp[s], x);
    }
    int ans = min(mp["10"] + mp["01"], mp["11"]);
    // cout << min(mp["10"] + mp["01"], mp["11"]) << endl;
    if (ans != INT_MAX)
        cout << ans << endl;
    else
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