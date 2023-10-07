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

void solve() {
    int n;
    cin >> n;
    int mp[n + 1][n + 1];
    memset(mp, 0, sizeof mp);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mp[i][j];
            mp[i][j] += mp[i - 1][j] + mp[i][j - 1] - mp[i - 1][j - 1];
            // cout << mp[i][j] << ' ';
        }
        // cout << endl;
    }

    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            for (int k = i; k <= n; k++)
                for (int l = j; l <= n; l++) {
                    ans = max(ans, mp[k][l] - mp[k][j - 1] - mp[i - 1][l] + mp[i - 1][j - 1]);
                }
        }

    cout<<ans<<endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

    int tt = 1;
    //  cin >> tt;
    while (tt--)
        solve();

    return 0;
}