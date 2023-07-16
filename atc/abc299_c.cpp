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
    string s;
    cin >> s;

    int res = -1;

    int tmp = 0,cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'o')
            tmp++;
        if (s[i] == '-') {
            // res = max(res, tmp);
            cnt++;
            tmp = 0;
        }
        res = max(res,tmp);
    }

    if(cnt == 0||res == 0)
        res = -1;
    cout << res << endl;
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