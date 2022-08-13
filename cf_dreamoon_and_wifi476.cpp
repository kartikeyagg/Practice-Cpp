#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<int,map<int,int>>mp;
ll rec1(string &b, int i,int n,ll sum,ll rp,set<pair<int,int>> &st){

    // memoize it please

    if(i>=n) {
        if(sum==rp)return 1;
        else return 0;
    }
    
    if(b[i] != '?'){

        if(b[i] == '+'){
            return rec1(b,i+1,n,sum+1,rp,st);
        }
        else return rec1(b,i+1,n,sum-1,rp,st);

    }

    ll res =0;
    b[i] = '+';
    res += rec1(b,i+1,n,sum+1,rp,st);
    b[i] = '?';
    b[i] = '-';
    res += rec1(b,i+1,n,sum-1,rp,st);
    b[i] = '?';

    return res;
}

int main()
{
    string a,b;
    cin>>a>>b;
    int n = a.size();
    ll req_pos =0;

    for (int i = 0; i < n; i++)
    {
        if(a[i] == '+'){
            req_pos++;
        }
        else req_pos--;
    }
    ll q_count =0;
    for(auto x: b){
        if(x=='?'){
            q_count++;
        }
    }
    // map<int,map<int,int>>mp;

    set<pair<int,int>> st;

    ll res= rec1(b,0,n,0,req_pos,st);
    
    // cout<<res<<endl;
    if(res == 0) {
        cout<<0<<endl;
        return 0;
    }
    if(q_count == 0){
        cout<<res<<endl;
        return 0;
    }
    ll ex = pow(2,q_count);

    long double ans = res;
    cout<<fixed;
    cout<<setprecision(12);
    ans = ans/ex;
    cout<<ans;

    cout<<endl;
    return 0;
}