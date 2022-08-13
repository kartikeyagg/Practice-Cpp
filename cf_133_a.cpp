#include<bits/stdc++.h>
using namespace std;
#define mod 1e9+7
#define ll long long

void solve(){

    int k;
    cin>>k;
    int ans =0 ;
    k = abs(k);
    if(k == 1)
    {
        cout<<"2"<<endl;
        return;
    }
    ans+=k/3;
    k = k%3;
    if(k == 2 || k ==1){
        ans++;
    }
    // cout<<"ans is "<<endl;
    cout<<ans<<endl;
    return ;
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