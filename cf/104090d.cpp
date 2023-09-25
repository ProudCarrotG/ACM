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

void solve1() {
    int n;
    cin >> n;
    vector<double> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int K = 100;
    while (K--) {
        for (int i = 0; i < n; i++) {
            arr[(i + 1) % n] += arr[i] / 2;
            arr[i] /= 2;
        }
        for (int i = 0; i < n; i++)
            cout << arr[i] << ' ';
        cout << endl;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<double> arr(n);
    double tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        tot += arr[i];
    }

    tot /= n + 1;

    // cout << tot * 2 << ' ';
    printf("%.f ", tot * 2);
    for (int i = 1; i < n; i++)
        // cout << tot << ' ';
        printf("%.10f ", tot);
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