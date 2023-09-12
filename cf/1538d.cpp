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

vector<int> prime;

void get_prime() {
    const int N = 1e5;
    map<int, int> vis;
    for (int i = 2; i <= N; i++) {
        if (vis.count(i) == 0) {
            prime.push_back(i);
            // cout<<i<<' ';
        }

        for (int j = 0; j < prime.size(); j++) {
            if (i * prime[j] > N)
                break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

void solve1() {
    int a, b, k;
    cin >> a >> b >> k;
    multiset<int> st;
    for (int i = 2; i <= a; i++) {
        while (a % i == 0) {
            st.insert(i);
            a /= i;
        }
    }
    for (auto i : st)
        cout << i << ' ';
    cout << endl;

    st.clear();
    for (int i = 2; i <= b; i++) {
        while (b % i == 0) {
            st.insert(i);
            b /= i;
        }
    }
    for (auto i : st)
        cout << i << ' ';
    cout << endl;
    cout << "---------------" << endl;
}

void solve() {
    int a, b, k;
    cin >> a >> b >> k;

    vector<int> ys1, ys2;
    for (int i = 0; i < prime.size() && prime[i] * prime[i] <= a; i++) {
        while (a % prime[i] == 0) {
            ys1.push_back(prime[i]);
            a /= prime[i];
        }
    }

    int res = 0;
    for (int i = 0; i < ys1.size(); i++) {
        if (b % ys1[i] == 0)
            b /= ys1[i];
        else
            res++;
    }

    for (int i = 0; i < prime.size() && prime[i] * prime[i] <= b; i++) {
        while (b % prime[i] == 0) {
            res++;
            b /= prime[i];
        }
    }

    cout << res << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

    get_prime();
    int tt = 1;
    cin >> tt;
    // cout<<tt<<endl;
    while (tt--)
        solve1();

    return 0;
}