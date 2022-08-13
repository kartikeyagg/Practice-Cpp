#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

// void solve(){

//     int n;
//     cin>>n;

//     vector<int> vec(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin>>vec[i];
//     }
    
//     int minx = 1e9;
//     int maxx  = -1;
//     vector<int> pref(n);
//     vector<int> prefmin(n);

//     for (int i = 0; i < n; i++)
//     {
//         maxx = max(maxx,vec[i]);
//         pref[i] = maxx;
//         minx = min(minx,vec[i]);
//         prefmin[i] = minx;
//     }
//     maxx  = -1;
//     minx = 1e9;
//     vector<int> suff(n);
//     vector<int> suffmin(n);
//     for (int i = n-1; i >=0; i--)
//     {
//         maxx = max(maxx,vec[i]);
//         suff[i] = maxx;
//         minx = min(minx,vec[i]);
//         suffmin[i] = minx;
//     }

//     int c1=0,c2=0;
    
//     for (int i = 0; i < n; i++)
//     {
//         if(suff[i] == pref[i]) c1++;
//         if(suffmin[i] == prefmin[i]) c2++;
//     }
    
//     if(c1>=2 || c2>=2){

//         cout<<"NO"<<endl;

//     }
//     else cout<<"YES"<<endl;
    
//     return;

// }
void solve(){

    int n;
    cin>>n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin>>vec[i];
    }
    if(vec[0]<vec[n-1]){

        int j=1;
        while(j<n && vec[j]>vec[j-1]){
            j++;
        }


    }

}    

int main()
{
    ios_base::sync_with_stdio(false); 

    int t =1;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    
    

    cout<<endl;
    return 0;
}