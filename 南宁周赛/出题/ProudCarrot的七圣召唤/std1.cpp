#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using namespace std;

#ifdef LOCAL
#include "/home/zhangah/vimcp/cp-library/debug.h"
#else
#define dbg(...)
#endif

using ll = int64_t;
using ld = long double;
using db = double;
using str = string;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pli = pair<ll, int>;
using pd = pair<ld, ld>;

#define ar array
using vi = vector<int>;
using vd = vector<db>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;

#define si(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ins insert

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, n) for (int i = (a); i < (n); i++)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define FORd(i, a, n) for (int i = (n)-1; i >= a; i--)
#define trav(a, v) for (auto& a : v)
#define uid(a, b) uniform_int_distribution<int>(a, b)(mt)

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

template <class T, class U>
bool ckmin(T& a, U b) {
    return a > b ? a = b, true : false;
}
template <class T, class U>
bool ckmax(T& a, U b) {
    return a < b ? a = b, true : false;
}

const char nl = '\n';
const int MX = 100000;

template <int MOD_>
struct modnum { /*{{{*/
    static constexpr int MOD = MOD_;
    static_assert(MOD_ > 0, "MOD must be positive");

    int v;

    static int minv(int a, int m) {
        a %= m;
        assert(a);
        return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
    }

   public:
    modnum()
        : v(0) {}
    modnum(ll v_)
        : v(int(v_ % MOD)) {
        if (v < 0)
            v += MOD;
    }
    explicit operator int() const { return v; }
    friend std::ostream& operator<<(std::ostream& out, const modnum& n) { return out << int(n); }
    friend std::istream& operator>>(std::istream& in, modnum& n) {
        ll v_;
        in >> v_;
        n = modnum(v_);
        return in;
    }

    friend bool operator==(const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator!=(const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum inv() const {
        modnum res;
        res.v = minv(v, MOD);
        return res;
    }
    friend modnum inv(const modnum& m) { return m.inv(); }
    modnum neg() const {
        modnum res;
        res.v = v ? MOD - v : 0;
        return res;
    }
    friend modnum pow(modnum a, ll p) {
        modnum ans = 1;
        assert(p >= 0);
        while (p) {
            if (p & 1)
                ans *= a;
            a *= a;
            p /= 2;
        }
        return ans;
    }
    friend modnum neg(const modnum& m) { return m.neg(); }

    modnum operator-() const {
        return neg();
    }
    modnum operator+() const {
        return modnum(*this);
    }

    modnum& operator++() {
        v++;
        if (v == MOD)
            v = 0;
        return *this;
    }
    modnum& operator--() {
        if (v == 0)
            v = MOD;
        v--;
        return *this;
    }
    modnum& operator+=(const modnum& o) {
        v += o.v;
        if (v >= MOD)
            v -= MOD;
        return *this;
    }
    modnum& operator-=(const modnum& o) {
        v -= o.v;
        if (v < 0)
            v += MOD;
        return *this;
    }
    modnum& operator*=(const modnum& o) {
        v = int(ll(v) * ll(o.v) % MOD);
        return *this;
    }
    modnum& operator/=(const modnum& o) {
        return *this *= o.inv();
    }

    friend modnum operator++(modnum& a, int) {
        modnum r = a;
        ++a;
        return r;
    }
    friend modnum operator--(modnum& a, int) {
        modnum r = a;
        --a;
        return r;
    }
    friend modnum operator+(const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator-(const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator*(const modnum& a, const modnum& b) { return modnum(a) *= b; }
    friend modnum operator/(const modnum& a, const modnum& b) { return modnum(a) /= b; }
}; /*}}}*/
using mi = modnum<998244353>;
using vmi = vector<mi>;
using vpmi = vector<pair<mi, mi>>;

void __print(mi x) {
    cerr << x.v;
}
int A[100010][20];
mi dp[100010][20];

void solve() {
    freopen(".in", "r", stdin);

    int N, M;
    cin >> N >> M;
    F0R(i, N) {
        F0R(j, M) {
            cin >> A[i][j];
        }
    }
    F0R(i, N)
    F0R(j, M)
    dp[i][j] = 0;
    F0R(i, M)
    dp[0][i] = 1;
    FOR(i, 1, N) {
        F0R(j, M) {
            F0R(k, M) {
                if (A[i][k] != A[i - 1][j]) {
                    dp[i][k] += dp[i - 1][j];
                }
            }
        }
    }
    mi ans = 0;
    F0R(i, M)
    ans += dp[N - 1][i];
    cout << ans << nl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(12);

    int T = 1;
    //   cin >> T;

    while (T--) {
        solve();
    }
    return 0;
}