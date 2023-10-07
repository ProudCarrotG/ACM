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

int n, m;
int mp[10][10];
int vis[10][10];
int ans, res;
int dx[9] = {1, 1, 0, -1, -1, -1, 0, 1, 0};
int dy[9] = {0, 1, 1, 1, 0, -1, -1, -1, 0};

void dfs(int x, int y) {
    if (y > m) {
        dfs(x + 1, 1);
        return;
    }
    if (x > n) {
        res = max(res, ans);
        return;
    }

    dfs(x, y + 1);

    if (vis[x][y] == 0) {
        for (int i = 0; i < 8; i++) {
            vis[x + dx[i]][y + dy[i]]++;
        }
        ans += mp[x][y];

        dfs(x, y + 1);

        ans -= mp[x][y];
        for (int i = 0; i < 8; i++) {
            vis[x + dx[i]][y + dy[i]]--;
        }
    }
}

void solve() {
    cin >> n >> m;
    memset(mp, 0, sizeof mp);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];

    memset(vis, 0, sizeof vis);

    ans = 0;
    res = INT_MIN;
    dfs(1, 1);
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
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}