#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen(".in","r",stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;

    vector<int> edge[n+1];

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    
    queue<pair<int,int>> q;
    q.push({1,-1});
    vector<int> tmp(n+1,0);
    tmp[1]=1;

    while(q.size())
    {
        auto now = q.front();
        q.pop();

/*
        if(tmp[now.first])
        {
            cout<<"No"<<endl;
            return 0;
        }

        tmp[now.first]=1;
*/

        if(edge[now.first].size()>=3)
        {
            cout<<"No"<<endl;
            return 0;
        }

        for(int i=0;i<edge[now.first].size();i++)
        {
            auto next = edge[now.first][i];
            if(next!=now.second)
                if(tmp[next]==0)
                   tmp[next]=1,q.push({next,now.first});
                else
                {
                    cout<<"No"<<endl;
                    return 0;
                }
        }
    }

//    cout<<"!!!!"<<endl;

    for(int i=1;i<=n;i++)
        if(tmp[i]!=1)
        {
            cout<<"No"<<endl;
            return 0;
        }

    cout<<"Yes"<<endl;
    return 0;
}
