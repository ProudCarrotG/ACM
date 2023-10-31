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
    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    a.push_back(0);

    vector<int> pre(n + 2);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    vector<int> rpe(n + 2);
    for (int i = n; i >= 1; i--) {
        rpe[i] = rpe[i + 1] + a[i];
    }

    int p;
    for (int i = n; i >= 1; i--) {
        if (pre[i - 1] <= rpe[i]) {
            p = i;
            break;
        }
    }

    // debug(p);

    int ans = 0;
    ans += n - p;
    ans += rpe[p + 1];

    // debug(rpe[p+1]);
    // debug(ans);

    int tot = pre[p] - rpe[p + 1];
    if (tot <= 3) {
        ans += tot;
    } else {
        ans += (tot / 2) + 1 + (tot % 2);
    }
    cout << ans << endl;
}
signed main() {
#ifndef ONLINE_JUDGE
    // freopen(".in","r",stdin);
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