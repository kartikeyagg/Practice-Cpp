#include<bits/stdc++.h>
using namespace std;
#define mod 1e9+7
#define ll long long
void make(int node,vector<int> &vec){
    // initially every node is parent of its own
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
    if(size1[a]< size1[b]){
        swap (a,b);
    }
    vec[b] = a; // parent of b is a; 
    size1[a] +=size1[b];
    // size1[b] = size1[a];
    return ;
}
void solve(){

    int n,m;
    cin>>n>>m;
    vector<int> vec(n,0);
    for (int i = 0; i < n; i++)
    {
        vec[i] = i;
    }
    vector<int> size1(n+1,0);
    // make disjoint set for languages
    // in the parent matrix;
    map<int,unordered_set<int> >mp;

    unordered_set<int> st = {};
    int k,a,b;
    int flag =0;
    for (int i = 0; i < n; i++)
    {
        cin>>k;
        for (int j = 0; j < k; j++)
        {
            cin>>a;
            a--;
            flag = 1;
            if(mp.find(a) == mp.end()){
                mp[a] = st;
                mp[a].insert(i);

            }
            else{
                mp[a].insert(i);
            }
        }
        
    }

    // for(auto x:mp){
    //     cout<<x.first<<" : ";
    //     for(auto y : x.second){
    //         cout<<y<<" ";
    //     }cout<<endl;
    // }

    for(auto x: mp)
    {

        // st = x.second;
        for (auto i = x.second.begin(); i !=x.second.end(); i++)
        {
           for(auto j = i;j!=x.second.end();j++){

                if(j == i){
                    continue;
                }

                Union(*i,*j,vec,size1);

           }
        }
        
        
    }
    int count =0;
    for (int i = 0; i < n; i++)
    {
        if(vec[i] == i){
            count++;
        }
    }

    // if(count == m)    
    // cout<<"\n#\n";
    if(flag == 1)
    cout<<max(count-1,0)<<endl;
    else cout<<count<<endl;
    return ;

}

int main()
{
    solve();

    cout<<endl;
    return 0;
}