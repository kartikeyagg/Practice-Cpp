#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    
    vector<int> vec(3,0);
    for (int i = 0; i < 3; i++)
    {
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    vector<int> arr = vec;
    // int high = vec[2];
    // int low = 0;
    // int mid;
    // while(high-low>1){

    //     mid= low+(high-low)/2;

    // }

    ll ans =0;
    ans +=vec[0];

    vec[1]-=vec[0];
    vec[2]-=vec[0];
    vec[0] =0;

    ans+=vec[1]/3;
    ans+=vec[2]/3;


    ll res=0;
    ll tk =0;
    for (int i = 1; i < 3; i++)
    {   
        if(arr[0]!=arr[i])
        {res+=arr[i]/3;
        arr[i] = arr[i]%3;}
    }
    sort(arr.begin(),arr.end());
    
    res+=arr[0];
    int temp = arr[0];
    for (int i = 0; i < 3; i++)
    {
        arr[i]-=temp;
        res+=arr[i]/3;
    }
    

    cout<<max(res,ans);
    cout<<endl;
    return 0;
}