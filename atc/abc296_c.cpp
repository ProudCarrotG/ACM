#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
signed main()
{
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    int n, X;
    cin >> n >> X;
    map<int, bool> mp;
    vector<int> arr;
    for (int x, i = 1; i <= n; i++)
    {
        cin >> x;
        mp[x] = 1;
        arr.push_back(x);
    }
    for (int i = 0; i < arr.size(); i++)
        if (mp[arr[i] - X] == 1)
        {
            cout << "Yes" << endl;
            return 0;
        }

    cout << "No" << endl;

    return 0;
}