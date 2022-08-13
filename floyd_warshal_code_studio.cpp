#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long
#define inf int(1e9)

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges){

    // vector<vector<int>> g(n,vector<int>(0));

    int a,b;
    int w;
    vector<vector<int>> g(n,vector<int> (n,inf));
    for (int i = 0; i < m; i++)
    {
        // cin>>a>>b>>w;
        a = edges[i][0];
        b = edges[i][1];
        w = edges[i][2];
        a--;
        b--;
        g[a][b] = w;
    }
    for (int i = 0; i < n; i++)
    {
        g[i][i] =0;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(g[i][k] == inf || g[k][j] == inf){
                    continue;
                }
                g[i][j] = min(g[i][j] , g[i][k]+g[k][j]);

            }
            
        }
        
    }
    
    src--;
    dest--;
    return g[src][dest];


}

void solve(){
    int n,m,src,dest;
    cin>>n>>m>>src>>dest;
    vector<vector<int>> edges;
    int u,v,w;
    for (int i = 0; i < m; i++)
    {
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    int res = floydWarshall(n,m,src,dest,edges);

    cout<<"ans is ";
    cout<<res<<endl;
    return;    
}

int main()
{
    ios_base::sync_with_stdio(false); 
    
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    

    cout<<endl;
    return 0;
}