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

    int ans = 1;
    int tmp = 0;
    int flag = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1)
            flag = 1;
        tmp += flag * 1;
        if (x == 1) {
            ans *= tmp;
            tmp = 0;
        }
    }

    if (flag == 0)
        cout << 0 << endl;
    else
        cout << ans << endl;
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