#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9+7)
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    
    vector<pair<int,pair<int,int>>> vec;
    int a,b;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a>>b;
        vec.push_back({a,{b,i}});
    }
    
    sort(vec.begin(),vec.end());
    // cout<<"vec is "<<endl;
    // for(auto x:vec){
        
    //     cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
    // }
    // cout<<endl;
    int low = 0,high = n-1;
    int sum1 =0,sum2=0;
    int t;
    string s;
    vector<int> ans(n,0);
    while(high>low){
        // cout<<"high and low are "<<high<<" "<<low<<endl;
        // if(sum1<=sum2 || sum1+vec[low].first-sum2 <=500){
        if(sum1+vec[low].first-sum2 <=500){

            sum1+=vec[low].first;
            ans[vec[low].second.second] = 1;
            low++;


        }
        else{
            sum2+=vec[high].second.first;
            ans[vec[high].second.second] =2;
            high--;

        }

    }
    if(ans[vec[high].second.second] == 0){

        // if(sum1<=sum2 || abs(sum1+vec[high].first-sum2) <=500){
        if((sum1+vec[high].first-sum2) <=500){
            sum1+=vec[high].first;
            ans[vec[high].second.second] = 1;
        }
        else{
            sum2+=vec[high].second.first;
            ans[vec[high].second.second] = 2;

        }
    }
    // cout<<"ans is "<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<ans[i]<<" ";
    // }cout<<endl;
    
    if(abs(sum1-sum2)>500){
        cout<<"-1"<<endl;
        return 0;
    }
 

    for (int i = 0; i < n; i++)
    {
        if(ans[i] == 1){
            s+='A';
        }
        else{
            s+='G';
        }
    }
    // cout<<"ans is ";
    cout<<s;
    

    cout<<endl;
    return 0;
}