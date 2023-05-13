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
    string s;
    cin >> s;

    map<char, int> mp;
    int tot = 0;
    for (int i = 0; i < s.size() / 2; i++) {
        mp[s[i]] += 1;
        if (mp[s[i]] == 1)
            tot++;
        // cout<<i<<' ';
    }


    if (tot >= 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

    int tt;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}