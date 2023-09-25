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
    // cout << n << endl;
    // cout << pow(n, 1.0 / 3) << endl;

    vector<int> prime;
    vector<int> mp(1e6 + 10);
    for (int i = 2; i <= 1e6; i++) {
        if (mp[i] == 0) {
            prime.push_back(i);
            // cout << i << endl;
        }
        for (int j = 0; j < prime.size(); j++) {
            if (prime[j] * i > 1e6)
                break;
            mp[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
    // cout << prime.size() << endl;

    int res = 0;
    for (int i = 0; i < prime.size(); i++) {
        for (int j = i + 1; j < prime.size(); j++) {
            int c = n / prime[i] / prime[j] / prime[j];
            c = pow(c, 1.0 / 3);

            if (prime[i] * prime[j] * prime[j] * prime[j + 1] * prime[j + 1] * prime[j + 1] > n)
                break;

            int x = upper_bound(prime.begin(), prime.end(), c) - prime.begin() - 1;

            res += max(0ll, x - j);

            // cout << i << ' ' << j << ' ' << x << endl;
        }
    }
    cout << res << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
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