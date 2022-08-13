#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    
    ll n,m;
    cin>>n;
    ll a;
    vector<pair<ll,ll>> vec(n);
    ll w =0;
    for (ll i = 0; i < n; i++)
    {
        cin>>a;
        vec[i] = {a,w};
        w++;

    }
    cin>>m;

    ll k =0;
    ll mxheight =0;
    ll v,h;
    for (ll i = 0; i < m; i++)
    {
        cin>>v>>h;
        v--;
        k = max(v,k);
        mxheight = max(mxheight,vec[k].first);
        // cout<<"ans is ";
        cout<<mxheight<<endl;
        vec[k] = {mxheight+h,vec[k].second};
        mxheight+=h;
    }

    cout<<endl;
    return 0;
}