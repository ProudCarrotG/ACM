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

void solve1() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = " " + s;
    cout << s << endl;

    while (k--) {
        for (int i = 1; i < s.size() - 1; i++) {
            if (s[i] == '4' && s[i + 1] == '7') {
                if (i % 2)
                    s[i + 1] = '4';
                else
                    s[i] = '7';
                break;
            }
        }
        cout << s << endl;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = " " + s;
    map<string, bool> mp;
    vector<string> arr;
    int cnt = 0;

    mp[s] = 1;
    arr.push_back(s);

    int flag = 1;
    for (int i = 1; i < n; i += flag) {
        flag = 1;
        if (s[i] == '4' && s[i + 1] == '7') {
            if (i % 2)
                s[i + 1] = '4';
            else {
                s[i] = '7';
                flag = -1;
            }

            if (mp.count(s) == 0)
                arr.push_back(s);
            else
                break;
            cnt++;

            if (cnt >= k)
                break;
        }
    }

    for(auto i:arr)
        cout<<i<<' ';
    cout<<endl;

    cout << arr[k % arr.size()] << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();

    return 0;
}