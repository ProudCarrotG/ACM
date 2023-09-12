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
    int mp1[n][n];
    int mp2[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            char x;
            cin >> x;
            mp1[i][j] = mp2[i][j] = x - '0';
        }

    int res1 = 0;
    for (int i = 0; i < n; i++) {
        if (mp1[i][0] == 1) {
            res1++;
            for (int j = 0; j < n; j++)
                mp1[i][j] = !mp1[i][j];
        }
    }

    for (int j = 1; j < n; j++) {
        int tmp = 0;
        for (int i = 0; i < n; i++)
            tmp += mp1[i][j];
        if (tmp == n)
            res1++;
        else if (tmp == 0)
            ;
        else {
            res1 = INT_MAX;
            break;
        }
    }

    int res2 = 0;
    for (int i = 0; i < n; i++) {
        if (mp2[i][0] == 0) {
            res2++;
            for (int j = 0; j < n; j++)
                mp2[i][j] = !mp2[i][j];
        }
    }
    for (int j = 1; j < n; j++) {
        int tmp = 0;
        for (int i = 0; i < n; i++)
            tmp += mp2[i][j];
        if (tmp == 0)
            res2++;
        else if (tmp == n)
            ;
        else {
            res2 = INT_MAX;
            break;
        }
    }

    cout << res1 << ' ' << res2 << endl;
    int res = min(res1, res2);
    if (res == INT_MAX)
        cout << -1 << endl;
    else
        cout << res << endl;
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