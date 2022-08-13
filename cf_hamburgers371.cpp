#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool check(vector<int> &ps,vector<int> &ns,ll key,ll rub,vector<int>&count){

    // ns is present pieces
    // count is pieces required to make 1;
    // ps is price per piece;
    ll h,t,v;
    ll z =0;
    for (int i = 0; i < 3; i++)
    {
        // t =max(z,key - ns[i]/count[i] );
        // h = ns[i]%count[i];
        // v = t*count[i];
        // v = v - h;
        // v = max(z,v);

        t= key*count[i];
        t = max(t - ns[i],z);

        rub-= t*ps[i];

        if(rub<0){
            return 0;
        }


    }
    
return 1;

}

int main()
{
    string s;
    cin>>s;
    vector<int> ns(3,0);
    vector<int> ps(3,0);
    // for
    int n = s.size();
    for (int i = 0; i < 3; i++)
    {
        cin>>ns[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cin>>ps[i];
    }
    ll rub;
    cin>>rub;
    vector<int> count(3,0);
    ll maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i] == 'B'){
            count[0]++;
        }
        else if(s[i] == 'S'){
            count[1]++;
        }
        else{
            count[2]++;
        }
    }
    // cout<<"count is "<<endl;
    // for(auto x: count) cout<<x<<" ";
    // cout<<endl;
    // maxi = max(count[0],max(count[1],count[2]));
    maxi = max(ns[0],max(ns[1],ns[2]));

    ll high = rub+10+maxi;
    // cout<<"high is "<<high<<endl;
    ll low = 0,mid;
    while(high-low > 1){

        mid = low+(high-low)/2;

        if(check(ps,ns,mid,rub,count)){
            low = mid;
        }
        else{
            high = mid-1;
        }

    }
    if(check(ps,ns,high,rub,count)){
        cout<<high<<endl;
    }
    else{
        cout<<low<<endl;
    }
    cout<<endl;
    return 0;
}