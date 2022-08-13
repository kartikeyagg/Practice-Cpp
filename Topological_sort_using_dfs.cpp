#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

void dfs(int curr,vector<int>&visited, stack<int> &st,vector<vector<int>> &g){

    if(visited[curr])
    {
        return ;
    }
    visited[curr] =1;
    int n = g[curr].size();
    for (int i = 0; i < n; i++)
    {
        dfs(g[curr][i],visited,st,g);
    }
    st.push(curr);
    return;

}

vector<int> topo_sort(int n,int m, vector<pair<int,int>> &edges){
    
    vector<vector<int>> g(n,vector<int>(0));
    int x,y;
    for (int i = 0; i < m; i++)
    {
        cin>>x>>y;
        x--;
        y--;
        g[x].push_back(y);
    }

    vector<int> visited(n,0);
    stack<int>st;
    for (int i = 0; i < n; i++)
    {
        dfs(i,visited,st,g);
    }

    vector<int> ans;
    int t;
    while(!st.empty()){
        t = st.top();
        st.pop();
        ans.push_back(t);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    

    cout<<endl;
    return 0;
}