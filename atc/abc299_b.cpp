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
    int n, t;
    cin >> n >> t;
    int ans = 0;
    vector<int> c(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
        cin >> r[i];

    for (int i = 1; i <= n; i++) {
        if (c[i] == t)
            if (r[ans] < r[i])
                ans = i;
    }

    if (ans == 0)
        t = c[1];

    for (int i = 1; i <= n; i++) {
        if (c[i] == t)
            if (r[ans] < r[i])
                ans = i;
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