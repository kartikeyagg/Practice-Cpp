#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(pair<int,int> &a, pair<int,int> &b){

    return a.first<b.first;
}
int main()
{
    vector<int> vec(3);
    vector<pair<int,int>> arr;
    // vector<int> mat;
    for (int i = 0; i < 3; i++)
    {
        cin>>vec[i];
        arr.push_back({vec[i],i});
    }
    // arr = vec;
    // mat = vec;
    sort(vec.begin(),vec.end());
    // cout<<"vec is "<<endl;
    // for(auto x: vec){
    //     cout<<x<<" ";
    // }cout<<endl;
    // cout<<"#####"<<endl;
    if(vec[2]>vec[1]+vec[0] || vec[1]<vec[2]-vec[0]|| vec[0]<vec[2]-vec[1]){
        cout<<"Impossible"<<endl;
        return 0;
    }
    vector<int> ans(5,0);
    // 1,3 ; 1,2; 3,2;

    
    sort(arr.begin(),arr.end(),cmp);
    int t = arr[2].first;
    int m = arr[0].first;

    m = min(m,t/2);

    arr[0].first-=m;

    ans[arr[2].second+arr[0].second] = m;

    ans[arr[2].second+arr[1].second] = t-m;

    m = arr[1].first-(t-m);

    while(m>arr[0].first){

        ans[arr[2].second+arr[0].second]--;
        ans[arr[2].second+arr[1].second]++;
        arr[0].first++;
        m--;

    }
    
    ans[arr[1].second+arr[0].second] = m;

    // cout<<"the ans is ";
    // for(auto x: ans){
    //     cout<<x<<" ";
    // }cout<<endl;
    if((ans[1]+ans[2]+ans[3])*2!=vec[0]+vec[1]+vec[2]){
        cout<<"Impossible";
        return 0;
    }
    cout<<ans[1]<<" "<<ans[3]<<" "<<ans[2];
    cout<<endl;
    return 0;
}