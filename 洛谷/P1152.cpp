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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    set<int> st;
    for (int i = 1; i < n; i++)
        st.insert(abs(arr[i] - arr[i - 1]));

    if (st.size() != n - 1) {
        cout << "Not jolly" << endl;
        return;
    }

    int cnt = 1;
    for (auto i : st) {
        if (i != cnt) {
            cout << "Not jolly" << endl;
            return;
        }
        cnt++;
    }

    cout << "Jolly" << endl;
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