#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

ll rec1(ll n,ll k,int flag,int d,vector<vector<ll>>& memo){

    if(n<0){
        return 0;
    }
    if(n==0 && flag == 1){
        return 1;
    }

    if(memo[n][flag]!=-1){
        return memo[n][flag];
    }

    ll res =0;

    for (int i = 0; i < k; i++)
    {
        if(i+1 >=d){
            res+=(rec1(n-(i+1),k,1,d,memo)%mod);
        }
        else res+=(rec1(n-(i+1),k,flag,d,memo)%mod);
    }
    
    return memo[n][flag]=(res%mod);

}

int main()
{
    ios_base::sync_with_stdio(false); 
    
    ll n,k,d;
    cin>>n>>k>>d;

    // n = n-d;
    
    vector<vector<ll>> memo(n+1,vector<ll>(2,-1));

    ll res = rec1(n,k,0,d,memo);

    // cout<<"the answer is ";
    cout<<res%mod;

    cout<<endl;
    return 0;
}