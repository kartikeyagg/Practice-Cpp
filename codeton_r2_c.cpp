#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){

    int n,m;
    cin>>n>>m;
    vector<int> vec(m);
    for (int j = 0; j < m; j++)
    {
        cin>>vec[j];
        vec[j]--;
    }
    sort(vec.begin(),vec.end());
    // cout<<"vec is "<<endl;
    // for(auto x:vec){
    //     cout<<x<<" ";
    // }cout<<endl;
    vector<int> len(m,0);

    for (int j = 0; j < m-1; j++)
    {
        
        len[j] = vec[j+1]-vec[j]-1;
        
    }
    len[m-1] = (n-vec[m-1])+vec[0]-1;
    sort(len.begin(),len.end());

    // cout<<"len is "<<endl;
    // for(auto x: len){
    //     cout<<x<<" ";
    // }cout<<endl;
    
    ll ans =0;
    ll temp;
    int i = m-1;
    int k=0;
    while(i>=0){

        // temp = len[i] - pow(2,k);
        temp = len[i] - 2*k-1;

        if(temp>0){
            // cout<<"adding "<<temp<<endl;
            ans+=temp;
        }
        // else if(i==m-1&&temp==0) ans+=1;
        else if(temp==0) ans+=1;
        else break;

        i--;
        // k+=1;
        k+=2;

    }

    // cout<<"\n# ";
    cout<<n-ans<<endl;
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