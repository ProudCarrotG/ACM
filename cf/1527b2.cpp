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
    string s;
    cin >> s;

    if (s == string(s.rbegin(), s.rend())) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
            cnt += (s[i] == '0');

        // cout<<cnt<<endl;
        if (cnt % 2 && cnt != 1)
            cout << "ALICE" << endl;
        else
            cout << "BOB" << endl;
        return;
    }

    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        cnt += s[i] == '0';
    }

    if (s.size() % 2 && cnt == 2 && s[s.size() / 2] == '0')
        cout << "DRAW" << endl;
    else
        cout << "ALICE" << endl;
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
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}