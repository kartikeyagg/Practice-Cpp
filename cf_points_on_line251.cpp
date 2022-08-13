#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long
 
ll factorial(ll n) {
      if(n == 0)
      return 1;
    ll factorial = 1;
    for (ll i = 2; i <= n; i++)
        factorial = factorial * i;
    return factorial;
}
 
ll nCr(ll n, ll r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}
 
int main()
{
    // ios_base::sync_with_stdio(false); 
    
    ll n,d;
    cin>>n>>d;
    if(n <3){
        cout<<"0"<<endl;
        return 0;
    }
 
    ll a;
    vector<ll> vec(n);
    for (ll i = 0; i < n; i++)
    {
        cin>>vec[i];
        // cin>>a;
    }
    vector<ll> :: iterator iter;
    ll t;
    ll prevt = 0;
    ll k =0;
    ll ans =0;
    ll curr =0 ;
    for (ll i = 0; i < n; i++)
    {
            
        iter = lower_bound(vec.begin(),vec.end(),vec[i]+d);
        // if(!(iter == vec.end())){ 
        if(iter == vec.end() || *iter > vec[i]+d ) 
        {
            iter--;
        }
        t = distance(vec.begin(),iter);
        // cout<<"t is "<<t<<endl;
        // t gives the index
        // if(t<=prevt){
        //     continue;
        // }
        prevt = t;
        // k = t-i;
        k = t-i;
        if(k>=2)
        {
            // ans += nCr(k,3);
            // curr = (k*(k-1)*(k-2))/6;
            // curr = (k*(k-1))/3;
            curr = (k*(k-1))/2;
            ans+=curr;
        }
        // }
        // update prevt; done
    }
    
    cout<<ans<<endl;
 
    cout<<endl;
    return 0;
}