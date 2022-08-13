#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long
map<int,int> ans;
int tans = 1e9;
bool rec1(int i,vector<int> &vec,int n,map<int,int> &mp,vector<vector<int> > &memo)
{   
    if(n==0) 
    {
        if(mp[4]+mp[7] < ans[4]+ans[7])
        {   

            ans[4] = mp[4];
            ans[7] = mp[7];
        }
        else if(mp[4]+mp[7] == ans[4]+ans[7])
        {
            if(ans[4] < mp[4])
            {
                ans[4] = mp[4];
                ans[7] = mp[7];
            }
        }
        return 1;
    }
    if(n<0) return 0;
    if(i>=2)
    {
        return 0;
    }
    if(memo[n][i]!=-1)
    {
        return memo[n][i];
    }
    mp[vec[i]]++;
    bool pick = rec1(i,vec,n-vec[i],mp,memo);
    mp[vec[i]]--;
    // if(pick){
        
    //     return pick;

    // }
    // not picking now
    bool npick = rec1(i+1,vec,n,mp,memo);
    // if(pick) {
    //     return pick;
    // }
    return memo[n][i] = (pick|| npick);
}

int main()
{   

    ios_base::sync_with_stdio(false); 
    ans.clear();
    ans[4] = 1e9;
    ans[7] = 1e9;
    tans = 1e9;
    int n;
    cin>>n;
    vector<int> vec = {7,4};
    map<int,int> mp;
    // vector<int> memo(n+1,1);
    vector<vector<int> > memo(n+1,vector<int> (2,-1));
    bool t = rec1(0,vec,n,mp,memo);
    // cout<<" mp is "<<endl;
    // for(auto x: mp){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
    if(!t){
        cout<<"-1"<<endl;
        return 0;
    }
    if(ans.find(4)!=mp.end())
    {
        for (int i = 0; i < ans[4]; i++)
        {
            cout<<"4";
        }
        
    }
    
    if(ans.find(7)!=mp.end()){
        for (int i = 0; i < ans[7]; i++)
        {
            cout<<"7";
        }  
    }

    cout<<endl;
    return 0;
}