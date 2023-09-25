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
    // cout<<0|1<<endl;
    int n, m;
    cin >> n >> m;
    int A = 0;

    int flag = n % 2;
    int maxa = 0;

    vector<int> a(n);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        A ^= x;
        a[i] = x;
        maxa = max(a[i], maxa);
    }

    int B = 0;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        if (flag == 0) {
            // if (x <= maxa)
            B |= x;
            // else
            //     ;
        } else
            B |= x;
    }

    int res1 = A;
    int res2 = 0;
    // cout << maxa << endl;
    // cout << B << endl;
    for (int i = 0; i < n; i++) {
        a[i] |= B;
        res2 ^= a[i];
        // cout << a[i] << ' ';
    }
    // cout << endl;

    cout << min(res1, res2) << ' ' << max(res1, res2) << endl;
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