#include <bits/stdc++.h>

using namespace std;

#define int long long

int rand(int l, int r) {
    return 1.0 * rand() / RAND_MAX * (r - l) + l;
}

int rand(int r) {
    return rand(1, r);
}

signed main() {
    srand(time(0));

    int tot = 0;

    int num = rand(1e5);
    // int num = 10;
    vector<int> son[num], val(num);

    val[0] = rand(1e9);
    for (int i = 1; i < num; i++) {
        int fa = rand(0, i - 1);
        son[fa].push_back(i);
        val[i] = rand(1e9);
        tot += val[i];
        // cout << i << ' ' << fa << endl;
    }

    // cout << tot << endl;
    int n = rand(max((int)1e5, tot / 1000));
    cout << n << endl;

    stack<int> q;
    q.push(0);
    while (q.size()) {
        int now = q.top();
        q.pop();

        cout << val[now] << ' ' << son[now].size() << endl;

        for (int i = 0; i < son[now].size(); i++) {
            q.push(son[now][i]);
        }
    }

    return 0;
}