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
    // vector<int> arr(n + 1);
    int arr[n + 1];
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    int cnt = 0;
    // memset(cnt, 0, sizeof cnt);
    int x[n + 1];
    memset(x, 0, sizeof x);

    for (int i = 1; i <= n; i++) {
        int a = arr[i - 1], b = arr[i];
        x[i] = x[i - 1];
        while (1) {
            if (a * pow(2, x[i - 1]) <= b * pow(2, x[i] - 1))
                x[i]--;
            else
                break;
        }
        while(a * pow[2,x[i-1\]
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