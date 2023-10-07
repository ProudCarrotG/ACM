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

    vector<int> prime;
    vector<int> vis(n + 10);
    for (int i = 2; i <= n + 1; i++) {
        if (vis[i] == 0)
            prime.push_back(i);
        for (int j = 0; j < prime.size(); j++) {
            if (prime[j] * i > n + 1)
                break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
    // cout << prime.size() << endl;
    // for(auto i:prime)
    //     cout<<i<<' ';
    // cout<<endl;

    vector<int> ans(n + 10, 1);
    int k = 1;
    vector<int> cnt(n + 10);

    for (int i = 2; i <= n + 1; i++) {
        for (int j = 0; j < prime.size(); j++) {
            if (i * prime[j] <= n + 1) {
                if (cnt[ans[i] + 1] == 0) {
                    cnt[ans[i] + 1] = 1;
                    k++;
                }
                ans[i * prime[j]] = ans[i] + 1;
            } else {
                break;
            }
        }
    }

    cout << k << endl;
    for (int i = 2; i <= n + 1; i++)
        cout << ans[i] << ' ';
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