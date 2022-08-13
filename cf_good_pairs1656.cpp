#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{   
    
    int t;
    cin>>t;
    
    int mint = 1e9+1,maxt =0;
    int mini = -1, maxi = -1;
    int n,inp;
    for (int i = 0; i < t; i++)
    {   
        mint = 1e9+1;maxt =0;
        mini = -1; maxi = -1;
        cin>>n;
        for (int j = 0; j < n; j++)
        {
            cin>>inp;
            if(inp>maxt){
                maxt = inp;
                maxi = j;
            }
            if( inp<mint){
                mint = inp;
                mini = j;
            }
        }
        // cout<<"# ";
        cout<<mini+1<<" "<<maxi+1<<endl;
        
    }
    

    cout<<endl;
    return 0;
}