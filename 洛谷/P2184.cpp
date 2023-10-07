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

const int N = 2e5 + 10;

struct node {
    int l, r;
    int st, en;

} tr[N << 2];
void pushup(node& u, node& l, node& r) {
    u.st = l.st + r.st;
    u.en = l.en + r.en;
}
void pushup(int u) {
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}
void build(int u, int l, int r) {
    tr[u].l = l;
    tr[u].r = r;
    // cout << u << ' ' << tr[u].l << ' ' << tr[u].r << endl;
    if (l == r) {
        tr[u].st = 0;
        tr[u].en = 0;
    } else {
        int L = u * 2, R = L + 1;
        int mid = l + r >> 1;
        build(L, l, mid);
        build(R, mid + 1, r);
        pushup(u);
    }
}
void change(int u, int x, int v) {
    if (tr[u].l == x && tr[u].r == x) {
        int b = tr[u].st += max(0ll, v);
        int c = tr[u].en += min(0ll, v);
        // cout << "tr: " << u << ' ' << c << endl;
        tr[u] = {x, x, b, c};
    } else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid)
            change(u << 1, x, v);
        if (mid + 1 <= x)
            change(u * 2 + 1, x, v);
        pushup(u);
    }
}
node get(int u, int l, int r) {
    // cout << tr[u].l << ' ' << tr[u].r << ' ';
    // debug(u);
    if (l <= tr[u].l && tr[u].r <= r)
        return tr[u];
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        node res;
        if (r <= mid)
            return get(u * 2, l, r);
        if (mid + 1 <= l)
            return get(u * 2 + 1, l, r);
        auto L = get(u * 2, l, r);
        auto R = get(u * 2 + 1, l, r);
        pushup(res, L, R);
        return res;
    }
}
void solve() {
    int n, m;
    cin >> n >> m;

    build(1, 1, n + 1);

    while (m--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            change(1, l, 1);
            change(1, r + 1, -1);
        } else {
            cout << get(1, 1, r).st + get(1, 1, l).en << endl;
            // cout << get(1, 1, r).st << ' ' << get(1, 1, l).en << endl;
        }
        // cout <<"tr: "<< tr[4].en << endl;

        // cout << "-----------" << endl;
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

    int tt = 1;
    //  cin >> tt;
    while (tt--)
        solve();

    return 0;
}