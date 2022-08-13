#include<bits/stdc++.h>
using namespace std;
#define ll long long

set<int> st = {1,2,3,4,6,7,8,9};

void solve(){

    int n;
    cin>>n;
    int inp;
    int flag =0;
    int ans = 1;
    cin>>inp;
    if(st.find(inp)!=st.end()){
        flag = 1;
    }
    for (int i =1; i < n; i++)
    {
        cin>>inp;
        inp = inp%10;
        if( st.find(inp)!=st.end() ){

            if(flag != 1){

                ans =0;

            }

        }
        else if(flag == 1){
            ans =0;
        }
    }
    
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return ;
}

int main()
{
    int t;
    cin>>t;
    for (int i = 0; i <t; i++)
    {
        solve();
    }
    
    cout<<endl;
    return 0;
}