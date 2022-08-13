#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    int n,k;
    cin>>n>>k;
    int a;
    int count =0;
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        if(a<=5-k){
            count++;
        }
    }
    cout<<count/3;
    cout<<endl;
    return 0;
}