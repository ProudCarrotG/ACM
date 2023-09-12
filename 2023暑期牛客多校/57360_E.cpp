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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        arr[i] = x % 2;
    }

    vector<int> cnt1(n + 1);
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        tot += arr[i];
        if (tot % 2 == 0)
            cnt1[i]++;
        cnt1[i] += cnt1[i - 1];

        // cout << cnt1[i] << ' ';
    }
    // cout << endl;

    vector<int> cnt2(n + 1);
    tot = 0;
    int p = 0;
    for (int i = 1; i <= n; i++) {
        if (p == 0 && arr[i] == 1) {
            p = 1;
            continue;
        }
        if (p == 1) {
            tot += arr[i];
            if (tot % 2== 0)
                cnt2[i]++;
            cnt2[i] += cnt2[i - 1];
        }
        // cout << cnt2[i] << ' ';
    }
    // cout << endl;

    for (int i = 2; i <= n; i++) {
        arr[i] += arr[i - 1];
    }

    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;

        if ((arr[r] - arr[l - 1]) % 2) {
            cout << "NO" << endl;
            continue;
        }

        if (arr[l - 1] % 2 == 0) {
            if (cnt1[r] - cnt1[l - 1] >= k)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        } else {
            if (cnt2[r] - cnt2[l - 1] >= k)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
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
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}