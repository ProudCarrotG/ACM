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

double getdis(double a, double b, double c, double d) {
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

void solve() {
    int px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;

    double ans1 = max({getdis(ax, ay, bx, by) / 2.0, min(getdis(0, 0, ax, ay), getdis(0, 0, bx, by)), min(getdis(px, py, ax, ay), getdis(px, py, bx, by))});

    double ans2 = max(getdis(0, 0, ax, ay), getdis(px, py, ax, ay));

    double ans3 = max(getdis(0, 0, bx, by), getdis(px, py, bx, by));

    cout << min({ans1, ans2, ans3}) << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    cout << fixed << setprecision(10);

    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}