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

    multiset<int> L, R;

    for (int i = 1; i <= n; i++) {
        char op;
        cin >> op;
        int l, r;
        cin >> l >> r;

        if (op == '+') {
            L.insert(-l);
            R.insert(r);
        } else {
            L.erase(L.find(-l));
            R.erase(R.find(r));
        }

        if (*R.begin() < abs(*L.begin())) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    // freopen(".in", "r", stdin);
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