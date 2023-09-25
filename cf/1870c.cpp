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

void solve1() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << min(a[i], a[j]) << ' ';
        cout << endl;
    }
    cout << "-----------" << endl;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    map<int, int> mp1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp1[a[i]] = 1;
    }

    vector<int> res1(k + 1);
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        while (a[i] >= cnt) {
            res1[cnt] = i;
            cnt++;
        }
    }

    vector<int> res2(k + 1);
    cnt = 1;
    for (int i = n; i >= 1; i--) {
        while (a[i] >= cnt) {
            res2[cnt] = i;
            cnt++;
        }
    }

    for (int i = 1; i <= k; i++) {
        if (mp1.count(i)) {
            cout << 2 * (res2[i] - res1[i] + 1) << ' ';
        } else
            cout << 0 << ' ';
    }
    cout << endl;
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