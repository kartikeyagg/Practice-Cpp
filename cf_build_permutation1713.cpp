#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

void solve(){

    int n;
    cin>>n;
    int k = n-1;
    vector<int> res(n);
    float f;
    int h;
    // f = sqrt(9);
    // if(int(f) == f){
    //     cout<<"yes"<<endl;
    // }
    int tk;
    int y,u;
    while(k>=0){

        f = sqrt(k);
        if(int(f)==f){
            h = f;
        }
        else{
            h = f+0.99999;
        }
        h = h*h;
        // now h is the nearest perfect square bigger than current num

        tk = h-k;

        // tk should only be less than or equal to current num
        if(tk > k){
            cout<<"-1"<<endl;
            return;
        }
        y = k;
        u = tk;
        while(u<=k){
            res[u] = y;
            y--;
            u++;
        }

        k = tk-1;
    }
    
    // cout<<
    for(auto x: res){
        cout<<x<<" ";
    }cout<<endl;

    return;

}

int main()
{
    ios_base::sync_with_stdio(false); 
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    
    

    cout<<endl;
    return 0;
}