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

vector<int> f(1000 * 1000 + 10);

int find(int x) {
    if (f[x] == x)
        return x;
    else
        return f[x] = find(f[x]);
}

void add(int u, int v) {
    f[find(u)] = find(v);
}

void solve() {
    int n, m;
    cin >> n >> m;
    n = n * m;
    int k;
    cin >> k;

    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        // cout<<i<<' '<<find(i)<<endl;
        if (i == find(i))
            res++;
    }
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
    //  cin >> tt;
    while (tt--)
        solve();

    return 0;
}