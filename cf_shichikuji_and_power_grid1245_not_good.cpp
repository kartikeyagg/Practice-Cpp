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
    // ios_base::sync_with_stdio(false); 

    ll n;
    cin>>n; // the num of cities
    vector<ll> parent(n,0);
    vector<ll> size1(n+1,1);
    for (ll i = 0; i < n; i++)
    {
        make(i,parent);
    }

    vector<pair<ll,ll>> coordinates;
    
    ll a,b;

    for (ll i = 0; i < n; i++)
    {
        cin>>a>>b;
        coordinates.push_back({a,b});
    }
    // vector<ll> power(n);
    vector< pair<ll,ll> > power(n);
    for (ll i = 0; i < n; i++)
    {
        // cin>>power[i];
        cin>>a;
        power[i] = make_pair(a,i);
    }
    sort(power.begin(),power.end());
    vector<ll> kv(n);
    vector<pair<ll,ll>> ans; // for the op
    vector<ll> pvec; // for the op
    for (ll i = 0; i < n; i++)
    {
        cin>>kv[i];
    }

    ll e1 = 1e14;
    ll mini= -1;
    ll t;
    ll sum1 =0;
    vector<ll> visited(n,0);
    for (ll k = 0; k < n; k++)
    {   
        int i = power[k].second;
        // if(visited[i] == 1) continue;
        e1 = 1e14;
        mini = -1;
        for (ll j = 0; j < n; j++)
        {
            if(i == j){
                t = power[k].first;
                if(t<e1){
                    e1 = t;
                    mini = i;
                }
            }
            else{
                if(find(i,parent) == find(j,parent)) continue;
                t = abs(coordinates[i].first-coordinates[j].first) + abs(coordinates[i].second-coordinates[j].second);
                t = t*(kv[i]+kv[j]);
                if(t<e1){
                    e1 = t;
                    mini = j;
                }
            }
        }

        if(mini ==-1)
        {
            continue;
        }
        if(mini != i && mini!=-1){

            Union(mini,i,parent,size1);
            ans.push_back({i,mini});
            visited[mini] = 1;
        }
        else{
            pvec.push_back(i);
        }
        sum1=sum1+e1;
        visited[i] = 1;
    }
    // cout<<" ans is "<<endl;
    cout<<sum1<<" \n";
    cout<<pvec.size()<<" \n";
    for(auto x: pvec){
        cout<<x+1<<" ";
    }cout<<endl;

    cout<<ans.size()<<" \n";
    
    for(auto &x: ans){

        cout<<x.first+1<<" "<<x.second+1<<" \n";
        
    }
    
    cout<<endl;
    return 0;
}