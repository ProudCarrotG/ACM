#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
#endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++)
        if (s[i] == s[i - 1])
        {
            cout << "No" << endl;
            return 0;
        }

    cout << "Yes" << endl;

    return 0;
}