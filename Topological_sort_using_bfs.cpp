#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

vector<int> topologicalSort(vector<vector<int>> &edges, int n, int m)  {
    
    // Write your code here
    vector<vector<int>> g(n,vector<int>(0));
    int x,y;
    vector<int> indegree(n,0);
    for (int i = 0; i < m; i++)
    {
//         cin>>x>>y;
        x = edges[i][0];
        y = edges[i][1];
//         x--;
//         y--;
        g[x].push_back(y);
        indegree[y]++;
    }

//     vector<int> visited(n,0);
//     stack<int>st;
//     for (int i = 0; i < n; i++)
//     {
//         dfs(i,visited,st,g);
//     }

    vector<int> ans;
    int t;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    int f;
    int ng;
    while(!q.empty()){
        
        t = q.front();
        q.pop();
        ans.push_back(t);
        ng = g[t].size();
        for(int i=0;i<ng;i++){
            
            f = g[t][i];
            indegree[f]--;
            if(indegree[f] == 0){
                q.push(f);
            }
            
        }
        
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    

    cout<<endl;
    return 0;
}