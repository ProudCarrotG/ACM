#include <bits/stdc++.h>

using namespace std;

int random(int n) {
    return (long long)rand() * rand() % n;
}

int rand(int l, int r) {
    return (double)rand() / RAND_MAX * (r - l) + l;
}

int main() {
    freopen("data//10.in", "w", stdout);

    int n = random(100) + 1;
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        int op = (((double)rand() / RAND_MAX) > 0.6 ? 0 : 1);
        cout << op << ' ' << rand(0, 1000) << endl;
    }
    return 0;
}