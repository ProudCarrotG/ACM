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
    int x;
    cin >> x;

    vector<int> arr;
    queue<int> q;
    q.push(1);
    while (q.size()) {
        int now = q.front();
        q.pop();
        arr.push_back(now);

        if (now <= LLONG_MAX / 10) {
            q.push(now * 10);
            q.push(now * 10 + 1);
        }
    }

        // cout << arr.size() << ' ';
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % x == 0) {
            cout << arr[i] / x << endl;
            return;
        }
    }
    cout << "No Solution"<<endl;
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