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
    int tot = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tot += x;
    }

    int TOT = tot;

    int s, d;
    cin >> s >> d;

    s %= m;

    for (int i = 1; i <= n; i++) {
        tot += s + i * d;
    }
    cout << tot % m << endl;

    int res = INT_MAX;
    int ans = INT_MAX;
    for (int i = 1; i <= m; i++) {
        int tmp = TOT;

        tmp += n * i + (n * (n - 1)) / 2 * 0;

        if ((tmp % m) < res) {
            res = min(res, tmp % m);
            ans = i;
        }
    }
    cout << res << endl
         << ans << endl;
    cout << m / n << endl;
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