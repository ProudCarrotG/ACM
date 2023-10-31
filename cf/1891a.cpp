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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int m = 1; pow(2, m - 1) <= n; m++) {
        int last = -1;
        for (int i = pow(2, m - 1) + 1; i <= min(n, (LL)pow(2, m)); i++) {
            if (last > a[i]) {
                return cout << "NO" << endl, void();
            }
            last = a[i];
        }
    }

    cout << "YES" << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    // freopen(".in","r",stdin);
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