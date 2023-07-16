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

const int mod = 1e9;
int random(int n) {
    return (LL)rand() * rand() % n;
}

int rand(int l, int r) {
    return (double)rand() / RAND_MAX * (r - l) + l;
}

signed main() {
#ifndef ONLINE_JUDGE
    // freopen(".in","r",stdin);
    freopen("10.in", "w", stdout);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

    srand(time(0));

    int n = 1000;
    cout << n << endl;

    for (int i = 0; i < n; i++) {
        int a = rand(1, 1000000000);
        int b = rand(1, a);
        cout << a << ' ' << b << endl;
    }

    return 0;
}