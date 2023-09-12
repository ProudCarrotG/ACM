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
    int a, b, k;
    cin >> a >> b >> k;
    if (k == 1) {
        if ((a % b == 0 || b % a == 0) && a != b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return;
    }

    int res = 0;
    for (int i = 2; i * i <= a; i++) {
        while (a % i == 0) {
            res++;
            a /= i;
        }
    }
    for (int i = 2; i * i <= b; i++) {
        while (b % i == 0) {
            res++;
            b /= i;
        }
    }

    // cout<<res<<endl;

    if (res > k)
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