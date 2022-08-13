#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long
bool dfs(int curr,vector<int> &color,int n,vector<vector<int>> &vec){
    // return 1 when bipartite;
    // if(color[curr] !=-1){
    //     return 1;
    // }
    bool t;
    for (int i = 0; i < n; i++)
    {
        if(vec[curr][i] == 0) continue;
        if(color[i] == -1){
            color[i] = (color[curr]+1)%2;
            t = dfs(i,color,n,vec);
            if(!t) return t;
        }
        else if(color[i] == color[curr]){
            return 0;
        }
    }
    return 1;
}

bool solve(){

    int n;
    cin>>n;
    vector<vector<int>> vec(n,vector<int>(n,0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>vec[i][j];
        }
        
    }
    vector<int> color(n,-1);
    // queue<int> q;
    // q.push(0);
    color[0] = 0;
    int t;
    int f;
    bool b;
    // for (int i = 0; i < n; i++)
    // {
    //     // b = dfs()
    //     // if(color[])
    //     b= dfs(i,color,n,vec);
    //     if(b) return b;
    // }
    b = dfs(0,color,n,vec);
    
    return b;

}

int main()
{
    ios_base::sync_with_stdio(false); 

    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        bool t =solve();
        cout<<"ans is ";
        cout<<t<<endl;
    }
    cout<<endl;
    return 0;
}