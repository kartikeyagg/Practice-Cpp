#include<bits/stdc++.h>
using namespace std;
#define mod 1e9+7
#define ll long long

void solve(){

    int k;
    cin>>k;
    
    vector<int> vec;
    for (int i = 0; i < k; i++)
    {
        vec.push_back(i+1);
    }
    cout<<k<<endl;
    for(auto x:vec){
            cout<<x<<" ";
        }cout<<endl;
    for (int i = 0; i < k-1; i++)
    {
        swap(vec[i],vec[i+1]);
        for(auto x:vec){
            cout<<x<<" ";
        }cout<<endl;
    }
    
    
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