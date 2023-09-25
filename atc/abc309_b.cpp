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
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            mp1[i][j] = c - '0';
        }

    int mp2[n][n];
    for (int i = 1; i < n - 1; i++)
        for (int j = 1; j < n - 1; j++) {
            mp2[i][j] = mp1[i][j];
        }

    for (int i = 0; i + 1 < n; i++)
        mp2[0][i + 1] = mp1[0][i];

    for (int i = 0; i + 1 < n; i++)
        mp2[i + 1][n - 1] = mp1[i][n - 1];

    for (int i = n - 1; i - 1 >= 0; i--)
        mp2[n - 1][i - 1] = mp1[n - 1][i];

    for (int i = n - 1; i - 1 >= 0; i--)
        mp2[i - 1][0] = mp1[i][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mp2[i][j];
        cout << endl;
    }
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