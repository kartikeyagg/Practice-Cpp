#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{   

    ios_base::sync_with_stdio(false); 
    int x,y,a,b;
    cin>>x>>y>>a>>b;
    int pb = b;
    vector<pair<int,int>> res;
    // cout<<"the ans is "<<" \n";
    while(a<=x){

        b=pb;
        a = max(a,b+1);
        a = min(a,x);
        for (int i = b; i < a && i<=y; i++)
        {
            // cout<<a<<" "<<i<<" \n";
            res.push_back({a,i});
        }
        a++;
    }
    cout<<res.size()<<"\n";
    for(auto x:res){
        cout<<x.first<<" "<<x.second<<"\n";
    }

    cout<<"\n";
    return 0;
}