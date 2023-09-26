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

    vector<int> jh[n];
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;
            jh[i].push_back(y);
            mp[y] += 1;
        }
    }

    vector<pair<int, int>> tmp;
    for (int i = 0; i <= 50; i++) {
        if (mp.count(i) != 0) {
            tmp.push_back({mp[i], i});
        }
    }

    sort(tmp.begin(), tmp.end());

    int k = tmp[0].first;
    vector<int> cf;
    for (int i = 0; tmp[i].first == k; i++) {
        cf.push_back(tmp[i].second);
        cout << tmp[i].second << ' ';
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