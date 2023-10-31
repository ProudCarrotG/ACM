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

    struct node {
        int l, r;
    };

    vector<node> po(n);
    for (auto& in : po) {
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        in.l = l;
        in.r = b;
    }

    sort(po.begin(), po.end(), [](auto a, auto b) { 
        if(a.l!=b.l)
            return a.l< b.l;
        else{
            return a.r < b.r;
        } });

    vector<int> jmpl, jmpr;
    int L = po[0].l, R = po[0].r;
    for (int i = 1; i < po.size(); i++) {
        if (po[i].l <= R) {
            R = max(R, po[i].r);
            L = min(L, po[i].l);
        } else {
            jmpl.push_back(L);
            jmpr.push_back(R);
            L = po[i].l;
            R = po[i].r;
        }
    }
    jmpl.push_back(L);
    jmpr.push_back(R);

    // for (int i = 0; i < jmpl.size(); i++) {
    //     cout << jmpl[i] << ' ' << jmpr[i] << " | ";
    // }
    // cout << endl;

    int q;
    cin >> q;
    while (q--) {
        int st;
        cin >> st;

        int idx = lower_bound(jmpr.begin(), jmpr.end(), st) - jmpr.begin();

        if (idx < jmpl.size() && jmpl[idx] <= st && st <= jmpr[idx]) {
            cout << jmpr[idx] << ' ';
        } else
            cout << st << ' ';
    }
    cout << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    // freopen(".in","r",stdin);
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