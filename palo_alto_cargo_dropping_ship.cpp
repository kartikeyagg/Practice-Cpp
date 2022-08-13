#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long 

void solve(){

    ll ans =0;
    int n;
    cin>>n;
    int a;
    cin>>a;
    if(n == 1){
        cout<<a<<endl;
        return ;
    }
    int preva = a;
    int flag = -1;
    int len =0;
    int small=a;
    int t;
    for (int i = 1; i < n; i++)
    {
        cin>>a;
        if(flag ==-1){
            if(a>preva){
                flag = 1;
            }
            else{
                flag = 0;
            }
            len =2;
            preva = a;
            continue;
        }
        if(flag == 0) 
        {  
            if(a<preva){
                len++;
            }
            else {
                // add in the answer
                t = (len*preva);
                // cout<<"adding a"<<t<<endl;
                ans+=t;
                len =2;
                flag = 1;
                small = preva; 
            }
        }
        // if(flag == 1)
        else if(flag == 1) {

            if(a>preva){
                len++;
            }
            else{
                t= (len*small);
                // cout<<"adding b "<<t<<endl;
                ans+=t;
                len = 2;
                flag =0;

            }

        }


        preva = a;
    }
    if(flag == 0){
        t = len*preva;
        ans+=(len*preva);
        // cout<<"adding 1  "<<t<<endl;

    }
    else{
        t = len*small;
        ans+=(len*small);
        // cout<<"adding 2 "<<t<<endl;

    }
    // cout<<"ans is "<<endl;
    cout<<ans<<endl;
    // cout<<"#"<<ans<<"#"<<endl;
    return ;

}

int main()
{   

    ios_base::sync_with_stdio(false); 

    ll t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    
    // cout<<endl;
    return 0;
}