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
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    cout << abs(ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)) * 1.0 / 2.0 << endl;

    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        int x, y;
        cin >> x >> y;

        if ((y - ay) * (x - bx) == (y - by) * (x - ax)) {
            ans++;
            continue;
        } else if ((y - ay) * (x - bx) == (y - by) * (x - ax)) {
            ans++;
            continue;
        } else if ((y - ay) * (x - bx) == (y - by) * (x - ax)) {
            ans++;
            continue;
        } else{
            int cnt = 0;
            if(
        }
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    cout << fixed << setprecision(1);

    int tt = 1;
    //  cin >> tt;
    while (tt--)
        solve();

    return 0;
}