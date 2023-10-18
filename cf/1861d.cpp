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

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    vector<int> up(n + 2, 0);
    for (int i = 2; i <= n; i++) {
        up[i] += up[i - 1] + (arr[i] >= arr[i - 1]);
        // cout << up[i] << ' ';
    }
    // cout << endl;
    vector<int> down(n + 2, 0);
    for (int i = n - 1; i >= 1; i--) {
        down[i] += down[i + 1] + (arr[i] >= arr[i + 1]);
        // cout << down[i] << ' ';
    }
    // cout << endl;

    int ans = min(up[n] + 1, down[1]);
    for (int i = 1; i < n; i++) {
        ans = min(ans, up[i] + 1 + down[i + 1]);
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

    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}