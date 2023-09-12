#include <bits/stdc++.h>
using namespace std;
#define fo(x, a, b) for (int x = a; x <= b; x++)
#define of(x, a, b) for (int x = a; x >= b; x--)
#define close()                       \
    ;                                 \
    std::ios::sync_with_stdio(false); \
    cin.tie(nullptr), cout.tie(nullptr);
#define int long long
#define pb push_back
#define fi first
#define se second
#define all(v) v.begin(), v.end()
typedef double db;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef unsigned long long ULL;
const int N = 1e6 + 10;
const int NUL = 0x3f3f3f3f;

bool IsPrime(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0)
            return false;
    return true;
}

void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    fo(i, 1, n) {
        int x;
        cin >> x;
        cnt += x;
    }
    if (n == 1) {
        if (IsPrime(cnt))
            cout << "Yes\n";
        else
            cout << "No\n";
    } else if (n == 2) {
        if (cnt % 2) {
            cnt -= 2;
            if (IsPrime(cnt))
                cout << "Yes\n";
            else
                cout << "No\n";
        } else {
            if (cnt >= 4)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    } else {
        if (cnt >= 2 * n)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return;
}

signed main() {
    close();

    int T = 1;
    // 	cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}