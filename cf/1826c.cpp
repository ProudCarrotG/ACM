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

    if (n == 1 || m == 1)
    {
        cout << "YES" << endl;
        return;
    }
    if (n > m)
    {
        int flag = 1, tmp = INT_MAX;
        for (int i = 2; i <= sqrt(n) + 1; i++)
            if (n % i == 0)
            {
                flag = 0;
                tmp = i;
                break;
            }
        if (tmp > m)
        {
            cout << "YES" << endl;
            return;
        }
        // cout << tmp << endl;
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