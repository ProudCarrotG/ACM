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

    bool bj[2000000 + 10];
    memset(bj, 0, sizeof bj);

    for (int i = 0; i < n; i++) {
        double a;
        int t;
        cin >> a >> t;

        for (int j = 1; j <= t; j++)
            bj[(int)(a * j)] = !bj[(int)(a * j)];
    }

    for (int i = 1; i <= 2000000; i++)
        if (bj[i] == 1)
            cout << i << endl;
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