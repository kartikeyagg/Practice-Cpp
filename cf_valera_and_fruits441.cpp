#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n,v;
    cin>>n>>v;

    vector<int> vec(3003,0);
    vector<int> vec2(3003,0);

    int a,b;

    for (int i = 0; i < n; i++)
    {
        cin>>a>>b;
        vec[a]+= b;
        vec2[a+1]+= b;
    }
    int t,k,h;
    ll ans =0;
    for (int i = 0; i < 3003; i++)
    {   
        t = v;
        h = vec2[i];
        if(v<=vec2[i]){
            ans+=v;
            continue;
        }
        ans+=h;
        if(i>=3002) break;
        t-=h;
        k = min(t,vec[i]);
        ans+=k;
        vec2[i+1]-=k;
    }
    
    cout<<ans;

    cout<<endl;
    return 0;
}