#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll fun1(ll l, ll r)
{

    ll sum=0;
    queue<ll>q;

    q.push(4);
    q.push(7);
    ll prev = l-1;
    ll t;
    ll k;
    ll n;
    while(!q.empty() && prev<r){

        t = q.front();
        n = t;
        if(t>=l){
            q.pop();
            q.push(t*10 +4);
            q.push(t*10 +7);
            k = q.front();
            t = min(t,r);
            
            sum+= n*(t-prev);
            l = k;
            prev= t;
        }
        else{
            q.pop();
            q.push(t*10 +4);
            q.push(t*10 +7);
        }

    }

    return sum;

}

ll next1(ll l,ll r){

    ll sum=0;
    queue<ll> q;
    q.push(4);
    q.push(7);

    // multiply from the difference of next number in queue;
    ll t ;
    ll k;
    while(!q.empty() && l<=r){
        t= q.front();
        // q.pop();
        if(t>=l){

            sum=sum+t;
            // k = max(r-1,*(q+1));
            // // q.pop();
            // k = max(r,q.front());
            
            cout<<"Summing  "<<t<<endl;
            l++;
            
        }
        else{

            q.pop();
            cout<<"poping "<<t<<endl;
            q.push(t*10 +4);
            q.push(t*10 +7);
            

        }

    }
    cout<<"sum is "<<sum<<endl;

    return sum;

}

int main()
{
    ll l,r;
    cin>>l>>r;
    // cout<<"fadsfad \n";
    ll f1 = fun1(l,r);
    cout<<f1<<endl;
    cout<<endl;
    return 0;
}