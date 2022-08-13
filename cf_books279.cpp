#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    int n,m;
    cin>>n>>m;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin>>vec[i];
    }
    int sum1 =0;
    vector<int> suff;
    suff.push_back(0);

    for (int i = 0; i < n; i++)
    {
        sum1+=vec[i];
        // suff[i] = sum1;
        suff.push_back(sum1);
    }
    
    // cout<<"suff is "<<endl;
    // for(auto x:suff){
    //     cout<<x<<" ";
    // }cout<<endl;

    int low =0,high = 1;
    int ans =0;
    while(high<=n){

        if(suff[high]-suff[low] <=m){

            ans= max(ans,high-low);
            high++;

        }
        else{
            low++;
        }

    }
    cout<<ans;

    cout<<endl;
    return 0;
}