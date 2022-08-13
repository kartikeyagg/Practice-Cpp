#include<bits/stdc++.h>
using namespace std;
#define mod 1e9+7
#define ll long long
void make(ll node,vector<ll> &vec){
    // initially every node is parent of its own
    vec[node] = node;
    return ;
}

ll find(ll node, vector<ll> &vec){

    // this function finds the root parent of given node
    // also perform the depth compression
    // by joining the llermediate nodes directly to
    // the parent
    if(node == vec[node]) return node;
    return vec[node] = find(vec[node],vec);

}
void Union(ll a, ll b, vector<ll> &vec,vector<ll> &size1){

    a = find(a,vec);
    b = find(b,vec);
    if(a == b) return;
    if(size1[a]< size1[b]){
        swap (a,b);
    }
    vec[b] = a; // parent of b is a; 
    size1[a] +=size1[b];
    // size1[b] = size1[a];
    return ;
}
int main()
{
    ll n;
    cin>>n;
    ll inp;
    vector<ll> vec(n,0);
    for (ll i = 0; i < n; i++)
    {
        cin>>inp;
        vec[i]= inp-1;
    }
    vector<ll> parent(n);
    for (ll i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    vector<ll> size1(n+1,1);
    size1[n] =0;
    for (ll i = 0; i < n; i++)
    {
        Union(i,vec[i],parent,size1);
    }
    vector<ll> arr;
    for (ll i = 0; i < n; i++)
    {
        if(parent[i] == i){

            arr.push_back(size1[i]);

        }
    }
    sort(arr.begin(),arr.end());
    ll ans =0;
    ll na = arr.size();
    if(na == 1){
        cout<<arr[0]*arr[0]<<endl;
        return 0;
    }
    ans = (arr[na-1]+arr[na-2]) * (arr[na-1]+arr[na-2]);

    for(ll i = na-3;i>=0;i--){
        ans+=(arr[i]*arr[i]);
    }
    cout<<ans<<endl;
    cout<<endl;
    return 0;
}