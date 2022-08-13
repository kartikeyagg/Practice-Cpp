#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    
    string s,t;

    cin>>s>>t;
    int ns  =s.size(),nt = t.size();
    if(ns!=nt){
        cout<<"NO"<<endl;
        return 0;
    }
    int flag =0;
    int flag2=0;
    for (int i = 0; i < ns; i++)
    {
        if(s[i]!='0'){
            flag =1;
        }
    }
    for (int i = 0; i < ns; i++)
    {
        if(t[i]!='0'){
            flag2 =1;
        }
    }
    // cout<<"the flags are "<<flag<<" "<<flag2<<" \n";
    if(flag == flag2){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}


    // int i = ns-1;
    // int count =0;
    // int count2 =0;
    // while(i>0){

    //     count =0;
    //     count2=0;
    //     count+=s[i]-'0';
    //     count+=s[i-1]-'0';

    //     count2 +=t[i]-'0';
    //     count2 +=t[i-1]-'0';

    //     if(s[i] == t[i]&&s[i-1] == t[i-1]){

    //     }

    //     else if(count2 == count && count ==0){

    //     }
    //     else if(count == 2 && count2 == 1){

    //         s[i] = t[i];
    //         s[i-1] = t[i-1];

    //     }
    //     else if(count ==1 && count2 ==2){
    //         s[i] = t[i];
    //         s[i-1] = t[i-1];

    //     }

    //     else{
    //         cout<<"NO"<<endl;
    //         return 0;
    //     }

    //     i--;

    // }