#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9)
#define ll long long

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {

    vector<int> distance(n,mod);
    distance[src -1] = 0;
    int u,v,w;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < m; j++)
        {   
            u = edges[j][0];
            v = edges[j][1];
            w = edges[j][2];
            if(distance[u-1] == mod) continue;
            if(distance[u-1]+w<distance[v-1]){
                distance[v-1] = distance[u-1]+w;
            }
        }
        
    }
    return distance[dest-1];
}

void solve(){

    int n,m,src,dest;
    cin>>n>>m>>src>>dest;

    vector<vector<int>> edges;

    int u,v,w;
    // cin>>u>>v>>w;
    for (int i = 0; i < m; i++)
    {
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    int res = bellmonFord(n,m,src,dest,edges);
    cout<<"the result is "<<res;
    return ;
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