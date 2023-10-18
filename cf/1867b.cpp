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
    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        if (s[i] != s[j])
            cnt++;
    }

    if (n % 2) {
        for (int i = 0; i <= n; i++) {
            if (cnt <= i && i <= n - cnt)
                cout << 1;
            else
                cout << 0;
        }
    } else {
        for (int i = 0; i <= n; i++) {
            if (cnt <= i && i <= n - cnt && i % 2 == cnt % 2)
                cout << 1;
            else
                cout << 0;
        }
    }
    cout << endl;
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