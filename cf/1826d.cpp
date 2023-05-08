#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> b(n), L(n), R(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int tmp = 0;
    int mx = 1;
    for (int i = 0; i < n; i++)
    {
        mx--;
        L[i] = mx;
        mx = max(mx, b[i]);
    }
    mx = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        mx--;
        R[i] = mx;
        mx = max(mx, b[i]);
    }
    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        res = max(res, L[i] + b[i] + R[i]);
    }
    cout << res << endl;
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