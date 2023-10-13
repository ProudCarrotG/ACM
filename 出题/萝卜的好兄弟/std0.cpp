#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
// typedef long long ll;
#define int long long
typedef pair<int, int> pii;
const int N = 1e5 + 10;
vector<int> st(N, 0), p, s(N, 0);
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 2; i < N; i++) {
        s[i] = s[i - 1];
        if (st[i] == 0)
            p.push_back(i), s[i]++;
        for (int j = 0; j < p.size() && p[j] <= N / i; j++) {
            st[i * p[j]] = 1;
            if (st[i] == 0 && p[j] != i) {
                int k = n / (p[j] * p[j] * i * i * i);
                k = min(k, p[j] - 1);
                ans += s[k];
            }
            if (i % p[j] == 0)
                break;
        }
    }
    cout << ans << '\n';
    return 0;
}