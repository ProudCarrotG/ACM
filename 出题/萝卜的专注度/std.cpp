#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    freopen("data//10.in","r",stdin);
    freopen("data//10.out","w",stdout);
    int n;
    cin>>n;
    int k = 500;
    for(int i=0,x,op;i<n;i++)
    {
        cin>>op>>x;
        if(op == 0)
            op = -1;
        k += op * x;

        if(k<=0)
        {
            cout<<"yes"<<endl;
            return 0;
        }
    }

    cout<<"no"<<endl;
    cout<<k<<endl;
}