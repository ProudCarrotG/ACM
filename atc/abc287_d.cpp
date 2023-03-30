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

    string s, t;
    cin >> s >> t;

    auto check = [&](char a, char b)
    {
        if (a == '?' || b == '?')
            return true;
        return (a == b);
    };

    vector<int> a(s.size() + 1), b(s.size() + 2);
    a[0] = b[t.size() + 1] = 1;
    for (int i = 0; i < t.size(); i++)
    {
        a[i + 1] = a[i] && check(s[i], t[i]);
    }

    for (int i = 0; i < t.size(); i++)
    {
        b[t.size() - i] = b[t.size() - i + 1] && check(s[s.size() - 1 - i], t[t.size() - 1 - i]);
    }

    // for (int i = 0; i <= t.size(); i++)
    //     cout << a[i] << ' ';
    // cout << endl;
    // for (int i = 0; i <= t.size(); i++)
    //     cout << b[i] << ' ';
    // cout << endl;

    for (int i = 0; i <= t.size(); i++)
    {
        if (a[i] && b[i + 1])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}