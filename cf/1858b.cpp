#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> s(m);
    int res = 0;
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }
    s.push_back(n + 1);
    s.insert(s.begin(), 1 - d);

    int ans = INT_MAX;
    int cnt = 0;

    vector<int> x;

    for (int i = 1; i <= m; i++) {
        int tmp = -((s[i] - s[i - 1] - 1) / d) - ((s[i + 1] - s[i] - 1) / d) + ((s[i + 1] - s[i - 1] - 1) / d);
        if (tmp < ans) {
            ans = tmp;
            x.clear();
        }
        if (ans == tmp)
            x.push_back(s[i]);
    }

    int tmp = 0;
    for (int i = 1; i < s.size(); i++) {
        tmp += (s[i] - s[i - 1] - 1) / d;
    }
    tmp += int(s.size()) - 2;

    cout << ans + tmp - 1 << ' ' << x.size() << endl;
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