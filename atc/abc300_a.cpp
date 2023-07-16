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

    int n;
    cin>>n;
    int a,b;
    cin>>a>>b;
    a += b;

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x == a)
        {
            cout<<i<<endl;
            return;
        }
    }
    cout<<-1<<endl;
    
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