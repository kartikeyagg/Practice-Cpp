#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

void dfs1(int curr,vector<int>&visited,stack<int> &st,vector<vector<int>> &g){

    if(visited[curr]){
        return ;
    }
    visited[curr] = 1;
    int n = g[curr].size();
    for (int i = 0; i < n; i++)
    {
        dfs1(g[curr][i],visited,st,g);
    }
    
    st.push(curr);
    return; 

}
void dfs2(int curr,vector<int> &visited,vector<int> &res,vector<vector<int>> &t_g){

    if(visited[curr]) return ;
    visited[curr] = 1;
    int n = t_g[curr].size();
    for (int i = 0; i < n; i++)
    {
        dfs2(t_g[curr][i],visited,res,t_g);
    }
    res.push_back(curr);
    return;
}


vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges){
    
    int m = edges.size();
    vector<vector<int>> g(n,vector<int>(0));

    for(auto x: edges){

        g[x[0]].push_back(x[1]);

    }

    stack<int> st;
    vector<int> toposort;
    vector<int> visited(n,0);
    vector<vector<int>> ans;
    vector<vector<int>> t_g(n,vector<int> (0));
    for (int i = 0; i < n; i++)
    {
        dfs1(i,visited,st,g);
    }
    int t;
    while(!st.empty()){

        t = st.top();
        st.pop();

        toposort.push_back(t);

    }
    // cout<<"the toposort is"<<endl;
    // for(auto x: toposort){
    //     cout<<x<<" ";
    // }cout<<endl;
    // cout<<"##";
    // now transposing the graph;
    for(auto x: edges){

        t_g[x[1]].push_back(x[0]);

    }

    visited = vector<int>(n,0);
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        temp.clear();
        dfs2(toposort[i],visited,temp,t_g);
        
        if(temp.size()>0){
            // reverse(temp.begin(),temp.end());
            ans.push_back(temp);
        }

    }

    return ans;

}

void solve(){


    int n,e;
    cin>>n>>e;

    int a,b;
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        cin>>a>>b;
        edges.push_back({a,b});
    }
    vector<vector<int>> ans = stronglyConnectedComponents(n,edges);
    cout<<"\nthe ans is ";
    for(auto x: ans ){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

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