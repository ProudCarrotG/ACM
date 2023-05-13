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

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    int Min = INT_MAX;
    for (int x, i = 0; i < n; i++) {
        cin >> x;
        Min = min(Min, x);
    }

    while (q--) {
        int k;
        cin >> k;
        int ans = Min;
        int red = 1;
        int tmp = 0;
        while (k != 0) {
            if (red == 1) {
                if (k >= n) {
                    k -= n;
                    tmp += n;

                    ans += tmp;
                    if (k >= n) {
                        k -= n;
                        ans -= tmp + 1;
                        tmp += n;
                    } else {
                        k = 0;
                    }
                } else {
                    ans += k;
                    k = 0;
                }
            }
        }
        cout<<ans<<' ';
    }

    return 0;
}