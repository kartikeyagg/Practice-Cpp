#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

ll rec1(vector<int> &vec,vector<ll> &sumv,int m,int k,int nt,int n,int i,vector<vector<ll>> &memo){
    // sumv size if n+1
    if(i>n || i+m-1>n){
        return 0;
    }
    if(memo[i][k]!=-1){
        return memo[i][k];
    }
    ll take=0,not_take=0;
    // if(nt>0){
    not_take = rec1(vec,sumv,m,k,nt-1,n,i+1,memo);
    // }
    if(k>0)
    {take = sumv[i+m-1]-sumv[i-1]+rec1(vec,sumv,m,k-1,nt,n,i+m,memo);}


    return memo[i][k]=max(take,not_take);

}

int main()
{
    ios_base::sync_with_stdio(false); 
    
    int n,m,k;
    cin>>n>>m>>k;
    int inp;
    vector<int> vec;
    // vec.push_back(0);
    for (int i = 0; i < n; i++)
    {
        cin>>inp;
        vec.push_back(inp);
    }
    int nt = n- m*k;
    ll sum1=0;
    vector<ll> sumv;
    sumv.push_back(0);
    for (int i = 0; i < n; i++)
    {
        sum1+=vec[i];
        sumv.push_back(sum1);
    }
    vector<vector<ll>> memo(n+2,vector<ll>(k+1,-1));
    // start i from 1 
    ll res = rec1(vec,sumv,m,k,nt,n,1,memo);
    // cout<<"the result is "<<res<<endl;
    cout<<res<<endl;
    cout<<endl;
    return 0;
}