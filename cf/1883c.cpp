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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int ans = LLONG_MAX;
    int cnt_odd = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (k == 2) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) {
                cnt++;
            }
        }
        cout << max(0ll, 1 - cnt) << endl;
        return;
    } else if (k == 3) {
        int cnt = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 3 == 0) {
                cnt = min(cnt, 0ll);
            }
            if ((arr[i] + 1) % 3 == 0) {
                cnt = min(cnt, 1ll);
            }
            if ((arr[i] + 2) % 3 == 0) {
                cnt = min(cnt, 2ll);
            }
        }
        cout << cnt << endl;
    } else if (k == 4) {
        int cnt1 = 0;
        int cnt2 = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) {
                cnt1++;
            }
            if (arr[i] % 4 == 0) {
                cnt2 = min(cnt2, 0ll);
            }
            if ((arr[i] + 1) % 4 == 0) {
                cnt2 = min(cnt2, 1ll);
            }
            if ((arr[i] + 2) % 4 == 0) {
                cnt2 = min(cnt2, 2ll);
            }
            if ((arr[i] + 3) % 4 == 0) {
                cnt2 = min(cnt2, 3ll);
            }
        }

        int ans1 = max(0ll, 2 - cnt1);
        int ans2 = cnt2;

        cout << min(ans1, ans2) << endl;
    } else if (k == 5) {
        int cnt = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 5 == 0) {
                cnt = min(cnt, 0ll);
            }
            if ((arr[i] + 1) % 5 == 0) {
                cnt = min(cnt, 1ll);
            }
            if ((arr[i] + 2) % 5 == 0) {
                cnt = min(cnt, 2ll);
            }
            if ((arr[i] + 3) % 5 == 0) {
                cnt = min(cnt, 3ll);
            }
            if ((arr[i] + 4) % 5 == 0) {
                cnt = min(cnt, 4ll);
            }
        }
        cout << cnt << endl;
    }
    // cout << "-------" << endl;
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