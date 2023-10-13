#include <bits/stdc++.h>
using namespace std;
#define int long long
#define LL long long
#define PII pair<int, int>
#define umap unordered_map
#define l first
#define r second
#define endl "\n"
#ifndef ONLINE_JUDGE
#define debug(x) cout << #x << ' ' << x << endl;
#define fg cout << "-----------------" << endl;
#else
#define debug(x)
#define fg
#endif

void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<pair<int, int>> op;

    auto check = [&](int x, int len) {
        if (x > len)
            return (char)-1;

        int id = op.size() - 1;
        while (x >= s.size()) {
            int oplen = op[id].r - op[id].l + 1;
            if (len - oplen <= x) {
                int tmp = len - 1 - x;
                x = op[id].l + tmp;
            }
            len -= oplen;
            id--;
        }
        return s[x];
    };

    int len = s.size();
    while (m--) {
        int o;
        cin >> o;
        if (o == 0) {
            int l, r;
            cin >> l >> r;
            op.push_back({l, r});
            len += r - l + 1;
        } else {
            int x;
            cin >> x;
            char ans = check(x, len);
            if (ans == -1)
                cout << -1 << endl;
            else
                cout << ans << endl;
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