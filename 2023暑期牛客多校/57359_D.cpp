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
    int k, c, n;
    cin >> k >> c >> n;

    int ans = 0;
    for (int b = 1; b * b <= c; b++) {
        if (c % b == 0) {
            {
                if ((c - b) % k == 0) {
                    int a = (c - b) / k;
                    if (a > 0)
                        if (__gcd(a, b) >= n) {
                            // cout << "1 " << a << ' ' << b << endl;
                            ans++;
                        }
                }
            }
            if (b != (c / b)) {
                if ((c - (c / b)) % k == 0) {
                    int a = (c - (c / b)) / k;
                    if (a > 0)
                        if (__gcd(a, (c / b)) >= n) {
                            // cout << "2 " << a << ' ' << c / b << endl;
                            ans++;
                        }
                }
            }
            // cout << "!!!" << endl;
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