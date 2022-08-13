#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000000

ll dig_sum(int a){

    int sum =0;
    while(a>0){

        sum+=a%10;
        a = a/10;

    }
    // cout<<"sum is "<<sum<<endl;
    return sum;
}

int main()
{
    ll a,b,c;

    cin>>a>>b>>c;
    int count =0;
    ll x =1;
    vector<ll> ans;
    ll t;
    while(x<=81){

        t =(b*(pow(x,a))) +c;
        if(t>1e9) {
            x++;continue;}
        if(dig_sum(t) == x) 
        {count++;
        ans.push_back(t);}
        x++;
    }
    sort(ans.begin(),ans.end());

    cout<<count;
    cout<<endl;
    for(auto x: ans) cout<<x<<" ";
    cout<<endl;
    return 0;
}

/*
while(x<mod)
    {
        cout<<x<<endl;
        if(x-c<0){
            x++;
            continue;
        }
        if((x-c)%b !=0){
            x++;
            continue;
        }

        if(x == b*(pow(dig_sum(x),a)) +c){
            ans.push_back(x);
            count++;
        }
        x++;
        

    }
    cout<<count<<endl;
    for (int i = 0; i < count; i++)
    {
        cout<<ans[i]<<" ";
    }
    */