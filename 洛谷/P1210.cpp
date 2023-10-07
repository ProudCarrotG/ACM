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
    string x, s;
    s = " " + s;
    while (getline(cin, x)) {
        x += "\n";
        s += x;
    }

    vector<pair<char, int>> c;
    c.push_back({' ', 0});
    for (int i = 0; i < s.size(); i++) {
        if ('a' <= s[i] && s[i] <= 'z') {
            c.push_back({s[i], i});
        }
        if ('A' <= s[i] && s[i] <= 'Z') {
            c.push_back({s[i] - 'A' + 'a', i});
        }
    }

    unsigned long long pre[c.size() + 2];
    unsigned long long rpre[c.size() + 2];
    unsigned long long p[c.size() + 2];
    memset(pre, 0, sizeof pre);
    memset(rpre, 0, sizeof rpre);
    memset(p, 0, sizeof p);

    p[0] = 1;

    for (int i = 1; i < c.size(); i++) {
        pre[i] = pre[i - 1] * 233 + (c[i].first - 'A');
        p[i] = p[i - 1] * 233;
    }
    for (int i = c.size() - 1; i >= 1; i--) {
        rpre[i] = rpre[i + 1] * 233 + (c[i].first - 'A');
    }

    int ansl, ansr;
    int len = 0;

    for (int i = 1; i < c.size(); i++) {
        for (int j = i; j < c.size(); j++) {
            if (pre[j] - pre[i - 1] * p[j - i + 1] == rpre[i] - rpre[j + 1] * p[j - i + 1]) {
                if (j - i + 1 > len) {
                    ansl = i;
                    ansr = j;
                    len = j - i + 1;
                }
            }
        }
    }

    cout << len << endl;
    for (int i = c[ansl].y; i <= c[ansr].y; i++)
        cout << s[i];
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