#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

ll rec1(int n,int i,int prev,vector<vector<int>> &memo){

    if(i >=n) return 1;

    if(memo[i][prev]!=-1 ){
        return memo[i][prev];
    }

    ll res = 0;
    if(i!=0 && i!=n-1 && prev!=1){ //pick d; and update d;

        res+=(1*rec1(n,i+1,1,memo))%mod;
    
    }
    if(prev == 1){

        res+=(3*rec1(n,i+1,0,memo)%mod)%mod;

    }
    else{
        res+=(2*rec1(n,i+1,0,memo)%mod)%mod;
    }

    return memo[i][prev] =res%mod;

}

int main()
{
    ios_base::sync_with_stdio(false); 
    
    int n;
    cin>>n;
    if(n == 1){
        cout<<"0"<<endl;
        return 0;
    }
    n--;
    vector<vector<int>> memo(n+1,vector<int> (2,-1));
    ll res = rec1(n,0,1,memo)%mod;
    
    cout<<res<<endl;
    cout<<endl;
    return 0;
}