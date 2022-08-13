#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin>>n;
    int a;
    map<int,int> mp;
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        if(a == i){
            ans++;
            continue;
        }
        mp[a] = i;
    }
    if(mp.size()<2){
        cout<<ans<<endl;
        return 0;
    }
    int flag=0;
    for(auto x: mp){

        if( (mp[x.second]) == x.first ){
            flag=1;
            break;
        }

    }
    cout<<ans+1+flag<<endl;
    cout<<endl;
    return 0;
    
}