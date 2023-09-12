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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    map<int, int> mpp;
    vector<int> mp;
    int tmp = arr[n - 1];
    mpp[n - 1] = arr[n - 1];
    mp.push_back(tmp);
    for (int i = n - 2; i >= 0; i--) {
        tmp ^= arr[i];
        mp.push_back(tmp);
        mpp[i] = tmp;

        // cout<<tmp<<endl;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < mp.size(); j++) {
            ans = max(mpp[i] ^ mp[j], ans);
        }
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