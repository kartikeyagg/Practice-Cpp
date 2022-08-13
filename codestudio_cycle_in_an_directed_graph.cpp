#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

// true when cycle is there
bool dfs(int prev,vector<int> &visited,int curr,vector<vector<int>> &g,vector<int> &dfsvisited){
    
    if(visited[curr] == 1 ){
       
        return 0;
        
    }
    // if(prev != -1) visited[curr] = 1;
    visited[curr] = 1;
    dfsvisited[curr] = 1;
    int n = g[curr].size();
    bool t;
    for(int i=0;i<n;i++){
//         && prev!=g[curr][i]
        if(dfsvisited[g[curr][i]] == 1 ){
            return 1;
        }
        t = dfs(curr,visited,g[curr][i],g,dfsvisited);
        if(t) return t;
    }
    dfsvisited[curr] = 0;
    return 0;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    vector<vector<int>> g(n,vector<int> (0));
    int x,y;
    int m = edges.size();
    for(int i=0;i<m;i++){
        
        x = edges[i].first;
        y = edges[i].second;
        x--;
        y--;
        g[x].push_back(y);
//         g[y].push_back(x);
    }
    vector<int> visited(n,0);
    vector<int> dfsvisited(n,0);
// bool dfs(int prev,vector<int> &visited,int curr,vector<vector<int>> &g){
    
    for(int i=0;i<n;i++){
        
//         visited = vector<int>(n,0);
        
        if(dfs(-1,visited,i,g,dfsvisited))  return 1;
        
    }
    
//     return dfs(-1,visited,0,g);
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false); 

    int n,m;
    int k;
    cin>>k;
    int a,b;

    for (int i = 0; i < k; i++)
    {
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for (int i = 0; i < m; i++)
        {
            cin>>a>>b;
            edges.push_back({a,b});
        }
        int res = detectCycleInDirectedGraph(n,edges);

        cout<<"\nthe ans is ";
        cout<<res<<endl;
    }
    // cout<<endl;
    return 0;
}