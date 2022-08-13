#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    
    int n,m;
    ll k;
    cin>>n>>m;
    cin>>k;
    vector<vector<ll>> vec(n,vector<ll>(m,0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>vec[i][j];
        }
    }

    queue<pair<ll,pair<int,int>>> q;
    // queue<ll> qt;
    q.push({vec[0][0],{0,0}});
    ll t;
    int x,y;
    // qt.push(vec[0][0]);
    ll count =0;
    while(!q.empty()){

        t = q.front().first;
        x = q.front().second.first;
        y = q.front().second.second;
        q.pop();
        if(x == n-1 && y == m-1 && t==k){
            count++;
            continue; //
        }
        if(x<n-1){
            q.push({t^vec[x+1][y],{x+1,y}});
        }
        if(y<m-1){
            q.push({t^vec[x][y+1],{x,y+1}});
        }

    }
    
    // cout<<"ans is \n";
    cout<<count<<"\n";
    cout<<endl;
    return 0;
}