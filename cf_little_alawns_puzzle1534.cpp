#include<bits/stdc++.h>
using namespace std;
#define mod 1e9+7
#define ll long long
int pmodulo(int a, int b, int n){
    long long x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n; // multiplying with base
        }
        y = (y*y) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}
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
    for (int i = 0; i < n; i++)
    {
        make(i,vec);
    }
    vector<int> size1(n+1); // size
    vector<int> ar1(n);

    for (int i = 0; i < n; i++)
    {
        cin>>ar1[i]; 
        ar1[i]--;   
    }
    // vector<int> ar2(n);
    for (int i = 0; i < n; i++)
    {
        // cin>>ar2[i];   
        cin>>a;
        a--;
        Union(a,ar1[i],vec,size1); 
    }
    int count =0;
    for (int i = 0; i < n; i++)
    {
        // if(find(i,vec) == i){
        if(vec[i] == i){
            count++;
        }

    }
    // cout<<" \ncount is "<<count<<endl;
    // cout<<"ans is "<<pmodulo(2,count,mod)<<endl;
    // cout<<"\n ## \n";
    cout<<pmodulo(2,count,mod)<<endl;
    
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