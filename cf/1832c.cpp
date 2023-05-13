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
    vector<int> a;
    int x;
    cin >> x;
    a.push_back(x);
    for (int x, i = 1; i < n; i++) {
        cin >> x;
        if (x != a[a.size()-1])
            a.push_back(x);
    }

    // for(auto i:a)
    //     cout<<i<<' ';
    // cout<<endl;

    if (a.size() == 1) {
        cout << 1 << endl;
        return;
    }

    int ans = 2;
    for (int i = 1; i < a.size() - 1; i++) {
        if (a[i - 1] < a[i] && a[i] > a[i + 1])
            ans++;
        if (a[i - 1] > a[i] && a[i] < a[i + 1])
            ans++;
    }
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

    int tt;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}