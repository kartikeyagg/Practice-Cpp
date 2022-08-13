#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){

    int n,h,m;
    cin>>n>>h>>m;
    int k,t;
    k= h*60+(m);

    int a,b;
    int x;
    int ans = (23*60)+59;
    for (int i = 0; i < n; i++)
    {
        cin>>a>>b;
        t = a*60 + b;

        x= t-k;

        if(x<0){

            x = ((24*60-(k)) +t);

        }

        ans = min(ans,x);

    }
    // cout<<"\n # ";
cout<<ans/60<<" "<<ans%60<<endl;
return;


}

int main()
{
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    

    cout<<endl;
    return 0;
}