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
    for (int i = 8; i >= 1; i--)
        for (char j = 'a'; j <= 'h'; j++)
        {
            char c;
            cin >> c;
            if (c == '*')
            {
                cout << j << i << endl;
                return 0;
            }
        }

    return 0;
}