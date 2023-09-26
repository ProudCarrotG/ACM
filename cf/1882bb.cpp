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
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            jh[i].push_back(x);
        }
    }

    int ans = 0;
    for (int i = 1; i <= 50; i++) {
        set<int> res;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            int flag = 1;
            for (int k = 0; k < jh[j].size(); k++) {
                if (jh[j][k] == i) {
                    flag = 0;
                    cnt++;
                }
            }

            if (flag == 1) {
                for (int k = 0; k < jh[j].size(); k++)
                    res.insert(jh[j][k]);
            }
        }

        // cout << i << ": ";
        // for (auto i : res)
        //     cout << i << ' ';
        // cout << endl;
        if (cnt != 0)
            ans = max(ans, (int)res.size());
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