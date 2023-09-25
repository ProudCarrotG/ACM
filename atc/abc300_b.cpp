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
    char mp1[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mp1[i][j];

    char mp2[n * 2 + 10][m * 2 + 10];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> mp2[i][j];
            mp2[i + n][j] = mp2[i][j];
            mp2[i][j + m] = mp2[i][j];
            mp2[i + n][j + m] = mp2[i][j];
        }

    // for (int i = 0; i < n * 2; i++) {
    //     for (int j = 0; j < m * 2; j++)
    //         cout << mp2[i][j];
    //     cout << endl;
    // }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int flag = 1;
            for (int k = 0; k < n; k++)
                for (int l = 0; l < m; l++) {
                    if (mp2[i + k][j + l] != mp1[k][l])
                        flag = 0;
                }
            if (flag == 1) {
                cout << "Yes" << endl;
                return;
            }
        }

    cout << "No" << endl;
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