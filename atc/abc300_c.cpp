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
    char mp[105][105];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mp[i][j];

    vector<int> res(min(n, m) + 1);

    auto check = [&](int i, int j, int k) {
        if (0 <= i + k && i + k < n && 0 <= j + k && j + k < m &&
            0 <= i - k && i - k < n && 0 <= j + k && j + k < m &&
            0 <= i + k && i + k < n && 0 <= j - k && j - k < m &&
            0 <= i - k && i - k < n && 0 <= j - k && j - k < m) {
            if (mp[i + k][j + k] == '#' &&
                mp[i + k][j - k] == '#' &&
                mp[i - k][j + k] == '#' &&
                mp[i - k][j - k] == '#') {
                return 1;
            }
        }
        return 0;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == '#') {
                int k = 0;
                for (k = 0; check(i, j, k); k++) {
                    ;
                }
                res[k - 1]++;
            }
        }
    }

    for (int i = 1; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
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