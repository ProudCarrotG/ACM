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
    int n, k;
    cin >> n >> k;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == k)
            ans = 1;
    }

    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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