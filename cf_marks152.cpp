#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    int n,m;
    cin>>n>>m;

    string s;
    // pair<int,int> p = {0,0};
    // vector<pair<int,int>> arr(n);
    vector<vector<int>> arr(m,vector<int>(0));
    vector<int> maxr(m,0);
    int t;
    for (int i = 0; i < n; i++)
    {
        cin>>s;
        for (int j = 0; j < m; j++)
        {
            t = s[j]-'0';
            if(maxr[j]==t){
                arr[j].push_back(i);
            }
            else if(maxr[j]<t){
                maxr[j] = t;
                arr[j].clear();
                arr[j].push_back(i);
            }
            
        }
        

    }

    vector<int> av(n+1,0);
    // cout<<"arr is "<<endl;
    for(auto x: arr){
        for(auto y:x ){
            // cout<<y<<" ";
            av[y] = 1;
        }
        // cout<<"\n";
    }
    int count =0;
    for(auto x:av){
        if(x) count++;
    }
    cout<<count;
    cout<<endl;
    return 0;
}