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
    int n, m;
    cin >> n >> m;

    int mp[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mp[i][j];

    int ans = n;
    int flag = 1;
    while (flag && n % 2 != 1) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n / 2; j++) {
                if (mp[j][i] != mp[n - 1 - j][i]) {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag)
            n /= 2;
    }
    cout << n << endl;
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