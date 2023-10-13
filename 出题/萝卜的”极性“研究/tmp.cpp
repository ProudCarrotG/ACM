#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = ' ' + s;

    vector<pll> op;
    vector<ll> qry;
    for (int i = 0; i < m; i++) {
        int OP;
        cin >> OP;
        if (OP) {
            ll pos;
            cin >> pos;
            pos++;
            qry.push_back(pos);
        } else {
            ll L, R;
            cin >> L >> R;
            L++, R++;
            op.push_back({L, R});
        }
    }

    vector<ll> len(1, op[0].y - op[0].x + 1 + n);
    for (int i = 1; i < (int)op.size(); i++)
        len.push_back(op[i].y - op[i].x + 1 + len.back());

    auto find = [&](ll pos, auto self) -> ll {
        if (pos <= n)
            return pos;
        else {
            int l = 0, r = len.size() - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (len[mid] >= pos)
                    r = mid;
                else
                    l = mid + 1;
            }
            if (len[l] < pos)
                return -1ll;

            ll d = len[l] - pos;
            return self(op[l].x + d, self);
        }
    };

    for (int i = 0; i < (int)qry.size(); i++) {
        int pos = find(qry[i], find);
        if (pos == -1)
            cout << -1 << endl;
        else
            cout << s[pos] << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;cin >> t;while (t--)
    solve();
    return 0;
}