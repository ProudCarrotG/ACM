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

int random(int n) {
    return (LL)rand() * rand() % n;
}

int rand(int l, int r) {
    return (double)rand() / RAND_MAX * (r - l) + l;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("10.in", "w", stdout);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

    srand(time(0));

    int tt = 1;

    int n = rand(1,100000);
    cout<<n<<endl;
    int maxn = 100000;
    for (int i = 0; i < n; i++) {
        int a = rand(0, maxn);
        int b = rand(0, maxn);
        int c = rand(0, maxn);

        cout << a << ' ' << b << ' ' << c << endl;
    }

    return 0;
}