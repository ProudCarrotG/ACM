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

int mode = 998244353;

long long qmi(LL a, LL b = mode - 2, LL p = mode) {
    LL ans = 1;
    while (b) {
        if (b & 1)
            ans = (LL)(ans * a) % p;
        a = (LL)(a * a) % p;
        b >>= 1;
    }
    return ans;
}

void solve() {
    int x;
    cin >> x;
    cout << ((1 - sqrt(1 - 4 * x)) / (2 * x)) << endl;

    cout << ((1 - sqrt(1 - 4 * x)) % mode * qmi(2 * x)) % mode << endl;
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