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

const int N = 2e5 + 10;

struct node
{
    int v, id;
};
int n;

vector<int> to(N + 1, 0);
vector<int> sz(N + 1, 0), fa(N + 1, 0), son(N + 1);
vector<node> edge[N + 1];
vector<int> w(N + 1);

void dfs(int u)
{
    sz[u] = 1;
    for (int i = 0; i < edge[u].size(); i++)
    {
        int v = edge[u][i].v;
        if (v == fa[u])
            continue;
        to[edge[u][i].id] = v;
        fa[v] = u;
        dfs(v);
        sz[u] += sz[v];
        if (sz[u] == 0 || sz[v] > sz[son[u]])
            son[u] = v;
    }
}
vector<int> top(N, 0), dfn(N, 0);
int id;
void dfs2(int u, int tp)
{
    top[u] = tp;
    dfn[u] = ++id;
    if (son[u])
        dfs2(son[u], tp);
    for (int i = 0; i < edge[u].size(); i++)
    {
        int v = edge[u][i].v;
        if (v != son[u] && v != fa[u])
            dfs2(v, v);
    }
}

vector<int> c(N, 0);
int lowbit(int x)
{
    return x & -x;
}
void add(int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += v;
}
int sum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += c[i];
    return res;
}
int sum(int l, int r)
{
    return sum(r) - sum(l - 1);
}

int qustion(int u, int v)
{
    int res = 0;
    while (top[u] != top[v])
    {
        if (dfn[u] < dfn[v])
            swap(u, v);
        res += sum(dfn[top[u]], dfn[u]);
        u = fa[top[u]];
    }
    if (dfn[u] < dfn[v])
        swap(u, v);
    res += sum(dfn[v] + 1, dfn[u]);
    return res;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

    cin >> n;

    for (int u, v, i = 1; i < n; i++)
    {
        cin >> u >> v >> w[i];
        edge[u].push_back({v, i});
        edge[v].push_back({u, i});
    }

    dfs(1);
    dfs2(1, 1);
    for (int i = 1; i < n; i++)
        add(dfn[to[i]], w[i]);

    int m;
    cin >> m;
    for (int op, x, y; m--;)
    {
        cin >> op >> x >> y;
        if (op == 1)
        {
            add(dfn[to[x]], y - w[x]);
            w[x] = y;
        }
        else
            cout << qustion(x, y) << endl;
    }

    return 0;
}