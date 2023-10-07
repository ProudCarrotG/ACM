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
    int a, b, c;
    cin >> a >> b >> c;
    int M[3] = {a, b, c};

    map<vector<int>, bool> vis;
    set<int> ans;
    ans.insert(c);
    queue<vector<int>> q;
    q.push({0, 0, c});
    vis[{0, 0, c}] = 1;

    while (q.size()) {
        auto now = q.front();
        q.pop();

        // cout<<now[0]<<' '<<now[1]<<' '<<now[2]<<endl;

        if (now[0] == 0) {
            ans.insert(now[2]);
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    if (now[i] && now[j] != M[j]) {
                        auto next = now;
                        next[i] = max(0ll, now[i] - (M[j] - now[j]));
                        next[j] = min(M[j], now[j] + now[i]);

                        if (vis[next] == 0) {
                            q.push(next);
                            vis[next] = 1;
                        }
                    }
                }
            }
        }
    }

    for (auto i : ans)
        cout << i << ' ';
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