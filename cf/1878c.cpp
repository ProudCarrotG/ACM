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

vector<int> pre;

void solve() {
    int n, k, x;
    cin>>n>>k>>x;

    // cout<<pre[k]<<' '<<pre[n]<<endl;
    if (pre[k] <= x && x <= pre[n] - pre[n-k])
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

    pre.push_back(0);
    for (int i = 1; i <= 2e5; i++) {
        pre.push_back(pre[i - 1] + i);
        // cout<<pre[i]<<' ';
    }

    // cout << pre[2e5] << endl;

    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}