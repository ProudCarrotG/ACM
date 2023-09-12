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
    int k, n;
    cin >> k >> n;

    vector<int> arr(k);
    for (int i = 0; i < k; i++)
        cin >> arr[i];

    vector<int> tmp(k - 1);
    for (int i = 0; i < k - 1; i++)
        tmp[i] = -abs(arr[i] - arr[i + 1]);

    sort(tmp.begin(), tmp.end());

    // for(int i=0;i<

    int ans = 0;
    for (int i = n - 1; i < k - 1; i++)
        ans += -tmp[i];

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
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}