#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

void solve(){


    int n;
    cin>>n;

    vector<pair<int,int>> vec;
    int a,b;
    pair<int,int> x,y,z,q;
    for (int i = 0; i < n; i++)
    {
        cin>>a>>b;
        vec.push_back({a,b});
    }

    int xmax = 0,ymax =0,zmin = 0,qmin =0;

    for (int i = 0; i < n; i++)
    {
        a = vec[i].first;
        b = vec[i].second;
        if(a>xmax){
            xmax = a;
            x = vec[i];
        }
        if(b>ymax){
            ymax = b;
            y = vec[i];
        }
        if(a<zmin){
            zmin = a;
            z = vec[i];
        }
        if(b<qmin){
            qmin = b;
            q = vec[i];
        }
    }
    
    int ans =0;

    // if(xmax >0){
    //     ans+=xmax;
    // }
    ans+= abs(0-x.first)+abs(0-x.second);
    ans+= abs(x.first-y.first)+abs(x.second-y.second);
    ans+= abs(z.first-y.first)+abs(z.second-y.second);
    ans+= abs(z.first-q.first)+abs(z.second-q.second);
    ans+= abs(0-q.first)+abs(0-q.second);
    // cout<<"ans is ";
    cout<<ans<<endl;
    return;

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