#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){

    int n;
    cin>>n;

    vector<int> vec(n+1,0);
    vector<int> arr(n,0);

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int k=n-1;
    for (k = n-1; k >= 0; k--)
    {
        if(vec[arr[k]] == 0){
            vec[arr[k]]++;
        }
        else break;
    }
    // cout<<"\n # ";
    cout<<k+1<<endl;
    return ;

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