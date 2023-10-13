#include <bits/stdc++.h>

using namespace std;

#define int long long

int rand(int x) {
    return rand() * rand() % x;
}

int rand(int l, int r) {
    return ((double)rand() / RAND_MAX) * (r - l) + l;
}

signed main() {
    srand(time(0));

    int n = rand(500 - 10) + 5;
    int m = rand(3, n * n);

    cout << n << ' ' << m << endl;

    for (int i = 0; i < n; i++) {
        int x = rand(-1e9, 1e9) * 1.0 * n / 500;
        int y = rand(-1e9, 1e9) * 1.0 * n / 500;
        int r = rand(0, 1e9) * 1.0 * n / 500;
        double p = 1.0 * rand() / RAND_MAX;

        cout << x << ' ' << y << ' ' << r << ' ' << p << endl;
    }

    for (int i = 0; i < m; i++) {
        int a = rand(1, n);
        int b = rand(1, n);
        cout << a << ' ' << b << endl;
    }

    return 0;
}