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
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    vector<PII> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    int adis = LLONG_MAX / 2, bdis = LLONG_MAX / 2;
    for (int i = 1; i <= k; i++) {
        adis = min(adis, abs(p[i].x - p[a].x) + abs(p[i].y - p[a].y));
        bdis = min(bdis, abs(p[i].x - p[b].x) + abs(p[i].y - p[b].y));
    }

    // cout << adis << ' ' << bdis << endl;
    cout << min(abs(p[a].x - p[b].x) + abs(p[a].y - p[b].y), adis + bdis) << endl;
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