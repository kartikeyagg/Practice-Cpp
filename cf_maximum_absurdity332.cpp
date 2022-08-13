#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    int n,k;
    cin>>n>>k;
    vector<int> vec(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>vec[i];
    }
    ll s1=0;
    vector<ll> sum_vec(1,0);
    for (int i = 0; i < n; i++)
    {
        s1+=vec[i];
        sum_vec.push_back(s1);
    }
    vector<ll> arr;
    int h=0;
    int ns1 = sum_vec.size();

    while(h+k<ns1){

        arr.push_back(sum_vec[h+k]-sum_vec[h]);
        
        
        h++;
    }

    // cout<<"arr is  "<<endl;
    // for(auto x:arr){
    //     cout<<x<<" ";
    // }cout<<endl;

    int na = arr.size();
    vector<ll> suff(na,0);
    ll mxi = -1;
    ll mxind = 0;
    for (int i = na-1; i >=0; i--)
    {
        // mxi = max(mxi,arr[i]);
        if(mxi<=arr[i]){
            mxi = arr[i];
            mxind = i;
        }
        suff[i] = mxind;
    }
    
    ll ans = -1;
    h=0;
    ll a=0,b =0;
    while(h+k<na){

        // ans = max(ans,suff[h+k]+suff[h]);
        // can 'k' be out of brakcets

        // if(ans<arr[suff[h+k]]+arr[suff[h]]){
        if(ans<arr[suff[h+k]]+arr[h]){
            // ans=suff[h+k]+suff[h];
            ans=arr[suff[h+k]]+arr[h];
            // a = h;
            // b = h+k;
            a= h;
            b=suff[h+k];
        }

        h++;

    }
    // cout<<"ans is ";
    // cout<<ans;
    // cout<<endl;
    // cout<<"a and b are ";
    cout<<a+1<<" "<<b+1;
    cout<<endl;
    return 0;
}