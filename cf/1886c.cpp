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

void solve() {
    string s;
    cin >> s;
    int x;
    cin >> x;

    // vector<pair<char, int>> st;
    // for (int i = 0; i < s.size(); i++) {
    //     st.push_back({s[i], i});
    // }
    // sort(st.begin(), st.end(), [](auto a, auto b) { if (a.x == b.x) return a.y < b.y; else return a.x > b.x; });

    // for (auto i : st) {
    //     cout << i.x << ' ' << i.y << endl;
    // }
    int n = s.size();
    stack<pair<char, int>> st;
    vector<bool> bj(s.size());

    if (x <= n) {
        cout << s[x-1];
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        while (st.size() && st.top().x > s[i]) {
            bj[st.top().y] = 1;
            st.pop();
            x -= n;
            n--;

            if (x <= n) {
                int cnt = 0;
                char ans;
                for (int i = 0; cnt < x; i++) {
                    if (bj[i] == 0) {
                        ans = s[i];
                        cnt++;
                    }
                }
                // cout << cnt << endl;
                cout << ans;
                return;
            }
        }
        st.push({s[i], i});
    }

    while (st.size()) {
        bj[st.top().y] = 1;
        st.pop();
        x -= n;
        n--;

        if (x <= n) {
            int cnt = 0;
            char ans;
            for (int i = 0; cnt < x; i++) {
                if (bj[i] == 0) {
                    ans = s[i];
                    cnt++;
                }
            }

            cout << ans;
            return;
        }
    }
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
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}