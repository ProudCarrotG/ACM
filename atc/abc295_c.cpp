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

signed main()
{
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

    int n;
    cin >> n;
    set<int> st;
    map<int, int> mp;
    for (int x, i = 0; i < n; i++)
    {
        cin >> x;
        st.insert(x);
        mp[x]++;
    }

    int ans = 0;
    for (auto i : st)
    {
        ans += mp[i] / 2;
    }
    cout << ans << endl;

    return 0;
}