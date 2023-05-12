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
    freopen("data\\9.in", "r", stdin);
    freopen("data\\9.out", "w", stdout);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

        int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int x;
    cin >> x;

    if (a[n] < x)
        return cout << -1 << '\n', 0;
    int l = 1, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        int f = 0;
        for (int i = mid; i <= n; i++) {
            f |= a[i] - a[i - mid] >= x;
        }
        if (f)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << '\n';


    return 0;
}