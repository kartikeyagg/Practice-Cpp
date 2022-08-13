#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> vec = {2,3,5};

int rec1(int a,int b,map<int,map<int,int>> &mp){

    // cout<<"for a and b "<<a<<" "<<b<<endl;
    // base condition
    // check if equal
    if(a == b){
        return 0;
    }
    if(mp.find(a)!=mp.end() && mp[a].find(b) != mp[a].end()){
        return mp[a][b];
    }
    int res = 1e9+1;
    // int flag =0;
    // for (int i = 0; i < 4; i++)
    // {   
    //     if(a%vec[i] != 0) continue;

    //     for (int j = 0; j < 4; j++)
    //     {   
    //         if(i ==0 && j== 0) continue;
    //         if(b%vec[j] ==0){
    //             // flag =1;
    //             res = min(res,1+rec1(a/vec[i],b/vec[j])); // multiply here
    //         }
    //     }
        
    // }
    for (int i = 0; i < 3; i++)
    {
        if(a%vec[i] == 0){

            res = min(res,1+rec1(a/vec[i],b,mp));
        }
        if(b%vec[i] == 0){
            res = min(res,1+rec1(a,b/vec[i],mp));
        }
    }
    if(mp.find(a) == mp.end()){

        mp[a] = {{b,res}};

    }
    else{
        mp[a][b] =res;
    }


    return res;
}
int main()
{
    int a,b;
    cin>>a>>b;
    map<int,map<int,int>> mp;
    ll res = rec1(a,b,mp);
    if(res>1e9) cout<<"-1"<<endl;
    else cout<<res<<endl;
    cout<<endl;
    return 0;
}