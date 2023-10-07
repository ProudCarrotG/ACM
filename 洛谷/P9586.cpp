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
    int c1, c2, c3, d1, d2, d3;
    cin >> c1 >> c2 >> c3 >> d1 >> d2 >> d3;

    if (c3 > d1) {
        cout << "C" << endl;
        return;
    } else {
        d1 -= c3;
        c3 = 0;
    }

    if (c1 > d2) {
        cout << "C" << endl;
        return;
    }

    if (d3 > c1) {
        cout << "D" << endl;
        return;

    } else {
        c1 -= d3;
        d3 = 0;
    }

    if (d1 > c2) {
        cout << "D" << endl;
        return;
    }

    cout<<"E"<<endl;
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