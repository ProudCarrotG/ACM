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

signed main() {
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    auto check = [&]() {
        for (int i = 1; i < n; i++) {
            int tot = 0;
            for (int j = 0; j < m; j++)
                tot += arr[i - 1][j] != arr[i][j];
            if (tot != 1)
                return 0;
        }
        return 1;
    };

    do {
        if (check()) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(arr.begin(), arr.end()));

    cout << "No" << endl;

    return 0;
}