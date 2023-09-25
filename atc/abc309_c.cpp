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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> arr(n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        tot += arr[i].second;
    }
    sort(arr.begin(), arr.end());

    // for(int i=0;i<n;i++)
    // {
    //     cout<<arr[i].first<<' '<<arr[i].second<<endl;
    // }

    if (tot <= k) {
        cout << 1 << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        tot -= arr[i].second;
        while (arr[i + 1].first == arr[i].first) {
            i++;
            tot -= arr[i].second;
        }
        // cout << tot << endl;
        if (tot <= k) {
            cout << arr[i].first + 1 << endl;
            return;
        }
    }
    cout << arr[n - 1].first + 1 << endl;
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