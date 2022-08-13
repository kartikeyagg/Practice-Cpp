#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

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
    queue<int> q;
    q.push(0);
    color[0] = 0;
    int t;
    int f;
    while(!q.empty())
    {

        t = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {   
            f = vec[t][i]; 
            if(f == 0) continue;
            if(color[i] !=-1){

                if(color[i] == color[t]){
                    
                    return 0; // not bipartite
                }

            }
            else{
                color[i] = (color[t]+1)%2;
                q.push(i);
            }
            
        }
    }
    return 1;

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