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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (a[n - 1] == 1) {
        return cout << "NO" << endl, void();
    }

    vector<int> ans;
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0) {
            ans.push_back(0);
            cnt = 0;
        } else {
            cnt++;
            if (i == 0 || a[i - 1] != 1)
                ans.push_back(cnt);
            else {
                ans.push_back(0);
            }
        }
    }

    cout << "YES" << endl;
    for (auto i : ans) {
        cout << i << ' ';
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