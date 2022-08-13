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

    // this function finds the parent of given node
    // also perform the depth compression
    // by joining the llermediate nodes directly to
    // the parent
    if(node == vec[node]) return node;
    return vec[node] = find(vec[node],vec);

}
void Union(ll a, ll b, vector<ll> &vec,vector<ll> &size1){

    a = find(a,vec);
    b = find(b,vec);
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
    ios_base::sync_with_stdio(false); 
    
    int n;
    cin>>n;

    vector<ll> vec(n+1,0);
    vector<ll> size1(n+1,0);
    for (int i = 0; i < n+1; i++)
    {
        make(i,vec);
    }

    vector<pair<ll,ll>> coordinates;

    ll a,b;
    for (int i = 0; i < n; i++)
    {
        cin>>a>>b;
        coordinates.push_back({a,b});
    }
    // the coordinates of the last element is not here

    vector<ll> power(n);

    for (int i = 0; i < n; i++)
    {
        cin>>power[i];
    }
    

    vector<ll> k_vec(n);
    for (int i = 0; i < n; i++)
    {
        cin>>k_vec[i];
    }
    
    vector<pair<ll,pair<ll,ll>>> edges;
    ll t;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            t= abs(coordinates[i].first - coordinates[j].first)+abs(coordinates[i].second-coordinates[j].second);
            t = t*(k_vec[i]+k_vec[j]);
            edges.push_back({t,{i,j}});
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        t= power[i];
        edges.push_back({t,{n,i}});
    }
    
    sort(edges.begin(),edges.end());
    // vector<pair<ll,pair<ll,ll>>> ans;
    vector<pair<ll,ll>> ans;
    vector<pair<ll,ll>> pans;
    ll sum1 =0;
    int ne = edges.size();
    ll u,v,wt;
    for (int i = 0; i < ne; i++)
    {
        wt= edges[i].first;
        u = edges[i].second.first;
        v = edges[i].second.second;

        if(find(u,vec)== find(v,vec)){
            continue;
        }
        Union(u,v,vec,size1);
        if(u == n || v == n){
            pans.push_back({u,v});
        }
        else ans.push_back({u,v});
        sum1+=wt;
        
    }
    cout<<sum1<<endl;
    cout<<pans.size()<<"\n";
    for(auto x: pans){
        if(x.first == n){
            cout<<x.second+1;
        }
        else cout<<x.first+1;
    cout<<" ";
    }
    cout<<endl;

    int nx = ans.size();
    cout<<nx<<endl;
    for (int i = 0; i < nx; i++)
    {
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
    }
    

    cout<<endl;
    return 0;
}