#include <bits/stdc++.h>

using namespace std;

int tire[500010][300];
int tmp[500010];
int main()
{
    //    freopen(".in", "r", stdin);

    int n;
    cin >> n;
    vector<string> S;
    int idx = 0;

    auto add = [&](string s)
    {
        int now = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (tire[now][s[i]] == 0)
                tire[now][s[i]] = ++idx;
            now = tire[now][s[i]];
            tmp[now]++;
        }
    };

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        add(s);
        S.push_back(s);
    }

    int ans = 0;

    for (int i = 0; i < S.size(); i++)
    {
        ans = 0;
        int now = 0;
        while (ans < S[i].size() && tmp[tire[now][S[i][ans]]] > 1)
        {
            now = tire[now][S[i][ans]];
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}