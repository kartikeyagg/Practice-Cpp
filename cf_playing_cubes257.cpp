#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    int r,b;
    cin>>r>>b;
    if(r<b) swap(r,b);
    int a,c;
    a = b;
    c = r-1;
    // if(c<a) swap(c,a);
    cout<<c<<" "<<a;
    cout<<endl;
    return 0;
}