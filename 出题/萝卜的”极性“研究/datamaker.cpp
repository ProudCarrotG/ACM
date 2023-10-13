#include <bits/stdc++.h>

using namespace std;

#define int long long

int rand(int x) {
    return (rand() * rand()) % x;
}

int rand(int l, int r) {
    return ((double)rand(RAND_MAX) / RAND_MAX) * (r - l) + l;
}

char C[4] = {'M', 'V', 'N', 'Z'};

signed main() {
    srand(time(0));

    int n = rand(1,1e5 - 1) + 1;
    int m = rand(1e5-2) + 2;
    cout << n << ' ' << m << endl;
    for (int i = 1; i <= n; i++) {
        cout << C[rand(4)];
    }
    cout << endl;

    int len = n;
    int qnum = rand(1, min(10ll, m));

    for (int i = 1; i <= m - qnum; i++) {
        int l = rand(0, len - 1);
        int r = rand(l, min(l + 100000, len - 1));
        cout << 0 << ' ' << l << ' ' << r << endl;
        len += (r - l + 1);
    }
    for (int i = 1; i <= qnum; i++) {
        int x = rand(0, len - 1);
        cout << 1 << ' ' << x << endl;
    }

    return 0;
}