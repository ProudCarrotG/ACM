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

int max(int a, int b, int c)
{
    return max(a, max(b, c));
}
int min(int a, int b, int c)
{
    return min(a, min(b, c));
}

void solve()
{
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<pair<int, int>> tmp(3);
    tmp[0] = {b[0], 0}, tmp[1] = {b[1], 1}, tmp[2] = {b[2], 2};
    sort(tmp.begin(), tmp.end());

    int ans = tmp[0].x + tmp[1].x + tmp[2].x - 2;

    for (int i = 3; i < n; i++)
    {
        if (b[i] > tmp[0].first)
        {
            tmp[0] = {b[i], i};
            sort(tmp.begin(), tmp.end());
            ans = max(ans, tmp[0].x + tmp[1].x + tmp[2].x - (max(tmp[0].y, tmp[1].y, tmp[2].y) - min(tmp[0].y, tmp[1].y, tmp[2].y)));
        }
        else
        {
            int l = 0;
            if (tmp[0].y < tmp[1].y && tmp[0].y < tmp[2].y)
                l = 0;
            if (tmp[1].y < tmp[0].y && tmp[1].y < tmp[2].y)
                l = 0;
            if (tmp[2].y < tmp[0].y && tmp[2].y < tmp[1].y)
                l = 0;

            if (tmp[0].x + tmp[1].x + tmp[2].x - tmp[l].x - (i - tmp[l].y) >= ans)
            {
                ans = tmp[0].x + tmp[1].x + tmp[2].x - tmp[l].x - (i - tmp[l].y);
                tmp[l] = {b[i], i};
            }
        }
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