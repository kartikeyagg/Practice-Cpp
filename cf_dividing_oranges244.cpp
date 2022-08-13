#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    int n,k;
    cin>>n>>k;
    set<int> st;
    vector<int> emp;
    vector<vector<int>> vec(k+1,emp);
    
    int a;
    for (int i = 1; i <=k; i++)
    {
        cin>>a;
        vec[i].push_back(a);  
        st.insert(a);

    }
    // cout<<"st is "<<endl;
    // for(auto x: st){
    //     cout<<x<<" ";
    // }cout<<endl;
    // cout<<"vec is "<<endl;
    // for(auto x: vec){
    //     for(auto y:x){
    //         cout<<y<<" ";
    //     }cout<<endl;
    // }
    // cout<<"fasdf"<<endl;
    int j =1;
    int h =1;
    int nv = 0;
    while(j<= (n*k) && h<=k){

        // cout<<"rqer"<<endl;
        // cout<<"for h and j = "<<h<<" "<<j<<endl;
        nv = vec[h].size();
        while(nv<n){
            // cout<<"2\n";
            if(st.find(j) == st.end()){
                // cout<<"found it"<<endl;
                vec[h].push_back(j);
                nv++;
            }
            j++;

        }
        h++;

    }
    // cout<<"result is \n";

    for(auto x: vec){
        for(auto y:x){
            cout<<y<<" ";
        }cout<<endl;
    }
    

    cout<<endl;
    return 0;
}