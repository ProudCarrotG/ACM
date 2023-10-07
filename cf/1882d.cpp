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
vector<int> a;
vector<int> edge[200000 + 1];
int n;
vector<int> son;
vector<int> m;
vector<int> vis;

void dfs(int u, int v) {
    vis[v] = 1;
    son[v] = 1;
    int c = a[u] ^ a[v];
    for (int i = 0; i < edge[v].size(); i++) {
        int next = edge[v][i];
        if (!vis[next]) {
            dfs(v, next);
            son[v] += son[next];
        }
    }
    // cout << u << ' ' << v << ' ' << c << ' ' << son[v] << endl;
    m[1] += son[v] * c;
}

void solve() {
    a.clear();
    son.clear();
    m.clear();
    vis.clear();
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        edge[i].clear();
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    son.resize(n + 1);
    vis.resize(n + 1);
    m.resize(n + 1);
    a[0] = a[1];
    dfs(0, 1);

    // cout<<m[1]<<endl;

    queue<int> q;
    q.push(1);
    vis.clear();
    vis.resize(n + 1);
    while (q.size()) {
        int now = q.front();
        q.pop();
        vis[now] = 1;

        for (int i = 0; i < edge[now].size(); i++) {
            int next = edge[now][i];
            if (!vis[next]) {
                m[next] = m[now] - (son[next] * (a[now] ^ a[next])) + ((son[now] - son[next]) * (a[now] ^ a[next]));
                son[next] = n;
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << m[i] << ' ';
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
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}