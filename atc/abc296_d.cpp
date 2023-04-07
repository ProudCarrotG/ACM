#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
signed main()
{
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

    int n,m;
    cin>>n>>m;
    int ans=LLONG_MAX;
    for(int i=1;i<=n;i++)
    {
        int x = (m+i-1)/i;
        if(x<=n) ans = min(ans,i*x);
        if(i>x) break;
    }
    if(ans == LLONG_MAX)
        cout<<-1<<endl;
    else  
        cout<<ans<<endl;


    return 0;
}