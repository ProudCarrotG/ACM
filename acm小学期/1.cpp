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

void solve2() {
    // 求全排列
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    do {
        for (auto i : arr)
            cout << i << ' ';
        cout << endl;
    } while (next_permutation(arr.begin(), arr.end()));
}

vector<int> vis(10, 0);
void dfs(int now, vector<int> arr, int tot) {
    if (now > tot) {
        for (auto i : arr)
            cout << i << ' ';
        cout << endl;
    }

    for (int i = 1; i <= tot; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            arr.push_back(i);
            dfs(now + 1, arr, tot);
            arr.pop_back();
            vis[i] = 0;
        }
    }
}
void solve() {
    int n;
    cin >> n;

    dfs(1, {}, n);
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