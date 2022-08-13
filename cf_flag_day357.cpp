#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    
    int n,m;
    // vector<vector<int>> vec(n,vector<int>(0));
    cin>>n>>m;
    // unordered_set<int> st = {};
    unordered_set<int> st = {};
    vector<unordered_set <int> > vec(n,st);
    vector<int> color(n,-1);
    int a,b,c;

    for (int i = 0; i < m; i++)
    {
        cin>>a>>b>>c;
        a--;
        b--;
        c--;

        vec[a].insert(b);
        vec[a].insert(c);
        vec[b].insert(a);
        vec[b].insert(c);
        vec[c].insert(a);
        vec[c].insert(b);
        

    }
    cout<<"\ngraph is "<<endl;

    for (int i = 0; i < n; i++)
    {
        cout<<i<<": ";
        for(auto x: vec[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    

    vector<int> arr(3,0);

    for (int i = 0; i < n; i++)
    {   
        for (int j = 0; j < 3; j++)
        {
            arr[j]=0;
        }

        for(auto x: vec[i]){

            if(color[x] == -1){

                continue;

            }
            
            arr[color[x]] = 1;
            

        }
        cout<<"arr is "<<endl;
        for(auto x: arr){
            cout<<x<<" ";
        }cout<<endl;

        for (int j = 0; j < 3; j++)
        {
            if(arr[j] ==0 ){
                color[i] = j;
                break;
            }
        }
        

    }
    
    for (int i = 0; i < n; i++)
    {   
        if(color[i] == -1) cout<<"1 ";
        else cout<<color[i]+1<<" ";
    }
    



    cout<<endl;
    return 0;
}