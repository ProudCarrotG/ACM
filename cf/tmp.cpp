#include <bits/stdc++.h>
using namespace std;
#define int int64_t
typedef pair<int, int> pii;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(1 >> 8, 0), t(1 >> 8, 0);
    for (int& i : a)
        cin >> i;
    int ans = 0;
    function<vector<int>(int)> itoss = [&](int x) {
        vector<int> tp(8);
        for (int i = 0; i < 8; i++)
            tp[i] = x >> (7 - i) & 1;
        return tp;
    };
    function<int(int)> query = [&](int x) {
        cout << "x : " << x << '\n';
        auto s = itoss(x);
        int p = 1;
        for (int i : s) {
            if (c[p * 2 + (!i)])
                p = p * 2 + (!i);
            else if (c[p * 2 + i])
                p = p * 2 + i;
            else
                break;
        }
        return t[p] ^ x;
    };

    function<void(int)> insert = [&](int x) {
        auto s = itoss(x);
        int p = 1;
        for (int i : s) {
            if (!c[p * 2 + i])
                c[p * 2 + i] = 1;
            p = p * 2 + i;
        }
        t[p] = x;
    };
    // int pp = query(10);
    for (int i = 0; i < n; i++) {
        if (i == 0)
            b[i] = a[i];
        else
            b[i] = b[i - 1] ^ a[i];
        ans = max(ans, query(a[i]));
        // cout << i + 1 << " : "<< ans << '\n' ;
        insert(b[i]);
    }
    cout << ans << '\n';
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int _; cin >> _;
    while (_ -- )
    solve();
    return 0;
}