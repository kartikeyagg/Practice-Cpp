#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> val(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>val[i];
    }
    int u,v;
    ll ans =0;
    for (int i = 0; i < m; i++)
    {
        cin>>u>>v;
        u--;
        v--;
        ans+= min(val[u],val[v]);
    }
    
    cout<<ans;
    cout<<endl;
    return 0;
}