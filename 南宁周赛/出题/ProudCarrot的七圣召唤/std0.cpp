#include <bits/stdc++.h>
using namespace std;

#define int long long
int card[100010][20];
int dp[100010][20];

signed main() {
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
    // freopen("F/F/9.out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> card[i][j];

    // cout << "!!!!!!!!!" << endl;
    memset(dp, 0, sizeof dp);
    for (int j = 0; j < m; j++)
        dp[0][j] = 1;

    int mode = 998244353;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                if (card[i][j] != card[i - 1][k])
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mode;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
        ans = (ans + dp[n - 1][i]) % mode;
    cout << ans << endl;

    return 0;
}