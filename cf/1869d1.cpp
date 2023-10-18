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

map<int, bool> mp;
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int tot = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        tot += arr[i];
    }

    if (tot % n != 0) {
        return cout << "No" << endl, void();
    }

    int avg = tot / n;

    multiset<int> S, T;
    for (int i = 0; i < n; i++) {
        int add = 1, sub = 1;
        int flaga = 0, flags = 0;
        int tmp = abs(arr[i] - avg);

        if (arr[i] != avg) {
            while (tmp) {
                // cout << tmp << ' ';
                if (tmp & 1) {
                    if (flags == 0) {
                        flags = 1;
                        // sub <<= 1;
                    }
                } else {
                    if (flags == 1) {
                        return cout << "No" << endl, void();
                    }
                }

                if (flags == 0)
                    sub <<= 1;
                add <<= 1;
                tmp = tmp >> 1;
            }
            // cout << endl
            //      << "-------------" << endl;
            if (arr[i] > avg) {
                S.insert(add);
                T.insert(sub);
            } else {
                T.insert(add);
                S.insert(sub);
            }

            // cout << add << ' ' << sub << endl;
        }
    }

    if (S == T)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

    mp[0] = 1;
    for (int x = 1; x <= 1e9; x *= 2)
        mp[x] = 1;

    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}