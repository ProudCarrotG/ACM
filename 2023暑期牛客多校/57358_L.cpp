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
    int q;
    cin >> n >> m >> q;

    vector<pair<string, int>> r(1e6 + 10), c(1e6 + 10);

    for (int i = 1; i <= q; i++) {
        string name, op;
        int x;
        cin >> name >> x >> op;
        if (name == "row")
            r[x] = {op, i};
        else
            c[x] = {op, i};
    }

    // r:0   c:1
    vector<vector<int>> op(1e6 + 10, {-1});
    for (int i = 1; i <= n; i++) {
        if (r[i].second != 0) {
            op[r[i].second] = {0, i, r[i].first == "on"};
        }
    }

    for (int i = 1; i <= m; i++) {
        if (c[i].second != 0) {
            op[c[i].second] = {1, i, c[i].first == "on"};
        }
    }

    // cout<<n<<' '<<m<<endl;
    int Or = 0, Oc = 0;
    int ans = 0;
    for (int i = 1; i <= q; i++) {
        if (op[i][0] != -1) {
            // cout << op[i][0] << ' ' << op[i][1] << ' ' << op[i][2] << endl;
            //
            if (op[i][0] == 0 && op[i][2] == 0)
                ans -= Oc;
            else if (op[i][0] == 0 && op[i][2] == 1) {
                ans += m - Oc;
                Or++;
            }
            if (op[i][0] == 1 && op[i][2] == 0)
                ans -= Or;
            else if (op[i][0] == 1 && op[i][2] == 1) {
                ans += n - Or;
                Oc++;
            }
        }
        // cout << ans << endl;
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
    //  cin >> tt;
    while (tt--)
        solve();

    return 0;
}