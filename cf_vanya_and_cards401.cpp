#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    int n,x;
    cin>>n>>x;

    int a;
    ll sum1=0;
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        sum1+=a;
    }
    sum1 = abs(sum1);
    int ans =0;
    ans += sum1/x;
    sum1 = sum1%x;
    if(sum1 !=0)
    ans++;
    cout<<ans;
    cout<<"\n";
    return 0;
}