#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    
    string s;
    cin>>s;
    int n,ns;
    ns = s.size();
    s = '@'+s;
    cin>>n;
    string t;
    string temp;
    vector<int> str_size;
    for (int i = 0; i < n; i++)
    {
        cin>>temp;
        str_size.push_back(temp.size());
        t+='#';
        t+=temp;
    }
    int nt = t.size();

    vector<vector<int>> matrix(nt,vector<int> (ns+1,0));
    vector<int> mx(ns+1,0);
    vector<int> sx(ns+1,-1);
    int s_counter =0;
    for (int i = 1; i < nt; i++)
    {   
        if(t[i] == '#') {
            
            s_counter++;
            continue;

        }
        for (int j = 1; j < ns+1; j++)
        {
            if(t[i] == s[j]){
                matrix[i][j] = matrix[i-1][j-1]+1;
                if(matrix[i][j] == str_size[s_counter]){
                    // mx[j] = max(mx[j],matrix[i][j]); // just store the s counter also
                    if(matrix[i][j] > mx[j])  {

                        mx[j] = matrix[i][j];
                        sx[j] = s_counter;

                    }                  
                }
            }
        }
        
    }
    // cout<<"\n mx is \n";
    // for(auto x: mx){
    //     cout<<x<<" ";
    // }cout<<endl;
    // cout<<"\n sx is \n";
    // for(auto x: sx){
    //     cout<<x<<" ";
    // }cout<<endl;
    vector<int> dp(ns+1,1e9);
    vector<int> dp_prev(ns+1,0);
    n = ns+1;
    for (int i = 0; i < n; i++)
    {
        dp_prev[i] = i;
    }
    
    dp[ns] = 0;
    if(mx[ns] == 0){
        cout<<"\n#####\n";
        cout<<"-1"<<endl;
        return ;
    }
    for (int i =ns; i >=0; i--)
    {
        for (int j = 1; j < mx[i]; j++)
        {
            // dp[i-j] = min(dp[i-j],dp[i]+1);
            if(dp[i-j]>dp[i]+1){
                dp[i-j]=dp[i]+1;
                dp_prev[i-j] = i;
            }
        }
        
    }
    // cout<<"dp is "<<endl;
    // for(auto x: dp){
    //     cout<<x<<" ";
    // }cout<<endl;

    // cout<<"dp_prev is "<<endl;
    // for(auto x: dp_prev){
    //     cout<<x<<" ";
    // }cout<<endl;
    cout<<"\n###########"<<endl;
    if(dp[1]!=1000000000)
    cout<<dp[1]<<endl;
    else
    {   
        cout<<"\n###\n";
        cout<<"-1"<<endl;
        return ;
    }
    int g=1;
    int gh;
    while(dp_prev[g]!=g){
        gh =g;
        g = dp_prev[g];
        cout<<sx[g]+1<<" ";
        cout<<gh<<" ";
        cout<<endl;
    }
    

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