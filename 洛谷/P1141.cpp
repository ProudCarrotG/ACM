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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int f[1010][1010];

void solve() {
    int n, m;
    cin >> n >> m;
    // vector<vector<char>> mp(n + 2, vector<char>(n + 2));
    int mp[n + 2][n + 2];
    memset(mp, 0, sizeof mp);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            char x;
            cin >> x;
            // scanf("%c", &x);
            mp[i][j] = x - '0';
        }

    vector<int> ans;
    int vis[n + 2][n + 2];
    memset(f, -1, sizeof f);
    memset(vis, 0, sizeof vis);
    queue<PII> q;
    int idx = 0;
    while (m--) {
        int x, y;
        int res = 1;
        cin >> x >> y;
        if (f[x][y] != -1) {
            // cout << "--------" << endl;
            cout << ans[f[x][y]] << endl;
            continue;
        }

        f[x][y] = idx;
        vis[x][y] = 1;
        q.push({x, y});
        while (q.size()) {
            int x = q.front().x;
            int y = q.front().y;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (1 <= nx && nx <= n && 1 <= ny && ny <= n)
                    if (mp[x][y] + mp[nx][ny] == 1) {
                        if (vis[nx][ny] == 0) {
                            q.push({nx, ny});
                            res++;
                            f[nx][ny] = idx;
                            vis[nx][ny] = 1;
                        }
                    }
            }
        }

        ans.push_back(res);
        idx++;

        cout << res << endl;
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++)
    //         cout << f[i][j] << ' ';
    //     cout << endl;
    // }
    // cout << ans[1] << endl;
}

void solve1234() {
    int n, m;
    cin >> n >> m;
    char x;
    int mp[n + 2][n + 2];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> x;
            mp[i][j] = x - '0';
        }

    int res[n + 2][n + 2];
    memset(res, 0, sizeof res);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (res[i][j] == 0) {
            }
        }
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