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
    int q;
    cin >> q;
    // multiset<int> box[n + 1];
    // set<int> car[n + 1];

    map<int,multiset<int>> box;
    map<int,set<int>> car;

    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int i, j;
            cin >> i >> j;
            box[j].insert(i);
            car[i].insert(j);
        }
        if (op == 2)
        {
            int i;
            cin >> i;
            for (auto c : box[i])
                cout << c << ' ';
            cout << endl;
        }
        if (op == 3)
        {
            int i;
            cin >> i;
            for (auto b : car[i])
                cout << b << ' ';
            cout << endl;
        }
    }

    return 0;
}