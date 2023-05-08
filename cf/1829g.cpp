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

// vector<int> mp[2000];
// vector<int> ans[2000];
int mp[3000][3000];
int ans[3000][3000];

void solve()
{
    int n;
    cin >> n;

    int r, l;
    for (int i = 1; i < 2000; i++)
    {
        if (mp[i][1] <= n && n < mp[i + 1][1])
        {
            r = i;
            break;
        }
    }
    for (int i = 1;; i++)
    {
        if (mp[r][i] == n)
        {
            l = i;
            break;
        }
    }

    cout << r << ' ' << l << endl;
    cout << ans[r][l] << endl;

    // cout << "------" << endl;
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

    int idx = 1;
    for (int i = 1; i <= 2050; i++)
        for (int j = 1; j <= i; j++)
        {
            mp[i][j] = idx;
            idx++;
        }

    for (int i = 2050; i <= 2050; i++)
        for (int j = 1; j <= i; j++)
        {
        }

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
    int tt;
    cin >> tt;

    while (tt--)
        solve();

    return 0;
}