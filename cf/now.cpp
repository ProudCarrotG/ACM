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
    int n, k;
    cin >> n >> k;
    vector<int> edge(n + 1);
    queue<int> q;

    if (k == 1) {
        int flag = 1;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x != i)
                flag = 0;
        }
        if (flag == 0) {
            return cout << "NO" << endl, void();
        } else {
            return cout << "YES" << endl, void();
        }
    }

    for (int i = 1; i <= n; i++) {
        int u = i, v;
        cin >> v;
        edge[i] = v;
    }

    vector<int> vis(n + 1, 0), cnt(n + 1, 0);

    int idx = 1;

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 1) {
            continue;
        }
        int now = i;
        cnt[now] = 1;

        while (1) {
            vis[now] = i;

            if (vis[edge[now]] == i) {
                // cout << "!!!!!!!!!" << cnt[now] - cnt[edge[now]] + 1 << endl;
                if (cnt[now] - cnt[edge[now]] + 1 != k) {
                    return cout << "NO" << endl, void();
                } else {
                    break;
                }
            } else {
                if (vis[edge[now]] == 0) {
                    vis[edge[now]] = i;
                    cnt[edge[now]] = cnt[now] + 1;
                    now = edge[now];
                } else {
                    break;
                }
            }
        }
    }

    cout << "YES" << endl;
    // cout << "----------" << endl;
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