#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

bool cmp(pair<ll,ll> &a,pair<ll,ll> &b){

    if(a.second == b.second){
        a.first<b.first;
    }
    return a.second<b.second;
}

int main()
{
    // ios_base::sync_with_stdio(false); 
    
    ll n,mx,avg;
    cin>>n>>mx>>avg;
    vector<pair<ll,ll>> vec;
    ll a,b;
    ll sum1 = 0;
    for (ll i = 0; i < n; i++)
    {
        cin>>a>>b;
        vec.push_back({a,b});
        sum1+=a;
    }
    sort(vec.begin(),vec.end(),cmp);
    ll counter =0;
    sum1 = avg*n - sum1;
    // cout<<"sum1 is "<<sum1<<endl;
    ll h =0;
    ll temp;
    while(sum1>0 && h<n){

        if(sum1 - (mx -vec[h].first) >=0){

            sum1 -= (mx -vec[h].first);
            counter+=((mx -vec[h].first)*vec[h].second);

        }
        else{
            temp  = sum1;
            sum1 =0 ;
            counter+=(temp*(vec[h].second));
        }
    h++;
    }
    // cout<<"ans is ";
    cout<<counter<<"\n";
    cout<<endl;
    return 0;
}