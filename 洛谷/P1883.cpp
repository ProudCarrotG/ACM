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
    int n;
    cin >> n;
    vector<double> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];

    double l = 0, r = 1000;
    double ans = INT_MAX;

    auto check = [&](double x) {
        double res = INT_MIN;
        for (int i = 0; i < n; i++) {
            res = max(res, a[i] * x * x + b[i] * x + c[i]);
        }
        ans = min(ans, res);
        return res;
    };

    while (r - l >= 1e-8) {
        double lmid = (l + r) / 2;
        double rmid = (lmid + r) / 2;

        if (check(lmid) < check(rmid)) {
            r = rmid;
        } else {
            l = lmid;
        }
        // cout<<l<<' '<<r<<endl;
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
    cout << fixed << setprecision(4);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}