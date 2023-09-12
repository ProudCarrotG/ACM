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
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    int ans = LLONG_MAX;

    vector<pair<int, pair<int, int>>> point(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        point[i].first = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
        point[i].second = {x, y};
    }

    sort(point.begin(), point.end());

    int d2 = 0;
    ans = min(point[n - 1].first, ans);
    for (int i = n - 1; i > 0; i--) {
        d2 = max(d2, (x2 - point[i].second.x) * (x2 - point[i].second.x) + (y2 - point[i].second.y) * (y2 - point[i].second.y));
        ans = min(point[i - 1].first + d2, ans);
    }

    d2 = max(d2, (x2 - point[0].second.x) * (x2 - point[0].second.x) + (y2 - point[0].second.y) * (y2 - point[0].second.y));
    ans = min(d2, ans);
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