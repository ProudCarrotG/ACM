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

int n;

void dfs(int n, vector<int> res, int x) {
    if (n == 0 && res.size()!=1) {
        for (int i = 0; i < res.size() - 1; i++)
            cout << res[i] << "+";
        cout << res[res.size() - 1] << endl;
    }
    for (int i = x; i <= n; i++) {
        auto tmp = res;
        tmp.push_back(i);
        dfs(n - i, tmp, i);
    }
}

void solve() {
    cin >> n;
    dfs(n, {}, 1);
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