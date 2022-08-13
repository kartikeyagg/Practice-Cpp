#include<bits/stdc++.h>
using namespace std;
#define mod 1e9+7
#define ll long long

int main()
{
    int n;
    cin>>n;
    vector<vector<ll>> dist( n,vector<ll> (n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>dist[i][j];
        }
        
    }
    vector<int> del_order(n);
    for (int i = 0; i < n; i++)
    {
        cin>>del_order[i];
        --del_order[i];
    }
    
    reverse(del_order.begin(),del_order.end());
    vector<ll> ans;
    ll sum = 0;
    for (int k = 0; k < n; k++)
    {   sum =0;
        int kv = del_order[k];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {   
                // if()
                dist[i][j] = min(dist[i][j],dist[i][kv]+dist[kv][j]);
                // sum+=dist[i][j];

            }

            
        }

        for (int i = 0; i <=k; i++)
        {
            for (int j = 0; j <=k; j++)
            {
                sum+= dist[del_order[i]][del_order[j]];
            }
            
        }
        
        ans.push_back(sum);
        
    }
    reverse(ans.begin(),ans.end());
    for(auto x: ans){
        cout<<x<<" ";
    }
    

    cout<<endl;
    return 0;
}

 