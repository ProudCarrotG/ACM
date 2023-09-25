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
    int n, k, x;
    cin >> n >> k >> x;

    int res = 0;

    if (x < k - 1) {
        cout << -1 << endl;
        return;
    }

    int cnt = 0;
    for (int i = 0; i < k; i++) {
        res += i;
        cnt++;
    }

    if (cnt > n) {
        cout << -1 << endl;
        return;
    }

    if (x != k)
        cout << res + x * (n - cnt) << endl;
    else
        cout << res + (x - 1) * (n - cnt) << endl;
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