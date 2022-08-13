#include<bits/stdc++.h>
using namespace std;
#define ll long long
// start with i = 1;
int rec1(int i,vector<int> &res,int target,vector<vector<int>> &memo){

    if(target == 0){
        return 1;
    }
    if(target <0 ) return 0;
    if(i <0) return 0;

    if(memo[target][i]!=-1){
        return memo[target][i];
    }

    int ans =0;
    res.push_back(i);
    int tk = rec1(i-1,res,target-i,memo);
    if(tk){
        return 1;
    }
    res.pop_back();
    tk = rec1(i-1,res,target,memo);
    if(tk) return 1;
    return memo[target][i]=0;
}

void solve(){

    int a;
    cin>>a;
    vector<int> res;
    vector<vector<int>> memo(a+1,vector<int>(10,-1));
    a = rec1(9,res,a,memo);
    sort(res.begin(),res.end());
    ll ans =0;
    for (int i = 0; i < res.size(); i++)
    {
        ans*=10;
        ans+=res[i];
    }
    // cout<<" \n #";
    cout<<ans<<endl;
    return ;

}

int main()
{
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    
    cout<<endl;
    return 0;
}