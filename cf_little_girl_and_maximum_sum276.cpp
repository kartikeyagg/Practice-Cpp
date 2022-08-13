#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod ll(1e9+7)


int main()
{
    // ios_base::sync_with_stdio(false); 
    ll n,q;
    cin>>n>>q;
    vector<ll> vec(n);
    for (ll i = 0; i < n; i++)
    {
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    vector<ll> starter(n+1,0);
    vector<ll> ender(n+1,0);
    vector<ll> ans(n+1,0);
    ll a,b;
    for (ll i = 0; i < q; i++)
    {
        cin>>a>>b;
        starter[a]+=1;
        ender[b]+=1;
    }
    ll sum1 =0;
    vector<ll> pref;
    vector<ll> suff;
    for (ll i = 0; i < n+1; i++)
    {
        sum1+=starter[i];
        pref.push_back(sum1);
    }
    sum1 =0;
    for (ll i = 0; i < n+1; i++)
    {
        sum1+=ender[i];
        suff.push_back(sum1);
    }
    // cout<<"pref array is "<<endl;
    // for(auto x: pref){
    //     cout<<x<<" ";
    // }cout<<endl;
    // cout<<"suff array is "<<endl;
    // for(auto x: suff){
    //     cout<<x<<" ";
    // }cout<<endl;

    for (ll i = 1; i < n+1; i++)
    {
        ans[i]=pref[i]-suff[i-1];
    }
    ans.erase(ans.begin());

    // cout<<"ans array is "<<endl;
    // for(auto x: ans){
    //     cout<<x<<" ";
    // }cout<<endl;

    // ans.erase(ans.begin());
    sort(ans.begin(),ans.end());

    ll res =0;

    for (ll i = 0; i < n; i++)
    {
        res+=(vec[i]*ans[i]);
    }
    
    cout<<res<<endl;

    cout<<endl;
    return 0;
}