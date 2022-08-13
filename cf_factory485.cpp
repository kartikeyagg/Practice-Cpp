#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    ll a,m;
    cin>>a>>m;
    ll r = a%m;
    // int pa = a;
    set<int> st;
    st.insert(r);
    while(r!=0){

        a = (a+r);
        r = a%m;
        
        if(st.insert(r).second == 0){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    cout<<endl;
    return 0;
}