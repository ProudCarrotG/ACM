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

    cout<<"YES"<<endl;

    vector<vector<int>> ans;

    int x = 0, y = 0;
    while (n != 0 && m != 0) {
        int l = min(n, m);
        // cout << x << ' ' << y << ' ' << min(n, m) << endl;
        ans.push_back({x,y,l});
        if (n < m) {
            y += n;
            m-=l;
        } else {
            x += m;
            n-=l;
        }
    }

    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i][0]<<' '<<ans[i][1]<<' '<<ans[i][2]<<endl;
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