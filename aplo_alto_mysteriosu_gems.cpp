#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    
    ll t;
    cin>>t;

    vector<ll> vec = {8,10,18,36,64};

    for (int i = 0; i < 1001; i++)
    {
        vec.push_back(((vec[2+i]%mod)+(vec[3+i]%mod)+(vec[4+i]%mod))%mod);
    }
    int n;
    for (int i = 0; i < t; i++)
    {
        cin>>n;
        cout<<vec[n-1]<<endl;
    }
    
    
    cout<<endl;
    return 0;
}