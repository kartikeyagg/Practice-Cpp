#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    int n,m;
    cin>>n>>m;

    vector<vector<int>> vec(n,vector<int>(m,0));
    int maxt = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>vec[i][j];
            maxt = max(maxt,vec[i][j]);
        }
        
    }
    int maxs = maxt+300;

    vector<int> prim(maxs+1,1);
    int maxprime = 0;
    for (int i = 2; i < maxs+1; i++)
    {
        if(prim[i] == 0){
            continue;
        }
        for (int j = 2*i; j < maxs+1; j+=i)
        {
            prim[j] = 0;
        }
        
    }
    set<int> st ;
    vector<int> primv;
    for (int i = 2; i < maxs+1; i++)
    {
        if(prim[i] == 0) continue;
        // st.insert(i);
        primv.push_back(i);
        maxprime = max(maxprime,i);
    }
    // cout<<"primv is "<<endl;
    // for(auto x: primv){
    //     cout<<x<<" ";
    // }cout<<endl;
    int t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            t = *lower_bound(primv.begin(),primv.end(),vec[i][j]);
            vec[i][j] =t-vec[i][j];
        }
        
    }

    // cout<<"vec is "<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout<<vec[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<int> row(n,0);
    vector<int> column(m,0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            row[i]+= vec[i][j];
            column[j]+= vec[i][j];
        }
        
    }
    int ans = min(*min_element(row.begin(),row.end()),*min_element(column.begin(),column.end()) );
    cout<<ans;
    cout<<endl;
    return 0;
}