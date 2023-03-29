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

    string s;
    cin >> s;
    vector<int> arr(10, 0);
    map<vector<int>, int> mp;
    int ans = 0;
    mp[arr] += 1;
    for (int i = 0; i < s.size(); i++)
    {
        int now = s[i] - '0';
        arr[now] = (arr[now] + 1) % 2;
        if (mp.count(arr))
            ans += mp[arr];
        mp[arr] += 1;

        // string tmp;
        // for (int i = 0; i <= 9; i++)
        //     if (arr[i] == 0)
        //         tmp += '0';
        //     else
        //         tmp += '1';
        // cout << tmp << endl;
    }
    cout << ans << endl;

    return 0;
}