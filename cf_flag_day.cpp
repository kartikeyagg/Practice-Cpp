#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> color(n,-1);

    int a,b,c;
    vector<int> arr(3,0);
    vector<int> temp;
    for (int j = 0; j < m; j++)
    {   
        temp.clear();
        cin>>a>>b>>c;
        a--;b--;c--;
        for (int i = 0; i < 3; i++)
        {
            arr[i] =0;
        }

        if(color[a]!=-1){
            arr[color[a]] = 1;
        }
        else temp.push_back(a);
        if(color[b]!=-1){
            arr[color[b]] = 1;
        }
        else temp.push_back(b);

        if(color[c]!=-1){
            arr[color[c]] = 1;
        }
        else temp.push_back(c);

        for (int i = 0; i < 3; i++)
        {
            if(arr[i] == 0){
                color[temp.back()] = i;
                temp.pop_back();

            }
        }
        

    }
    for(auto x: color){
        cout<<x+1<<" ";
    }cout<<endl;

    // cout<<endl;
    return 0;
}