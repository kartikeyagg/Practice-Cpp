#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    
    int a;
    int n;
    cin>>n;
    vector<int> vec(n+1,0);
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        vec[a] = i+1;
    }
    
    for (int i = 1; i <= n; i++)
    {
        cout<<vec[i]<<" ";
    }

    cout<<endl;
    return 0;
}