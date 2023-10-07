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

int mode = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;

    int dp[n + 2][m + 2];
    memset(dp, 0, sizeof dp);

    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = i + 1; k <= n; k++)
                for (int l = j + 1; l <= m; l++) {
                    if (k - i == 1 || (l - j) % (k - i) != 0) {
                        dp[k][l] = (dp[k][l] + dp[i][j]) % mode;
                    }
                }

            // cout << i << ' ' << j << endl;
            // for (int I = 0; I <= n; I++) {
            //     for (int J = 0; J <= m; J++) {
            //         cout << dp[I][J] << ' ';
            //     }
            //     cout << endl;
            // }
            // cout << "------------------" << endl;
        }
 
    }

    cout << dp[n][m] << endl;
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