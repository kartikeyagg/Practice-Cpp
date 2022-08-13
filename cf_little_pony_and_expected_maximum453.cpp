#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define inpv(x)       \
    for (auto &i : x) \
    cin >> i
#define outv(x)      \
    for (auto i : x) \
    cout << i << " "
#define all(x) x.begin(), x.end()
#define ld long double
#define ll long long
#define ull unsigned long long
#define db double
using namespace __gnu_pbds;
using namespace std;
 
const int N =  1000000007;
 
const int m = 1e8;
 
ll nc3(ll n){
    return n*(n-1)*(n-2)/6;
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int cases=1;
    // cin>>cases;
    while(cases--){
        double m,n;
        cin>>m>>n;
 
        double ans  = m;
        for(int i = 1;i<m;i++){
            ans -= pow(i/m,n);
        }
        
        cout<<fixed<<setprecision(8)<<ans;
        
    }
    return 0;
        
}