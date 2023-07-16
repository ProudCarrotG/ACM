#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("10.in", "r", stdin);
    freopen("10.out","w",stdout);
#endif

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, min(a[i], b[i]));

        int cnt = b[i];

        for (int j = i - 1; j >= 0; j--) {
            if (a[j] < a[i])
                break;
            cnt += b[j];
        }
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i])
                break;
            cnt += b[j];
        }

        if (cnt >= a[i])
            res = max(res, a[i]);
    }

    cout << res << endl;

    return 0;
}