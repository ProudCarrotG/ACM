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

    vector<vector<int>> arr(n + 1, vector<int>(m));
    for (int i = 1; i <= n; i++) {
        int cnt = (m - i + m) % m;
        for (int j = 0; j < m; j++) {
            arr[i][j] = cnt % m;
            cnt++;
        }
    }

    if (m == 1)
        cout << 0 << endl;
    else
        cout << min(n + 1, m) << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[min(i, m - 1)][j] << ' ';
        }
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
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}