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

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int MAX = -INT_MAX, MIN = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        MAX = max(arr[i], MAX);
        MIN = min(arr[i], MIN);
    }
    int limite = MAX - MIN;

    sort(arr.begin(), arr.end());

    vector<int> ans;
    int l = 0, r = n - 1;
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(tot + arr[l]) < limite)
            ans.push_back(arr[l]), tot += arr[l++];
        else if (abs(tot + arr[r]) < limite)
            ans.push_back(arr[r]), tot += arr[r--];
        else
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    for (auto i : ans)
        cout << i << ' ';
    cout << endl;

    return;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

    int tt;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}