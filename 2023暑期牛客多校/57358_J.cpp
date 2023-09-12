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
    int n, m;
    cin >> n >> m;

    queue<vector<int> > q;
    for (int i = -m; i <= m; i++)
        q.push({i});

    int ans = 0;
    while (q.size()) {
        vector<int> now = q.front();
        q.pop();

        if (now.size() == n) {
            int flag = 1;
            for (int i = 0; i < now.size(); i++) {
                int tot = now[i];
                for (int j = i + 1; j < now.size(); j++) {
                    tot += now[j];
                    if (tot < 0) {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag == 1)
                ans++;
            continue;
        }

        for (int i = -m; i <= m; i++) {
            vector<int> tmp = now;
            tmp.push_back(i);
            q.push(tmp);
        }
    }
    cout<<"n="<<n<<' '<<"m="<<m<<' ';
    cout <<"ans="<< ans << endl;
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