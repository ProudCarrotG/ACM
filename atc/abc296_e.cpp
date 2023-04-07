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

    int n;
    cin >> n;
    vector<int> f(n + 1, 0);
    auto find = [&](auto find, int x)
    {
        if (f[x] == x)
            return x;
        return f[x] = find(find, f[x]);
    };
    auto add = [&](int x, int y)
    {
        f[x] = find(find, y);
    };
    // for(int i=1;i<=n;i++)
    //     f[i] = i;
    vector<int> tp(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(find(find,i)==find(find,x))
            tp[find(find,x)] = 1;
        add(i,x);
    }

    

    return 0;
}