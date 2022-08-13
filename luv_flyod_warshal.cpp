#include<bits/stdc++.h>
using namespace std;
#define INF int(1e9+7)
#define ll long long

void floyd_warshall(vector<vector<int>> &vec){

    int n = vec.size();
    int m =n;
    
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                
                if(vec[i][k] == INF || vec[k][j] == INF) continue;
                else{
                    vec[i][j] = min(vec[i][k]+vec[k][j],vec[i][j]);
                }

            }
            
        }
        
    }
    return ;

}

int main()
{
    vector<vector<int>> vec = { {0,   5,  INF, 10},
                    {INF,  0,  3,  INF},
                    {INF, INF, 0,   1},
                    {INF, INF, INF, 0} };

    floyd_warshall(vec);

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            if(vec[i][j] == INF){
                cout<<"I ";
            }
            else cout<<vec[i][j]<<" ";
        }
        cout<<endl;
        
    }
    

    cout<<endl;
    return 0;
}