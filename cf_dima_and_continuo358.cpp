#include<bits/stdc++.h>
using namespace std;
#define mod 1e9+7
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    
    int n;
    cin>>n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin>>vec[i];
    }
    if(n<=2){
        cout<<"no"<<endl;
        return 0;
    }
    int minx ;//= 1e7;
    int maxx ;//= -1e7;

    
    minx = min(vec[0],vec[1]);
    maxx = max(vec[0],vec[1]);

    int x1,x2,x3,x4;

    for (int i = 0; i < n-1; i++)
    {   
        x1 = min(vec[i],vec[i+1]);
        x2 = max(vec[i],vec[i+1]);
        for (int j = i+1; j < n-1; j++)
        {
            x3 = min(vec[j],vec[j+1]);
            x4 = max(vec[j],vec[j+1]);
        }

        if(x1<x3 && x3<x2 && x2<x4 ){
            cout<<"yes"<<endl;
            return 0;
        }
        else if(x3<x1 && x1<x4 && x4<x2){
            cout<<"yes"<<endl;
            return 0;
        }
        
    }
    
    
    cout<<"no \n";

    // cout<<endl;
    return 0;
}