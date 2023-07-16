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

signed main()
{
#ifndef ONLINE_JUDGE
    freopen(".in","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

    int n;
    string s;
    string ans;
    cin>>n>>s;

    int flag1 = 0, flag2= 0;
    for(int i = 0;i<s.size();i++)
    {
        if(flag1 == 1 && s[i] == '|')
            flag2 = 1;
        if(s[i] == '|')
            flag1 = 1;
        if(s[i] == '*')
        {
            if(flag1 == 1 && flag2 == 0)
                ans = "in";
            else
                ans =  "out";
            
        }
    }

    cout<<ans<<endl;

    return 0;
}