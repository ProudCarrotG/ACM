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

void solve() {
    int n, m;
    cin >> n >> m;

    char mp[n + 2][m + 2];

    queue<PII> q;
    int vis[n + 2][m + 2];
    memset(vis, 0, sizeof vis);
    // int nx[n + 2][m + 2], ny[n + 2][m + 2];
    // memset(nx, 1, sizeof nx);
    // memset(ny, 1, sizeof ny);
    vector<vector<int>> nx(n + 2, vector<int>(m + 2, 1));
    vector<vector<int>> ny(n + 2, vector<int>(m + 2, 1));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            // if (mp[i][j] == '#')
            //     q.push({i, j});
        }

    int ans = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == '#' && vis[i][j] == 0) {
                q.push({i, j});
                vis[i][j] = 1;
                while (q.size()) {
                    auto now = q.front();
                    q.pop();

                    // if (vis[now.x][now.y] == 1)
                    //     continue;
                    // vis[now.x][now.y] = 1;

                    ans += nx[now.x][now.y] * nx[now.x][now.y];
                    ans += ny[now.x][now.y] * ny[now.x][now.y];

                    cout << ans << ' ' << now.x << ' ' << now.y << endl;

                    for (int i = 0; i < 4; i++) {
                        PII next = {now.x + dx[i], now.y + dy[i]};
                        if (vis[next.x][next.y] == 0) {
                            if (mp[next.x][next.y] == '#') {
                                q.push(next);
                                vis[next.x][next.y] = 1;

                                if (i == 1 || i == 3)
                                    nx[next.x][next.y] += nx[now.x][now.y];
                                else
                                    ny[next.x][next.y] += ny[now.x][now.y];
                            }
                        }
                    }
                }
            }
        }

    cout << ans << endl;
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