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
    vector<vector<int>> arr(n,vector<int>(4));
    for (int i = 0; i < n; i++)
        cin >> arr[i][1] >> arr[i][2] >> arr[i][3];

    vector<vector<int>> dp(n,vector<int>(4));

    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    dp[0][3] = arr[0][3];

    for (int i = 1; i < n; i++) {
        dp[i][1] = max(dp[i - 1][2], dp[i - 1][3]) + arr[i][1];
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][3]) + arr[i][2];
        dp[i][3] = max(dp[i - 1][1], dp[i - 1][2]) + arr[i][3];
    }


    cout << max({dp[n - 1][1], dp[n - 1][2], dp[n - 1][3]}) << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("10.in", "r", stdin);
    freopen("10.out","w",stdout);
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