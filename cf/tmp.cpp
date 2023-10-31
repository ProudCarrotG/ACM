#include<bits/stdc++.h>
using namespace std;
#define int long long
#define LL long long
#define PII pair<int,int>
#define umap unordered_map
#define x first
#define y second
#define endl "\n"
#ifndef ONLINE_JUDGE
#define debug(x) cout<<#x<<' '<<x<<endl;
#define fg cout<<"-----------------"<<endl;
#else
#define debug(x)
#define fg
#endif

void solve(){

    multiset<int> st;
    st.insert(2);
    st.insert(2);
    st.insert(3);
    st.insert(3);
    st.insert(4);

    debug(st.size() - (distance(st.begin(),st.lower_bound(3))+st.count(3)));
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen(".in","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

    int tt = 1;
//  cin >> tt;
    while(tt--)
        solve();

    return 0;
}