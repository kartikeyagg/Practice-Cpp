#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    
    string s;
    cin>>s;
    if(stoll(s)>=0){
        cout<<s<<endl;
        return 0;
    }
    int n =s.size();
    ll t,k;
    t = stoll(s.substr(0,n-1));
    k = stoll(s.substr(0,n-2)+s.substr(n-1,1));

    // cout<<"t and k are "<<t<<" "<<k<<endl;

    cout<<max(t,k);

    cout<<endl;
    return 0;
}