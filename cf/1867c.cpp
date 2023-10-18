#include <bits/stdc++.h>
#include<iostream>


using namespace std;
#define int long long
#define LL long long
#define PII pair<int, int>
#define umap unordered_map
#define x first
#define y second
// #define endl "\n"
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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int i = 0;
    for (i = 0; i < n; i++)
        if (i != arr[i])
            break;

    int x = i;
    while (x != -1 && x != -2) {
        cout << x << endl;
        cin >> x;
    }
    return;
}

signed main() {
#ifndef ONLINE_JUDGE
    // freopen(".in", "r", stdin);
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