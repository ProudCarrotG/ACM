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
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    int tot = 0;
    int MAX = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot += a[i];
        MAX = max(a[i], MAX);
    }
    if (tot - MAX > s)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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