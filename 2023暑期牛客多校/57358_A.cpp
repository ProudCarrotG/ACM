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

int mode = 1e9 + 7;

void solve() {
    int n;
    string t;
    cin >> n >> t;

    string s = t + string(n, '0') + t;

    int T = 0;
    for (int i = 0; i < t.size(); i++) {
        T = (T * 4) % mode;
        T = (T + t[i] - '0' + 1) % mode;
    }

    int CNT = 1;
    int tmp = 0;
    for (int i = 0; i < t.size(); i++) {
        tmp = (tmp * 4) % mode;
        tmp = (tmp + s[i] - '0' + 1) % mode;
    }

    for (int i = 0,j = t.size(); j< s.size(); i++,j++) {
        tmp -= s[i] - '0' + 1;
        
    }

    if (CNT == 2)
        cout << string(n, '0') << endl;
    else {
        // cout << CNT << endl;
        cout << string(n, '1') << endl;
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