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
    vector<string> s(n);
    map<string, int> want;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        want[s[i]] = 1;
    }

    int m;
    cin >> m;
    vector<string> arr(m);
    set<string> bj;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
        if (want[arr[i]])
            bj.insert(arr[i]);
    }

    if (bj.size() == 0) {
        cout << 0 << endl
             << 0 << endl;
        return;
    }

    auto check = [&](int x) {
        for (int i = 0; i < m; i++) {
            set<string> tmp;
            for (int j = 0; j < x && i + x - 1 < m; j++) {
                if (want[arr[i + j]])
                    tmp.insert(arr[i + j]);
            }
            if (tmp.size() == bj.size()) {
                return 1;
            }
        }
        return 0;
    };

    int ans = INT_MAX;
    int l = 0, r = m;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            ans = min(ans,mid);
            r = mid - 1;
        } else
            l = mid + 1;
    }

    cout << bj.size() << endl
         << l << endl;
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