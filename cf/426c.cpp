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

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];


    int ans = INT_MIN;
    for (int l = 0; l < n; l++)
        for (int r = l; r < n; r++) {
            vector<int> tmp;
            for (int i = 0; i < l; i++)
                tmp.push_back(arr[i]);
            for (int i = r + 1; i < n; i++)
                tmp.push_back(arr[i]);
            sort(tmp.begin(), tmp.end());

            vector<int> res;
            int tot = 0;
            for (int i = l; i <= r; i++) {
                tot += arr[i];
                res.push_back(arr[i]);
            }
            sort(res.begin(), res.end());

            for (int i = 0; i < k && i < res.size() && 0 <= (int)(tmp.size()) - 1 - i; i++) {
                if (res[i] < tmp[tmp.size() - 1 - i]) {
                    tot -= res[i];
                    tot += tmp[tmp.size() - 1 - i];
                }
            }

            ans = max(ans, tot);
    // cout << "----------" << endl;
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