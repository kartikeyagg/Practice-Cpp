#include<bits/stdc++.h>
using namespace std;
#define mod 1e9+7
#define ll long long
void make(int node,vector<int> &vec){
    // initiainty every node is parent of its own
    vec[node] = node;
    return ;
}

int find(int node, vector<int> &vec){

    // this function finds the root parent of given node
    // also perform the depth compression
    // by joining the intermediate nodes directly to
    // the parent
    if(node == vec[node]) return node;
    return vec[node] = find(vec[node],vec);

}
void Union(int a, int b, vector<int> &vec,vector<int> &size1){

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
void solve(){

    int n,k;
    cin>>n>>k;
    vector<int> vec(n,0);
    vector<int> size1(n,1);
    for (int i = 0; i < n; i++)
    {
        vec[i] = i;
    }
    // vector<int> visited(n,0);
    string s;
    cin>>s;
    int j;
    // cout<<"the parent array is"<<endl;
    // for(auto x:vec){
    //     cout<<x<<" ";
    // }cout<<endl;
    for (int i = 0; i < n; i++)
    {
        if(i-k>=0){
            Union(i,i-k,vec,size1);
        }
        j = n-i-1;
        if(j>=0 && j<n){
            Union(i,j,vec,size1);
        }
    }

    // cout<<"the parent array is"<<endl;
    // for(auto x:vec){
    //     cout<<x<<" ";
    // }cout<<endl;

    // now traverse the disjoint union
    // or form map of count array or vec of vec;
    vector<int> alpha(26,0);
    map<int,vector<int>> mp;
    int p;
    char c;
    for (int i = 0; i < n; i++)
    {   
        c = s[i];
        p = vec[i];
        while(vec[p]!=p){
            p = vec[p];
        }
        // while to find the main parent
        // c = s[p];
        if(mp.find(p) == mp.end()){
            mp[p] = alpha;
            mp[p][c-'a']+=1;
        }
        else{
            mp[p][c-'a']+=1;
        }
    }
    ll sum1 =0;
    ll ans =0;
    int maxi = 0;
    for(auto x:mp){
        sum1=0;
        maxi =0;
        
        for(auto y: x.second){
            maxi = max(maxi,y);
            sum1+=y;
        }

        ans+=sum1-maxi;

    }

    // cout<<"\nans is \n";
    cout<<ans<<endl;
    return ;
    
}

int main()
{
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    

    cout<<endl;
    return 0;
}

// if(visited[i] == 1) continue;
//         j = i;
//         while(j<n)
//         {

//             if(visited[j] == 1) continue;
//             Union(i,j,vec,size1);
//             j = j+k;
//             if(visited[n-1-i] != 1){
//                 visited[n-1-i] = 1;
//                 Union(s[n-i-1],i,vec,size1);
//             }
//             visited[j] = 1;
//         }
        
//         visited[i] = 1;