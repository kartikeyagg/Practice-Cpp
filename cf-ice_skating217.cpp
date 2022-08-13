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
    int n;
    cin>>n;
    int a,b;
    vector<int> vec(n); //parent
    vector<int> size1(n+1); // size
    for (int i = 0; i < n; i++)
    {
        make(i,vec);
    }
    int preva=-1,prevb=-1;
    int count =0;
    vector<pair<int,int>> mat;
    
    for (int i = 0; i < n; i++)
    {
        cin>>a>>b;
        mat.push_back({a,b});
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(mat[i].first == mat[j].first || mat[i].second == mat[j].second){
                Union(i,j,vec,size1);
            }
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        if(vec[i] == i){
            count++;
        }
    }
    // cout<<"\n ### \n";
    cout<<count-1<<endl;
    
    return ;
}

int main()
{
    int t=1;
    // cin>>t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    

    cout<<endl;
    return 0;
}