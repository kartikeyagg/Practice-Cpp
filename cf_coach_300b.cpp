#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long


void make(vector<int>&vec,int i){ //,vector<int> &size1

    vec[i] = i;
    // size1[i]= 1;
    return ;

}
int find(int a,vector<int> &vec){

    if(vec[a] == a) return a;

    return vec[a] = find(vec[a],vec);

}

bool Union(int a,int b,vector<int> &vec,vector<int> &size1){

    a = find(a,vec);
    b = find(b,vec);
    if(a==b) return 1;
    if(size1[a]+size1[b] >3){
        return 0;
    }
    if(size1[b]>size1[a]){
        swap(a,b);
    }
    vec[b] =a;
    size1[a]+=size1[b];
    return 1;
}
void solve(){

    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<int> vec(n,0);
    vector<int> size1(n+1,1);
    for (int i = 0; i < n; i++)
    {
        make(vec,i);
    }

    int a,b;
    int flag = 0;
    bool ub;
    int temp = -1;
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b;
        a--;
        b--;
        ub = Union(a,b,vec,size1);
        if(ub){
            
        }
        else{
            // flag = 1;
            cout<<"-1"<<endl;
            return ;
        }

    }
    // if(flag){
    //     // cout<<"32323"<<endl;
    //     cout<<"-1"<<"\n";
    //     return ;
    // }
    vector<int> ren;
    bool tk;
    for (int i = 0; i < n; i++)
    {
        if(vec[i] == i && size1[i] == 1){
            ren.push_back(i);
        }
        // if(ren.size() == 3){
        //     tk = Union(ren[0],ren[1],vec,size1);
        //     tk = Union(ren[2],ren[1],vec,size1);
        //     ren.clear();
        // }
    }
    
    map<int,vector<int>>mp;
    int t;
    int ind =0;
    int nr = ren.size();
    for (int i = 0; i < n; i++)
    {   
        if(vec[i] == i && size1[i] == 1) continue;
        t = find(i,vec);
        if(mp.find(t) ==mp.end()){
            
            mp[t] = {i};
        }
        else{
            mp[t].push_back(i);
        }
    }
    if(mp.size()>n/3){
        cout<<"-1"<<endl;
        return ;
    }
    ind =0;
    for(auto x: mp){
        if(x.second.size() == 2){
            // x.second.push_back(ren[ind]);
            cout<<ren[ind]+1<<" ";
            ind++;
        }
        for(auto y:x.second){
            cout<<y+1<<" ";
        }
        cout<<endl;
    }
    
    for (int i = ind; i < nr; i+=3)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<ren[i+j]+1<<" ";
        }
        cout<<endl;        
    }
    

    cout<<endl;
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    solve();
    return 0;
    
}