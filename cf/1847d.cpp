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
    int n, m, q;

    cin >> n >> m >> q;
    string s;
    cin >> s;
    s = ' ' + s;

    vector<int> next(n + 10);
    for (int i = 1; i <= n; i++) {
        next[i] = i + 1;
    }

    vector<int> c(n + 10);

    auto lowbit = [&](int x) {
        return x & -x;
    };

    auto add = [&](int x, int k) {
        while (x <= n) {
            c[x] += k;
            x += lowbit(x);
        }
    };

    auto getsum = [&](int x) {
        int res = 0;
        while (x > 0) {
            res += c[x];
            x -= lowbit(x);
        }
        return res;
    };

    vector<int> arr(n + 10), vis(n + 10);
    int idx = 1;
    while (m--) {
        int l, r;
        cin >> l >> r;

        int ne;
        for (int i = l; i <= r; i = ne) {
            ne = next[i];
            if (vis[i] == 0) {
                next[i] = r + 1;
                arr[i] = idx++;
                vis[i] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            arr[i] = idx;
        }
    }

    idx--;

    for (int i = 1; i <= n; i++) {
        add(arr[i], s[i] - '0');
    }

    // debug(idx);

    while (q--) {
        int x;
        cin >> x;

        if (s[x] == '0') {
            add(arr[x], 1);
            s[x] = '1';
        } else {
            add(arr[x], -1);
            s[x] = '0';
        }

        int cnt = getsum(n);
        // debug(cnt);
        cout << max(0ll, min(idx, cnt) - getsum(min(idx, cnt))) << endl;
    }
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