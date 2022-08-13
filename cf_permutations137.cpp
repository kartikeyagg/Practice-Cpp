#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 

    ll sum1=0;
    int n;
    cin>>n;
    vector<int> vec;
    int a;
    // set<int> st;
    vector<int> arr(n+1,0);
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        vec.push_back(a);
        sum1+=a;
        if(a>=1 && a<=n){
            // st.insert(a);
            arr[a] = 1;
        }
    }
    // ll t = ((n)*(n+1))/2;
    
    // cout<<"ans is ";
    // cout<<n - st.size();

    int count = 0;
    for(auto x: arr){
        if(x){
            count++;
        }
    }
    cout<<n-count;
    cout<<"\n";
    return 0;

}