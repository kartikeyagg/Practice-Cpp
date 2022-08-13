#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{   

    ios_base::sync_with_stdio(false); 

    int n,k;
    cin>>n>>k;
    

    vector<int> vec(n,0);

    for (int i = 0; i < n; i++)
    {
        cin>>vec[i];
    }
    if(n<k){
        cout<<"-1 -1"<<endl;
        return 0;
    }
    
    int low= 0;
    int high = 1;

    map<int,int> mp;
    mp[vec[low]]++;
    // mp[high]++;

    while(high<n && low <high){

        if(mp.size()<k){
            mp[vec[high]]++;
            high++;
        }
        else break;

    }
    if(mp.size()<k){
        cout<<"-1 -1"<<endl;
        return 0;
    }
    // cout<<"mp is "<<endl;
    // for(auto x:mp){
    //     cout<<x.first<<" "<<x.second<<endl;;
    // }cout<<endl;;
    
    while(low<high)
    {

        if(mp[vec[low]] == 1){

            break;

        }

        else{
            mp[vec[low]]--;
            low++;
        }
    }
    cout<<low+1<<" "<<high<<endl;
    cout<<endl;
    return 0;
}