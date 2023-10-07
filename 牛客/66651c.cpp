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
    int ans = 0;
    int x11, y11, x12, y12;
    cin >> x11 >> y11 >> x12 >> y12;
    ans += abs(x11 - x12) * abs(y11 - y12);

    int x21, y21, x22, y22;
    cin >> x21 >> y21 >> x22 >> y22;
    ans += abs(x21 - x22) * abs(y21 - y22);

    int x31, y31, x32, y32;
    cin >> x31 >> y31 >> x32 >> y32;
    ans += abs(x31 - x32) * abs(y31 - y32);

    int tmpx1 = max(x11, x21), tmpy1 = max(y11, y21);
    int tmpx2 = min(x12, x22), tmpy2 = min(y12, y22);
    ans -= max(0ll, tmpx2 - tmpx1) * max(0ll, tmpy2 - tmpy1);

    tmpx1 = max(x11, x31), tmpy1 = max(y11, y31);
    tmpx2 = min(x12, x32), tmpy2 = min(y12, y32);
    ans -= max(0ll, tmpx2 - tmpx1) * max(0ll, tmpy2 - tmpy1);

    tmpx1 = max(x21, x31), tmpy1 = max(y21, y31);
    tmpx2 = min(x22, x32), tmpy2 = min(y22, y32);
    ans -= max(0ll, tmpx2 - tmpx1) * max(0ll, tmpy2 - tmpy1);

    tmpx1 = max({x11, x21, x31}), tmpy1 = max({y11, y21, y31});
    tmpx2 = min({x12, x22, x32}), tmpy2 = min({y12, y22, y32});
    ans += max(0ll, tmpx2 - tmpx1) * max(0ll, tmpy2 - tmpy1);

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