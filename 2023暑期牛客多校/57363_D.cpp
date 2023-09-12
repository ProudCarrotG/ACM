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

void solve0() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 0;

    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            vector<int> tmp;
            for (int i = l; i <= r; i++) {
                tmp.push_back(arr[i]);
            }
            sort(tmp.begin(),tmp.end());
            int flag=1;
            for(int i=0;l+i<=r;i++)
            {
                if(tmp[i] == arr[l+i])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)
            {
                cout<<l<<' '<<r<<endl;
                ans++;
            }
        }
    }

    cout<<ans<<endl;
}

void solve(){
    int n;
    cin>>n;
    int ans = 0;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    

    for(int i=0;i<n;i++)
    {
        int Max = 0;
        for(int j=i;j<n;j++)
        {
            if(arr[j] < Max)
            {    ans++;
                cout<<i<<' '<<j<<endl;
            }
            Max = max(Max,arr[j]);
        }
    }

    cout<<ans<<endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}