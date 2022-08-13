#include<bits/stdc++.h>
using namespace std;
#define mod ll(1e9+7)
#define ll long long

ll rec1(map<ll,ll> &mp,map<ll,ll> :: iterator iter,ll t,map<ll,ll> &memo){

    if(iter == mp.end()){
        return 0;
    }
    for (ll j = 0; j < t; j++)
    {
        iter++;
        if(iter == mp.end()){
            return 0;
        }
        
    }

    if(memo.find(iter->first) != memo.end() ){

        return memo[iter->first];

    }

    // cout<<"the current element is "<<iter->first<<endl;
    ll take=0,not_take =0;
    // take = mp[i]+rec1(i+2,mp,n);
    t = 1;
    // cout<<"not take"<<endl;
    not_take = rec1(mp,iter,t,memo);
    map<ll,ll> :: iterator rt;
    rt = iter;
    rt++;
    // cout<<"#the current element is "<<iter->first<<endl;
    if(rt!=mp.end() && rt->first == (iter->first)+1){
        t++;
        // cout<<"323"<<endl;
    }
    // cout<<"take"<<endl;
    take = ((iter->first)*(iter->second))+rec1(mp,iter,t,memo);
    // cout<<"for element = "<<iter->first<<endl;
    // cout<<"not take and take are "<<not_take<<" "<<take<<endl;
    // cout<<" returning "<<max(take,not_take)<<endl;
    return memo[iter->first]=max(take,not_take);
}
// multiple times hai ek hi element toh?
// n*m (m is its count)
int main()
{
    ios_base::sync_with_stdio(false); 

    ll n;
    ll a;
    cin>>n;
    map<ll,ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin>>a;
        mp[a]++;
    }
    
    // cout<<"the map is "<<endl;
    // for(auto x:mp){

    //     cout<<x.first<<" "<<x.second<<endl;

    // }

    map<ll,ll> :: iterator iter;
    iter = mp.begin();
    // ll maxt = (--mp.end())->first;
    map<ll,ll> memo;
    ll res= rec1(mp,iter,0,memo);
    // cout<<"ans is ";
    cout<<res;

    cout<<endl;
    return 0;
}