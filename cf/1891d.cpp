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
    vector<int> f = {0, 1, 1};
    vector<int> g = {-1, -1, -1};

    int N = 10000000;

    set<int> st;
    int cnt = 0;

    map<int, int> mp;
    mp[1] = INT_MAX;
    mp[2] = INT_MAX;
    mp[3] = INT_MAX;
    mp[4] = INT_MAX;
    mp[5] = INT_MAX;

    for (int x = 4; x <= N; x++) {
        int ansY;
        for (int i = 0; pow(2, i) <= x; i++) {
            ansY = i;
        }
        f.push_back(ansY);

        int ansG;
        for (int i = 0; pow(ansY, i) <= x; i++) {
            ansG = i;
        }
        g.push_back(ansG);
        mp[ansG] = min(mp[ansG], x);
    }

    cout << mp[1] << endl;
    cout << mp[2] << endl;
    cout << mp[3] << endl;
    cout << mp[4] << endl;
    cout << mp[5] << endl;
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
    //  cin >> tt;
    while (tt--)
        solve();

    return 0;
}