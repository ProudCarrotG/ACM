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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> op;
    int maxn = INT_MAX;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (x < maxn) {
            maxn = x;
            op.push_back(maxn);
        }
    }

    for (int i = 0; i < op.size(); i++) {
        int tmp = pow(2, op[i]);
        for (int i = 0; i < n; i++) {
            if (a[i] % tmp == 0) {
                a[i] += tmp / 2;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
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