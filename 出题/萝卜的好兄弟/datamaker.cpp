// #include <windows.h>
#include <bits/stdc++.h>
using namespace std;

#define int long long

int rand(int x) {
    return rand() * rand() % x;
}

int rand(int l, int r) {
    return (double)rand() / RAND_MAX * (r - l) + l;
}

signed main() {
    srand(time(0));

    int x = rand(9)+3;

    int n = rand(300, pow(10, x));
    // cout << x << endl;
    cout << n << endl;

    return 0;
}