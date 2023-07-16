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

    vector<int> edge[n + 1];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    int k;
    cin >> k;
    vector<int> p, d;
    for (int i = 0, x, y; i < k; i++) {
        cin >> x >> y;
        p.push_back(x);
        d.push_back(y);
    }

    vector<int> col(n + 1, 1);
    for (int I = 0; I < k; I++) {
        int st = p[I];
        int dis = d[I];

        vector<int> vis(n + 1, 0);
        queue<vector<int>> q;
        q.push({st, dis - 1});
        while (q.size()) {
            auto x = q.front();
            q.pop();

            int u = x[0];
            vis[u] = 1;
            if (x[1] < 0)
                break;
            col[u] = 0;

            for (int i = 0; i < edge[u].size(); i++) {
                int v = edge[u][i];

                if (vis[v] == 0)
                    if (x[1] > 0) {
                        vis[v] = 1;
                        q.push({v, x[1] - 1});
                    }
            }
        }
    }

    for (int I = 0; I < k; I++) {
        int st = p[I];
        int dis = d[I];
        int cnt = 0;

        vector<int> vis(n + 1, 0);
        queue<vector<int>> q;
        q.push({st, 0});
        while (q.size()) {
            auto x = q.front();
            q.pop();

            if (x[1] > dis)
                break;
            if (x[1] == dis)
                cnt += col[x[0]];

            for (int i = 0; i < edge[x[0]].size(); i++) {
                int v = edge[x[0]][i];

                if (vis[v] == 0)
                    if (x[1] + 1 <= dis) {
                        vis[v] = 1;
                        q.push({v, x[1] + 1});
                    }
            }
        }

        // cout<<st<<' '<<cnt<<endl;

        if(cnt==0)
        {
            cout<<"No"<<endl;
            return;
        }
    }

    cout<<"Yes"<<endl;
    for(int i=1;i<=n;i++)
        cout<<col[i];
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