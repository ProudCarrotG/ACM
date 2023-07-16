#include <bits/stdc++.h>
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
}

signed main() {
#ifndef ONLINE_JUDGE
    // freopen(".in","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout.tie(0);
#endif

    int n;
    cin >> n;

    int l = 1, r = n;
    while (l<r-1) {
        int mid = l + r >> 1;
        cout << "? " << mid << endl;
        // fflush(stdout);
        int x;
        cin >> x;
        // cout<<"test   "<<l<<' '<<r<<endl;
        if (x == 0)
            l = mid;
        else
            r = mid;
    }

    cout << "! " << l << endl;
    return 0;
}