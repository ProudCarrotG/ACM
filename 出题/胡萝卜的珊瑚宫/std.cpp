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

int W;
int ans = 0;

struct node {
    int w;
    vector<int> son;
};
int idx = 0;

vector<node> tr(1e5 + 10);

void build() {
    int num = 0;
    int now = idx;
    cin >> tr[now].w >> num;

    for (int i = 0; i < num; i++) {
        idx++;
        tr[now].son.push_back(idx);
        build();
    }
}

void dfs(int now) {
    for (int i = 0; i < tr[now].son.size(); i++) {
        dfs(tr[now].son[i]);
    }

    vector<int> sonw;
    int tot = 0;
    for (int i = 0; i < tr[now].son.size(); i++) {
        int son = tr[now].son[i];
        tot += tr[son].w;
        sonw.push_back(tr[son].w);
    }

    sort(sonw.begin(), sonw.end());
    int id = sonw.size() - 1;

    while (tot > W) {
        ans++;
        tot -= sonw[id];
        id--;
    }

    tr[now].w += tot;

    ans += tr[now].w / W;
    tr[now].w = tr[now].w % W;
}

void solve() {
    cin >> W;

    build();

    dfs(0);

    cout << ans + (tr[0].w ? 1 : 0) << endl;
}

void solve1() {
    int n;
    cin >> n;
    int tot = 0;
    int x, tmp;
    while (cin >> x >> tmp)
        tot += x;
    cout << (tot - 1) / n + 1 << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    // freopen(".in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

    int tt = 1;
    //  cin >> tt;
    while (tt--)
        solve();

    return 0;
}