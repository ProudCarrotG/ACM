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

    int a, b, c = n - 3;
    a = 1, b = 2;
    if (c % 3 == 0) {
        if ((n - 5) % 3 != 0 && (n - 5) > 0)
            b = 4, c = n - 5;
        else {
            cout << "NO" << endl;
            return;
        }
    }

    if (a != b && b != c && a != c && a > 0 && b > 0 && c > 0) {
        cout << "YES" << endl;
        cout << a << ' ' << b << ' ' << c << endl;
        return;
    }
    cout << "NO" << endl;
    return;
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